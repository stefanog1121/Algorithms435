#include <iostream>
#include <vector>

void selectionSort(std:: vector<int>& A) 
{
    int n = A.size();

    for (int i = 0; i < n - 1; ++i) {
        // index of lowest value element
        int low = i;

        for (int j = i + 1; j < n; ++j) {
            // loop through unsorted part of array, updating new low index is one is found
            if (A[j] < A[low]) {
                low = j;
            }
        }

        // perform swap if necesary
        if (low != i) {
            std::swap(A[i], A[low]);
        }
    }
}

void insertionSort(std::vector<int>& A) 
{
    int n = A.size();
    // Starting at the second element, traverse array
    for (int i = 1; i < n; ++i) {
        int key = A[i];
        int j = i - 1;

        /* Starting with 1 - the current index, compare key to previous element and swap if required,
         working backwards until all previous elements have been compared  */
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

void mergeSort(std::vector<int>& A, int left, int right) 
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively divide an array into sorted sub arrays of size 1, and then merge back the sorted subarrys
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

// Merge the low-mid and mid-high subarrays of A 
void merge(std::vector<int>& A, int left, int right, int mid) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create & populate temp arrays 
    std::vector<int> L(n1);
    for (int i = 0; i < n1; i++){
        L[i] = A[left + i]
    };

    std::vector<int> R(n2);
    for (int j = 0; j < n2; j++) {
        R[j] = A[mid + 1 + j]
    };

    int i, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        // Merge each half back together by comparing elements from each subarry and placing the smaller of the two 


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
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void quickSort(std::vector<int>& A, int low, int high) 
{
    if (low < high) {
        //  Partition array around a chosen pivot into low and high subarray halves,
        //  returning the partition to the middle of each
        part = partition(A, low, high)

        // Recursively sort each smaller subarray of either half by further partitioning
        // and calls to quickSort
        quickSort(A, low, part-1);
        quickSort(A, part+1, high);

    }
}
int partition(std::vector<int>& A, int low, int high) 
{
    // Using high as pivot, sort array between elements below than the pivot and those above
    int pivot = A[high];
    int i = low - 1;
    for (j = low, j < high, j++) {
        if (A[j] <= pivot) {
            i++;
            std::swap(A[i], A[j])
        }
    }

    // Return pivot to middle position between each half
    std::swap(A[i+1], A[high])
    return (i+1);
}