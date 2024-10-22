#include <iostream>
#include <vector>

int linearSearch(std::vector<std::string>& a, std::string key) 
{
    int comparisons = 0;
    bool found;
    for (int i = 0; i < a.size(); i++) {
        comparisons = comparisons + 1;
        if (a[i] == key) {
            std::cout << key << "Found at index " << i << " | Comparisons: " << comparisons;
            found = true;
            break;
        }
    }
    if (found) {
        return comparisons;
    }
    else {
        return INT_MIN;
    }
};

int binarySearch(std::vector<std::string>& a, std::string key)
{

};