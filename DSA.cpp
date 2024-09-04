#include <iostream>
using namespace std;
#include <vector>

class DSA {
public:
    void insertionSort(int arr[], int n) {
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




    void printArray(int a[], int n) {
        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << endl;
    }

};

int main() {
    int a[] = {3, 7, 8, 6, 4, 10, 28, 2, 18, 9};
    int n = sizeof(a) / sizeof(a[0]);
    DSA dsa;

    dsa.insertionSort(a, n);
    dsa.printArray(a, n);

    return 0;
}