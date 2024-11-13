#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <vector>

class Graph {
    private:
        std::string title;
        std::vector<int> vertices;
        std::vector<std::vector<int>> matrix;
        std::map<int, std::vector<int>> adjacent;

        // linked-list object structure
        struct Vertex {
            Vertex();
            Vertex(int num);
            int id;
            bool processed;
            std::vector<int> neighbors;
        };
        std::map<int, Vertex> vertex_map;
    public:
        Graph();
        void setTitle(std::string title);
        std::string getTitle();
        Graph::Vertex& getFirstVertex();
        void addVertex(int id);
        void addEdge(int x, int y);
        void printMatrix();
        void printAdjList();
        void printDFS(Vertex& v);
        void printBFS(Vertex& v);
        static std::vector<Graph> parseGraphList(std::vector<std::string>& list);
};

#endif 