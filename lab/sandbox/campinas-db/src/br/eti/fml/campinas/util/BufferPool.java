package br.eti.fml.campinas.util;

import org.apache.log4j.Logger;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class BufferPool {
    private static final Logger log = Logger.getLogger(BufferPool.class);
    public static final BufferPool INSTANCE = new BufferPool();

    private final Map<Integer, Set<Long>> freeNameBuffers
            = new HashMap<Integer, Set<Long>>();

    private final Map<Long, NamedByteBuffer> freeBuffers
            = new HashMap<Long, NamedByteBuffer>();

    private BufferPool() {
    }

    public void doWithATemporaryBuffer(int size, Action action) throws IOException {
        NamedByteBuffer namedByteBuffer
                = BufferPool.INSTANCE.getAByteBuffer(size);
        
        try {
            action.doWith(namedByteBuffer.getByteBufferAndResetPosition());
        } finally {
            BufferPool.INSTANCE.free(namedByteBuffer);
        }
    }

    public interface Action {
        void doWith(ByteBuffer buffer) throws IOException;
    }

    public NamedByteBuffer getAByteBuffer(int size) {
        if (!freeNameBuffers.containsKey(size)) {
            freeNameBuffers.put(size, new HashSet<Long>());
        }

        Set<Long> buffersName = freeNameBuffers.get(size);

        if (buffersName.size() == 0) {
            log.trace("Creating buffer to size " + size + "...");

            for (int i = 0; i < 32; i++) {
                NamedByteBuffer newBuffer = new NamedByteBuffer(size);
                freeBuffers.put(newBuffer.getName(), newBuffer);
                buffersName.add(newBuffer.getName());
            }
        }

        Long first = buffersName.iterator().next();
        buffersName.remove(first);
        return freeBuffers.get(first);
    }

    public void free(NamedByteBuffer buffer) {
        Set<Long> buffersName = freeNameBuffers.get(buffer.getSize());
        buffersName.add(buffer.getName());
    }
}
