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
        std::cerr << "Error: " << strerror(errno) << '\n'; 
    }
    return list;
}

int main() {
    // set floating point precision for printing
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(2);


    // Binary Search Tree implementation:
    std::vector<std::string> list = readFile("magicitems.txt");
    std::vector<std::string> targetList = readFile("magicitems-find-in-bst.txt");

    std::cout<<"\n" << "---------- Populating BST ---------" << "\n" << "\n";
    BST Tree;
    Tree.populateTree(list);

    std::cout<<"\n" << "---------- BST Traversal ---------" << "\n" << "\n";
    Tree.inOrderTraversal(Tree.getRoot());

    std::cout<<"\n" << "---------- Searching Comparison ---------" << "\n" << "\n";
    double comparisons = 0;
    for (const auto& i : targetList) {
        int count = Tree.search(Tree.getRoot(), i, 0);
        comparisons = comparisons + count;
    }
    comparisons  = comparisons / targetList.size();
    std::cout << "-------------------" << "\n";
    std::cout << "Average Comparisons for list of size " << targetList.size() << ": " << comparisons << "\n";

    
    // Graph implementation:
    std::vector<std::string> graphCommandList = readFile("graphs1.txt"); 
    // ^^ change string in the line above to use different command files

    std::vector<Graph> graphs = Graph::parseGraphList(graphCommandList);
    for (auto& graph : graphs) {
        std::cout << "\n"<< graph.getTitle() << ":\n";
        graph.printMatrix();
        graph.printAdjList();

        std::cout<< "\n----------Depth First Traversal---------" << "\n";
        graph.printDFS(graph.getFirstVertex());
        std::cout<< "\n\n----------Breadth First Traversal---------" << "\n";
        graph.printBFS(graph.getFirstVertex());
    }
    
    
    


}