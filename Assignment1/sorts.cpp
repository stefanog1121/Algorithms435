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
        if (low = i) {
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

void mergeSort(std::vector<int>& A, int left, int right) {} 
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

    // create & populate temp arrays 
    vector<int> L(n1);
    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i]
    };

    vector<int> R(n2);
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j]
    };

    int i, j = 0;
    int k = left;

    for ()

    
}

void quickSort() 
{

}