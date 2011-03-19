import uk.co.scottlogic.SortedList;

import java.util.TreeSet;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Main {
    public static void main(String[] args) {

        SortedList<Long> sortedList = new SortedList<Long>();

        long min = Long.MAX_VALUE;
        long max = 0;

        int totalSize = 0;
        for (int i = 0; i < 1000; i++) {
            Size size = new Size();
            sortedList.add(size.getSize());
            System.out.println("Size: " + size);

            totalSize += size.getSize();

            if (size.getSize() > max) {
                max = size.getSize();
            }

            if (size.getSize() < min) {
                min = size.getSize();
            }
        }

        System.out.println("Avg.: " + (totalSize / 1000.0));
        System.out.println("Max: " + max);
        System.out.println("Min: " + min);

        for (Long i : sortedList) {
            System.out.println("" + i);    
        }
    }
}
