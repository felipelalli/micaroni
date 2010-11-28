
package br.eti.fml.ridiculousdb;

import java.io.Serializable;
import java.util.Comparator;

/**
 *
 * @author felipelalli
 */
public interface CustomComparator extends Serializable, Comparator<byte[]> {
    String name();
}
