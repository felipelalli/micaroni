package br.eti.fml.crazydb;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class MetaInfo {
    public static final int META_INFO_FIXED_SIZE_IN_BYTES = 5242880;

    private String name;
    private int indexSizeInMegabytes;
    private long creationTimestamp;
    private boolean shutdown;
}
