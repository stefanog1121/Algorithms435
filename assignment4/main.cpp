#include "weightedGraph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> readFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return lines;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    
    file.close();
    return lines;
}

void testGraphs(const std::string& filename) {
    std::vector<std::string> lines = readFile(filename);
    if (lines.empty()) {
        std::cerr << "Error: File not found" << std::endl;
        return;
    }
    
    std::vector<Graph*> graphs = Graph::parseGraphList(lines);
    
    for (size_t i = 0; i < graphs.size(); i++) {
        std::cout << "\n=== Graph " << (i + 1) << " ===" << std::endl;
        if (!graphs[i]->getTitle().empty()) {
            std::cout << graphs[i]->getTitle() << std::endl;
        }
        
        // run Bellman-Ford SSSP from vertex 1
        graphs[i]->SSSP(1);
        std::cout << std::endl;
    }
    
    // clean up after done
    for (Graph* graph : graphs) {
        delete graph;
    }
}

int main() {
    testGraphs("graphs2.txt");  //  *** Change this line for other graph files ***
    
    return 0;
}