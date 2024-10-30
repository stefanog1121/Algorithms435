#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include "quickSort.h"
#include "search.h"
#include "hashTable.h"

std::vector<std::string> readFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::string> list;

    if (file.is_open()) {
        while (getline(file, line)) {
            list.push_back(line);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << '\n';
        std::cerr << "Error: " << strerror(errno) << '\n';  // Add this for more detail
    }
    return list;
};

// returns a random number 1 to size-1 inclusive
int getRandomNumber(std::vector<std::string>& a) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, a.size() - 1);
    return dis(gen);
}

int main() {
    // read in + sort magic items
    std::vector<std::string> list = readFile("magicitems.txt");
    quickSort(list, 0, list.size() - 1);

    // pick 42 items at random
    std::vector<std::string> items;
    for (int i = 0; i < 42; i++) {
        int r = getRandomNumber(list);
        items.push_back(list[r]);
    }

    // set floating point precision for printing
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(2);
    
    // search avg comparisons
    linearGetItems(list, items);
    binaryGetItems(list, items);

    // hashing comparisons
    HashTable table;
    table.hashGetItems(list, items);
}

