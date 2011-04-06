package br.eti.fml.crazydb;

import java.util.Arrays;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class CorruptedDataException extends Exception {
    private byte[] corruptedData;
    private int checksum;
    private int realChecksum;

    public CorruptedDataException(byte[] corruptedData, int checksum, int realChecksum) {
        this.corruptedData = corruptedData;
        this.checksum = checksum;
        this.realChecksum = realChecksum;
    }

    public CorruptedDataException(String message, byte[] corruptedData, int checksum, int realChecksum) {
        super(message);
        this.corruptedData = corruptedData;
        this.checksum = checksum;
        this.realChecksum = realChecksum;
    }

    public CorruptedDataException(String message, Throwable cause, byte[] corruptedData, int checksum, int realChecksum) {
        super(message, cause);
        this.corruptedData = corruptedData;
        this.checksum = checksum;
        this.realChecksum = realChecksum;
    }

    public CorruptedDataException(Throwable cause, byte[] corruptedData, int checksum, int realChecksum) {
        super(cause);
        this.corruptedData = corruptedData;
        this.checksum = checksum;
        this.realChecksum = realChecksum;
    }

    public byte[] getCorruptedData() {
        return corruptedData;
    }

    public int getChecksum() {
        return checksum;
    }

    public int getRealChecksum() {
        return realChecksum;
    }

    @Override
    public String toString() {
        return "CorruptedDataException{" +
                "corruptedData=" + Arrays.toString(corruptedData) +
                ", checksum=" + checksum +
                ", realChecksum=" + realChecksum +
                "} " + super.toString();
    }
}
