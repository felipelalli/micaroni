package br.eti.fml.campinas;

import br.eti.fml.campinas.util.ByteUtil;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.UUID;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
@SuppressWarnings("unused")
public class CampinasDB {
    private static final long WARN_MAX_BYTES_WITHOUT_STREAM = 512 * ByteUtil.KB;

    public CampinasDB(String exclusiveName, String pathDirectory,
                      int indexSizeInMegabytes) throws IOException {

        
    }

    public void put(String key, byte[] value) throws IOException {
        this.put(UUID.nameUUIDFromBytes(
                ByteUtil.stringToBytesUTFNIO(key)), value);
    }

    public void putStreamInThread(
            String key, InputStream value, ActionStreamCallback callback) {
        // TODO
    }

    public byte[] get(String key) throws IOException {
        return this.get(UUID.nameUUIDFromBytes(
                ByteUtil.stringToBytesUTFNIO(key)));
    }

    public void getStreamInThread(
            String key, OutputStream returnedValue,
            ActionStreamCallback callback) {

        // TODO
    }

    protected void put(UUID key, byte[] value) throws IOException {
        if (value.length > WARN_MAX_BYTES_WITHOUT_STREAM) {

        }

//        long address = this.index.allocateAndPut(value);
//        int checksumData = Arrays.hashCode(value);
//        this.index.updateIndex(key, address, checksumData, value.length);
        // TODO
    }

    protected byte[] get(UUID key)
            throws IOException {

//        HashNode node = this.index.find(key);
//
//        if (node == null) {
//            return null;
//        } else {
//            byte[] data = this.body.read(node.getAddress(), node.getSize());
//            int realChecksumData = Arrays.hashCode(data);
//
//            if (realChecksumData != node.getChecksumData()) {
//                throw new CorruptedDataException(
//                        data, node.getChecksumData(), realChecksumData);
//            }
//
//            return data;
//        }
        return null; // TODO
    }
}
