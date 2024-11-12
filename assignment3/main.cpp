#include "BST.h"
#include "graph.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

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
}

int main() {
    std::vector<std::string> list = readFile("magicitems.txt");
    std::vector<std::string> targetList = readFile("magicitems-find-in-bst.txt");

    BST Tree;
    Tree.populateTree(list);

    
    std::cout<<"\n" << "-------------------" << "\n" << "\n";
    Tree.inOrderTraversal(Tree.getRoot());

    
    std::cout<<"\n" << "-------------------" << "\n" << "\n";
    int comparisons = 0;
    for (const auto& i : targetList) {
        int count = Tree.search(Tree.getRoot(), i, 0);
        std::cout << "Comparisons: " << count << "\n";
        comparisons = comparisons + count;
    }
    comparisons  = comparisons / targetList.size();
    std::cout << "Average Comparisons for list of size " << targetList.size() << " :" << comparisons << "\n";
}