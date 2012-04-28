package br.eti.fml.android.sigame.io.http;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class PairParam {
    public String name;
    public String value;

    /**
     *
     * @param name  the name of the parameter
     * @param value the value of parameter
     */
    public PairParam(String name, String value) {
        this.name = name;
        this.value = value;
    }

    public String toString() {
        return "(" + name + "=" + value + ")";
    }
}
