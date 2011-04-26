package br.eti.fml.campinas.util;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentLinkedQueue;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class BufferPool {
    private static final BufferPool bufferPool = new BufferPool();

    private final ConcurrentHashMap<Integer, ConcurrentLinkedQueue<Long>>
            freeNameBuffers = new ConcurrentHashMap<
                Integer, ConcurrentLinkedQueue<Long>>();

    private final ConcurrentHashMap<Long, NamedByteBuffer> freeBuffers
            = new ConcurrentHashMap<Long, NamedByteBuffer>();

    public static BufferPool getInstance() {
        return bufferPool;
    }

    private BufferPool() {
    }

    public void doWithATemporaryBuffer(int size, Action action) throws IOException {
        NamedByteBuffer namedByteBuffer
                = BufferPool.getInstance().getAByteBuffer(size);

        action.doWithTemporaryBuffer(
                namedByteBuffer.getByteBufferAndResetPosition());

        BufferPool.getInstance().free(namedByteBuffer);
    }

    public interface Action {
        void doWithTemporaryBuffer(ByteBuffer buffer) throws IOException;
    }

    public NamedByteBuffer getAByteBuffer(int size) {
        if (!freeNameBuffers.containsKey(size)) {
            freeNameBuffers.put(size, new ConcurrentLinkedQueue<Long>());
        }

        ConcurrentLinkedQueue<Long> buffersName = freeNameBuffers.get(size);

        if (buffersName.size() == 0) {
            for (int i = 0; i < 32; i++) {
                NamedByteBuffer newBuffer = new NamedByteBuffer(size);
                freeBuffers.put(newBuffer.getName(), newBuffer);
                buffersName.offer(newBuffer.getName());
            }
        }

        return freeBuffers.get(buffersName.poll());
    }

    public void free(NamedByteBuffer buffer) {
        ConcurrentLinkedQueue<Long> buffersName
                = freeNameBuffers.get(buffer.getSize());

        buffersName.offer(buffer.getName());
    }
}
