package br.eti.fml.campinas.local.body;

import br.eti.fml.campinas.local.index.HashNode;
import br.eti.fml.campinas.util.ByteUtil;
import br.eti.fml.campinas.util.FileUtil;
import br.eti.fml.campinas.util.Pair;
import org.apache.log4j.Logger;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.FileLock;
import java.util.concurrent.BlockingQueue;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Body {
    private static final Logger log = Logger.getLogger(Body.class);

    public final static long[] CONVERSION = new long[] {12L, 24L, 56L, 96L};
    public final static byte MAX_INDEX = (byte) (getIndexBySize(ByteUtil.GB) + 1);
    private static final int START = 4;

    private RandomAccessFile[] file = new RandomAccessFile[MAX_INDEX];
    private FileChannel[] channel = new FileChannel[MAX_INDEX];
    private FileLock[] lock = new FileLock[MAX_INDEX];
    private long[] currentFileSize = new long[MAX_INDEX];

    private ByteBuffer[] buffers = new ByteBuffer[MAX_INDEX];

    public static double log2(double num) {
        return (Math.log(num) / Math.log(2d));
    }

    public static long getSizeByIndex(byte index) {
        assert index >= 0;

        if (index < START) {
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
        for (int i = 0; i < MAX_INDEX; i++) {
            File f = new File(directoryPath.getAbsolutePath()
                    + getFileNameByIndex(i));

            this.buffers[i] = null;
            this.file[i] = new RandomAccessFile(f, "rw");            
            this.channel[i] = this.file[i].getChannel();
            this.lock[i] = this.channel[i].tryLock();

            if (this.lock[i] == null) {
                throw new IOException(this.channel[i] + " in '"
                        + directoryPath.getAbsolutePath()
                        + "' is locked! Unlock it first.");
            }

            this.currentFileSize[i] = this.file[i].length();
            long size = getSizeByIndex((byte) i) + BodyNode.CHECKSUM_SIZE
                    + BodyNode.FLAGS_SIZE + BodyNode.SIZE_SIZE;

            long rightSize = ByteUtil.getNextMultiple(
                    this.currentFileSize[i], size);

            if (rightSize != this.currentFileSize[i]) {
                FileUtil.checkFileSize("body index " + i, rightSize,
                        this.file[i], size);

                this.currentFileSize[i] = rightSize;
            }
        }
    }

    private String getFileNameByIndex(int i) {
        return File.separator + "b" + Integer.toHexString(i);
    }

    public Pair<Byte, Long> allocateAndPut(byte[] value) throws IOException {
        byte address1 = getIndexBySize(value.length);
        long realSize = getSizeByIndex(address1);

        long address2 = this.currentFileSize[address1];

        assert realSize < Integer.MAX_VALUE;
        BodyNode bodyNode = new BodyNode((int) realSize);
        ByteBuffer buffer = bodyNode.getNewByteBuffer(value,
                (byte) 0); // TODO: change flags

        this.channel[address1].write(buffer, address2);
        this.currentFileSize[address1] += realSize;
        
        buffer.clear();

        return new Pair<Byte, Long>(address1, address2);
    }

    public void shutdown() throws IOException {
        for (int i = 0; i < MAX_INDEX; i++) {
            this.lock[i].release();
            this.file[i].close();
            //log.trace("Closed " + getFileNameByIndex(i) + " file.");
        }
    }

    public byte[] read(HashNode node) throws IOException {
        byte[] result = null;

        byte address1 = node.getAddress1();
        long address2 = node.getAddress2();

        long realSize = getSizeByIndex(address1);
        assert realSize < Integer.MAX_VALUE;

        if (this.buffers[address1] == null) {
            this.buffers[address1] = ByteBuffer.allocateDirect((int) realSize);
        }

        // TODO: read size, checksum

        return result;
    }
}
