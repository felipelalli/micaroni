package br.eti.fml.campinas.local;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public enum Flag {
    DELETED(0),
    POINTER(1),
    N_BYTES(2);

    byte value;

    Flag(int index) {
        this.value = (byte) Math.pow(2, index);
    }

    public byte getValue() {
        return value;
    }

    public boolean isInside(byte flags) {
        return ((flags & this.getValue()) == this.getValue());
    }
}
