#include <iostream>
#include <vector>

std::string makeLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return std::tolower(c); });
    return s;
};

int partition(std::vector<std::string>& A, int low, int high) 
{
    // Using high as pivot, sort array between elements below than the pivot and those above
    std::string pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (makeLower(A[j]) <= makeLower(pivot)) {
            i++;
            std::swap(A[i], A[j]);
        }
    }

    // Return pivot to middle position between each half
    std::swap(A[i+1], A[high]);
    return (i+1);
};

void quickSort(std::vector<std::string>& A, int low, int high) 
{
    if (low < high) {
        //  Partition array around a chosen pivot into low and high subarray halves,
        //  returning the partition to the middle of each
        int part = partition(A, low, high);

        // Recursively sort each smaller subarray of either half by further partitioning
        // and calls to quickSort
        quickSort(A, low, part-1);
        quickSort(A, part+1, high);
    }
};
