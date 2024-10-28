#include <iostream>
#include <vector>

#include "quickSort.h"

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
    if (!found) {
        std::cout << "Key Not Found!" << '\n';
    }
    return comparisons;
};

int binarySearch(std::vector<std::string>& a, int low, int high, std::string key, int comparisons)
{
    if (low > high) {
    std::cout << "Key Not Found!" << '\n';
        return comparisons;
    }
    else { 
    // find midpoint of array, compare to key, and move into left/right problem space recursively based on equality
        int mid = (low + high) / 2;

        comparisons = comparisons + 1;
        if (makeLower(key) == makeLower(a[mid])) {
            std::cout << "Key found at index " << mid << " | Comparisons: " << comparisons << '\n';
            return comparisons;
        }

        comparisons = comparisons + 1;
        if (makeLower(key) > makeLower(a[mid])) {
            return binarySearch(a, mid + 1, high, key, comparisons);
        }
        else {
            return binarySearch(a, low, mid - 1, key, comparisons);
        }
    }
};

void linearGetItems(std::vector<std::string>& list, std::vector<std::string>& items) {
    double linearComparisonsCount = 0;
        for (std::string i : items) {
            linearComparisonsCount += linearSearch(list, i);
        }
        double avgl = linearComparisonsCount / 42.0;
        std::cout << "Average Linear Search Comparisons: " << avgl << '\n';
        std::cout << '\n';
};

void binaryGetItems(std::vector<std::string>& list, std::vector<std::string>& items) {
    double binaryComparisonsCount = 0;
    for (std::string i : items) {
        binaryComparisonsCount += binarySearch(list, 0, list.size() - 1, i, 0);
    }
    double avgb = binaryComparisonsCount / 42.0;
    std::cout << "Average Binary Search Comparisons: " << avgb << '\n';
    std::cout << '\n';
};

