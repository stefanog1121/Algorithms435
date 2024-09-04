import java.util.Arrays;

public class DSA {
    public static void main(String[] args) {
        int[] a = {3, 7, 8, 6, 4, 10, 28, 2, 18, 9};

        insertionSort(a);
        
        System.err.println(Arrays.toString(a));
    }

    public static void insertionSort(int[] a) {
        for (int j = 2; j < a.length; j++) {
            int key = a[j];
            int i = j - 1;
            while (i >= 0 && a[i] > key) {
                a[i+1] = a[i];
                i = i - 1;
            }
            a[i+1] = key;
        }
    }

    

}