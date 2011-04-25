package br.eti.fml.campinas;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public enum Flags {
    DELETED(1),
    POINTER(2),
    ONE_BYTE(3),
    TWO_BYTES(4),
    THREE_BYTES(5),
    FOUR_BYTES(6);

    byte value;

    Flags(int index) {
        this.value = (byte) Math.pow(index, 2);
    }

    public byte getValue() {
        return value;
    }
}
