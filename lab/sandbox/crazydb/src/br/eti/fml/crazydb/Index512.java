package br.eti.fml.crazydb;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.UUID;

/**
 *
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Index512 {
    public static long INDEX_SIZE_IN_BYTES = 512 * 1024 * 1024;

    private TheBigFile db;
    private Body body;

    public Index512(TheBigFile db, Body body) throws IOException {
        this.db = db;
        this.body = body;

        if (this.db.preallocate(INDEX_SIZE_IN_BYTES)) {
            this.db.fillWithZero(0L, INDEX_SIZE_IN_BYTES, 1024 * 512);
        }
    }
    
    protected static byte[] getHashNode(byte[] key, long size,
                                        long address, long nextAddress) {
        
        long timestamp = System.currentTimeMillis();

        return ByteBuffer.allocate(48).put(key).putLong(size)
                .putLong(address).putLong(nextAddress).putLong(timestamp).array();
    }

    public void updateIndex(UUID key, byte[] bytesKey, long address, long size) throws IOException {
        long indexPosition = Math.abs(key.getMostSignificantBits()
                ^ key.getLeastSignificantBits()) % (INDEX_SIZE_IN_BYTES / 8) * 8;

        if (this.db.checkIfPositionIsEqualTo(indexPosition, 0L)) { // it's free
            byte[] hashNode = getHashNode(bytesKey, size, address, 0L);
            long nodeAddress = body.allocate(hashNode);
            this.db.putLongAt(indexPosition, nodeAddress);
        } else { // need to find a free position
            // TODO
        }
    }
}
