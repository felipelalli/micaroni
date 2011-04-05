package br.eti.fml.crazydb.index;

import br.eti.fml.crazydb.ByteUtil;
import br.eti.fml.crazydb.CorruptedData;
import org.apache.log4j.Logger;

import java.nio.ByteBuffer;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class IndexNode {
    private static final Logger log = Logger.getLogger(IndexNode.class);

    //64 bits - addr - 8 bytes
    //16 bits - checksum - 2 bytes

    public static final int CHECKSUM_SIZE = 2;
    public static final int ADDRESS_SIZE = 8 + CHECKSUM_SIZE;

    private long hashNodeAddress;
    private byte[] hashNodeChecksumAddress;

    public IndexNode(byte[] indexNode) {
        ByteBuffer indexNodeBuffer = ByteBuffer.wrap(indexNode);
        hashNodeAddress = indexNodeBuffer.getLong();
        hashNodeChecksumAddress = new byte[2];
        indexNodeBuffer.get(hashNodeChecksumAddress);
    }

    public long getHashNodeAddress() {
        return hashNodeAddress;
    }

    public boolean checkIfDataIsOK() {
        try {
            return this.checkForCorruptedData(false);
        } catch (CorruptedData e) {
            // ignores
            return false;
        }
    }
    
    public boolean checkForCorruptedData(boolean throwException) throws CorruptedData {
        byte[] realChecksum = ByteUtil.getChecksum(hashNodeAddress);

        if (ByteUtil.compare(realChecksum, this.hashNodeChecksumAddress)) {
            return true;
        } else {
            // TODO: CORRUPTED DATA, WHAT TO DO NOW TO RECOVER?

            log.error("I'm so sorry! The hashNode address is corrupted here, so"
                    + " it's possible you lost some valid keys. I'll just"
                    + " replace this corrupted node with the new one. address="
                    + hashNodeAddress + " : checksumAddress=("
                    + hashNodeChecksumAddress[0] + "," + hashNodeChecksumAddress[1]
                    + " and should be (" + realChecksum[0] + "," + realChecksum[1] + ")");

            log.error("HASH NODE ADDRESS IS CORRUPTED!");
            
            if (throwException) {
                throw new CorruptedData("Corrupted data. " + hashNodeAddress
                        + " seems to be invalid!");
            }

            return false;
        }
    }
}
