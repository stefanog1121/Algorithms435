import java.util.Arrays;

public class DSA {
    public static void main(String[] args) 
    {
        int[] a = {3, 7, 8, 6, 4, 10, 28, 2, 18, 9};

        //insertionSort(a);
        mergeSort(a, 0, a.length - 1);
        
        System.err.println(Arrays.toString(a));
    }

    /* - INSERTION SORT - 
        Compares each index with the following ones, picks the smallest element in the remainder,
        and swaps once it has been found */ 
    public static void insertionSort(int[] a) 
    {
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

    /* - MERGE SORT - 
        Merge helper method for Merge Sort - Merges two subarrys of A[] */
    public static void merge(int[] A, int left, int mid, int right) 
    {
        // Find subarry sizes
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create & populate temp arrays
        int[] L = new int[n1];
        int[] R = new int[n2];
        for (int i = 0; i < n1; i++) {
            L[i] = A[left + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = A[mid + j + 1];
        }

        /* Initial indicies of subarrys + merged subarray array */
        int i = 0, j = 0;
        int k = left;

        /* Merging the two sub arrays */
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                A[k] = L[i];
                i++;
            }
            else {
                A[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy any remaining elements in*/
        while (i < n1) {
            A[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            A[k] = R[j];
            j++;
            k++;
        }
    }
    
    /*  Merge Sort function */
    public static void mergeSort(int[] A, int left, int right) 
    {
        if (left < right) {
            // Find mid point
            int mid = left + (right - left) / 2;

            // Sort each half
            mergeSort(A, left, mid);
            mergeSort(A, mid + 1, right);

            // Merge sorted halves
            merge(A, left, mid, right);
        }
    }

}