#include <iostream>
using namespace std;
#include <vector>

int main() {
    int a[] = {3, 7, 8, 6, 4, 10, 28, 2, 18, 9};
    int n = sizeof(a) / sizeof(a[0]);
    DSA dsa;

    dsa.insertionSort(a, n);
    dsa.printArray(a, n);

    return 0;
}

class DSA {
public:
    void insertionSort(int arr[], int n) 
    {
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    void merge(vector<int>& A, int left, int mid, int right) 
    {
        int n1 = mid - left +1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);
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

    void mergeSort(vector<int> A, int left, int right)
    {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(A, left, mid);
            mergeSort(A, mid + 1, right);

            merge(A, left, mid, right);
        }
    }

    void printArray(int a[], int n) {
        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << endl;
    }

};
