
void selectionSort() 
{

}

void insetionSort(int a[], int n) 
{
    // Starting at the second element, traverse array
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;

        /* Starting with 1 - the current index, compare key to previous element and swap if required,
         working backwards until all previous elements have been compared  */
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

}

void mergeSort() 
{

}

void quickSort() 
{

}