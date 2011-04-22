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
    public CampinasDB(String exclusiveName, String pathDirectory,
                      int indexSizeInMegabytes) throws IOException {

        
    }

    public void put(String key, byte[] value) throws IOException {
        UUID k = UUID.nameUUIDFromBytes(
                ByteUtil.stringToBytesUTFNIO(key));

//        long address = this.index.allocateAndPut(value);
//        int checksumData = Arrays.hashCode(value);
//        this.index.updateIndex(key, address, checksumData, value.length);
        // TODO
    }

    public byte[] get(String key) throws IOException {
        UUID k = UUID.nameUUIDFromBytes(
                ByteUtil.stringToBytesUTFNIO(key));

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
