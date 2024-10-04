#include <iostream>
#include <vector>

std::string makeLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return std::tolower(c); });
    return s;
};

void shuffle(std::vector<std::string>& A) 
{
    int n = A.size();
    std::srand(time(NULL));

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i+1);
        std::swap(A[i], A[j]);
    }
    std::cout << "Shuffled Array" << std::endl;
};

void selectionSort(std:: vector<std::string>& A) 
{
    int comparisons = 0;
    int n = A.size();

    for (int i = 0; i < n - 1; ++i) {
        // index of lowest value element
        int low = i;

        for (int j = i + 1; j < n; ++j) {
            comparisons++;
            // loop through unsorted part of array, updating new low index is one is found
            if (makeLower(A[j]) < makeLower(A[low])) {
                low = j;
            }
        }

        // perform swap if necesary
        if (low != i) {
            std::swap(A[i], A[low]);
        }
    }
    std::cout << "Selection Sort Comparisons: " << comparisons << "\n" << std::endl;
};

void insertionSort(std::vector<std::string>& A) 
{
    int comparisons = 0;
    int n = A.size();
    // Starting at the second element, traverse array
    for (int i = 1; i < n; ++i) {
        std::string key = A[i];
        int j = i - 1;

        /* Starting with 1 - the current index, compare key to previous element and swap if required,
         working backwards until all previous elements have been compared  */
        while (j >= 0) {
            comparisons++;
            if (makeLower(A[j]) < makeLower(key)) break;
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
    
    std::cout << "Insertion Sort Comparisons: " << comparisons << "\n" <<std::endl;
};

// Merge the low-mid and mid-high subarrays of A 
void merge(std::vector<std::string>& A, int left, int right, int mid, int& comparisons) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create & populate temp arrays 
    std::vector<std::string> L(n1);
    for (int i = 0; i < n1; i++){
        L[i] = A[left + i];
    };

    std::vector<std::string> R(n2);
    for (int j = 0; j < n2; j++) {
        R[j] = A[mid + 1 + j];
    };


    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        comparisons++;

        // Merge each half back together by comparing elements from each subarry and placing the smaller of the two 
        if (makeLower(L[i]) <= makeLower(R[j])) {
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
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
};

void mergeSort(std::vector<std::string>& A, int left, int right, int& comparisons) 
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively divide an array into sorted sub arrays of size 1, and then merge back the sorted subarrys
        mergeSort(A, left, mid, comparisons);
        mergeSort(A, mid + 1, right, comparisons);
        merge(A, left, right, mid, comparisons);
    }
};

void countMergeSort(std::vector<std::string>& A) {
    int comparisons = 0;
    int j = 50;
    mergeSort(A, 0, A.size() - 1, comparisons);
    std::cout << "Merge Sort Comparisons : " << comparisons << "\n" << std::endl;
};

int partition(std::vector<std::string>& A, int low, int high, int& comparisons) 
{
    // Using high as pivot, sort array between elements below than the pivot and those above
    std::string pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (makeLower(A[j]) <= makeLower(pivot)) {
            i++;
            std::swap(A[i], A[j]);
        }
    }

    // Return pivot to middle position between each half
    std::swap(A[i+1], A[high]);
    return (i+1);
};

void quickSort(std::vector<std::string>& A, int low, int high, int& comparisons) 
{
    if (low < high) {
        //  Partition array around a chosen pivot into low and high subarray halves,
        //  returning the partition to the middle of each
        int part = partition(A, low, high, comparisons);

        // Recursively sort each smaller subarray of either half by further partitioning
        // and calls to quickSort
        quickSort(A, low, part-1, comparisons);
        quickSort(A, part+1, high, comparisons);
    }
}

void countQuickSort(std::vector<std::string>& A) {
    int comparisons = 0;
    quickSort(A, 0, A.size() - 1, comparisons);
    std::cout << "Quick Sort Comparisons : " << comparisons << "\n" << std::endl;
};


