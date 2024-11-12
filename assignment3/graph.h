#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <vector>

class Graph {
    private:
        std::vector<int> vertices;
        std::vector<std::vector<int>> matrix;
        std::map<int, std::vector<int>> adjacent;

        // linked-list object structure
        struct Vertex {
            int id;
            bool processed;
            std::vector<int> neighbors;
        };
        std::map<int, Vertex> vertex_map;
    public:
        Graph();
        void addVertex();
        void addEdge();
        void printMatrix();
        void printAdjList();
        void printDFS();
        void printBFS();
};

#endif 