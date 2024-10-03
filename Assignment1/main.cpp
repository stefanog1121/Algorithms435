#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "palindromes.h"
#include "sorts.h"

using namespace std;

vector<string> readFile(const string& filename) {
    ifstream file(filename);
    string line;
    vector<string> list;

    if (file.is_open()) {
        while (getline(file, line)) {
            list.push_back(line);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }

    return list;
};

int main() {
    vector<string> list = readFile("/Users/stfarro/Library/Mobile Documents/com~apple~CloudDocs/Marist 24-25/Algorithms/Algorithms435/assignment1/magicitems.txt");

    // Validate palindromes
    //palindromes(list);

    // Randomize array using Knuth shuffle, then sort via ...
    shuffle(list);
    selectionSort(list);
    
    shuffle(list);
    insertionSort(list);

    shuffle(list);
    countMergeSort(list);

    shuffle(list);
    countQuickSort(list);

    // Prints Sorted Array for validation
    
    for (auto i : list) {
        cout << i << std::endl;
    }
    
    return 0;
}