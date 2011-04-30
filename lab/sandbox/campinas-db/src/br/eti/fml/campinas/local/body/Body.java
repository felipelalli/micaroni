package br.eti.fml.campinas.local.body;

import br.eti.fml.campinas.util.ByteUtil;
import br.eti.fml.campinas.util.FileUtil;
import br.eti.fml.campinas.util.Pair;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.FileLock;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Body {
    public final static long[] CONVERSION = new long[] {12L, 24L, 56L, 96L};
    public final static byte MAX_INDEX = (byte) (getIndexBySize(ByteUtil.GB) + 1);

    private RandomAccessFile[] file = new RandomAccessFile[MAX_INDEX];
    private FileChannel[] channel = new FileChannel[MAX_INDEX];
    private FileLock[] lock = new FileLock[MAX_INDEX];
    private long[] currentFileSize = new long[MAX_INDEX];

    public static double log2(double num) {
        return (Math.log(num) / Math.log(2d));
    }

    public static long getSizeByIndex(byte index) {
        assert index >= 0;

        if (index < 4) {
            return CONVERSION[index];
        } else {
            return (long) Math.pow(2d, (double) index);
        }
    }

    public static byte getIndexBySize(long size) {
        for (int i = 0; i < CONVERSION.length; i++) {
            long b = CONVERSION[i];

            if (size == b) {
                return (byte) i;
            }
        }

        byte number = (byte) Math.ceil(log2(size));
        return number < CONVERSION.length ? (byte) CONVERSION.length : number;
    }

    public Body(File directoryPath) throws IOException {
        for (int i = 4; i < MAX_INDEX; i++) {
            File f = new File(directoryPath.getAbsolutePath()
                    + File.separator + "b" + Integer.toHexString(i));

            this.file[i] = new RandomAccessFile(f, "rw");            
            this.channel[i] = this.file[i].getChannel();
            this.lock[i] = this.channel[i].tryLock();

            if (this.lock[i] == null) {
                throw new IOException(this.channel[i] + " in '"
                        + directoryPath.getAbsolutePath()
                        + "' is locked! Unlock it first.");
            }

            this.currentFileSize[i] = this.file[i].length();
            long size = getSizeByIndex((byte) i);

            long rightSize = ByteUtil.getNextMultiple(
                    this.currentFileSize[i], size);

            if (rightSize != this.currentFileSize[i]) {
                FileUtil.checkFileSize("body index " + i, rightSize,
                        this.file[i], size);

                this.currentFileSize[i] = rightSize;
            }
        }
    }

    public Pair<Byte, Long> allocateAndPut(byte[] value) throws IOException {
        byte address1 = getIndexBySize(value.length);
        long realSize = getSizeByIndex(address1);

        long address2 = this.currentFileSize[address1];
        this.channel[address1].write(ByteBuffer.wrap(value), address2);
        this.currentFileSize[address1] += realSize;

        return new Pair<Byte, Long>(address1, address2);
    }

    //public byte[] read(long address)
}
