#include <iostream>
#include <vector>

int linearSearch(std::vector<std::string>& a, std::string key) 
{
    bool found = false;
    int comparisons = 0;
    for (int i = 0; i < a.size(); i++) {
        comparisons = comparisons + 1;
        if (a[i] == key) {
            std::cout << "Key found at index " << i << " | Comparisons: " << comparisons << '\n';
            found = true;
            break;
        }
    }
    return comparisons;
};

int binarySearch(std::vector<std::string>& a, int low, int high, std::string key, int comparisons)
{
    if (low > high) {
        return comparisons;
    }
    else { 
    // find midpoint of array, compare to key, and move into left/right problem space recursively based on equality
        int mid = (low + high) / 2;

        comparisons = comparisons + 1;
        if (key == a[mid]) {
            std::cout << "Key found at index " << mid << " | Comparisons: " << comparisons << '\n';
            return comparisons;
        }

        comparisons = comparisons + 1;
        if (key > a[mid]) {
            return binarySearch(a, mid + 1, high, key, comparisons);
        }
        else {
            return binarySearch(a, low, mid - 1, key, comparisons);
        }
    }
};

