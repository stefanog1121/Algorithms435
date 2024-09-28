#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "palindromes.h"

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
}

int main() {
    vector<string> list = readFile("/Users/stfarro/Library/Mobile Documents/com~apple~CloudDocs/Marist 24-25/Algorithms/Algorithms435/assignment1/magicitems.txt");

    palindromes(list);


    // selectionSort(list);
    // insertionSort(list);
    // mergeSort(list);
    // quickSort(list);

    return 0;
}