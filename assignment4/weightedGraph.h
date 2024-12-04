#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <map>
#include <limits>

class Graph {
private:
    struct Vertex {
        int id;
        std::vector<std::pair<int, int>> neighbors;  // (destination_vertex, weight)
        int distance;                                
        int predecessor;                             
        
        Vertex() : id(0), distance(INT_MAX), predecessor(-1) {}
        Vertex(int num) : id(num), distance(INT_MAX), predecessor(-1) {}
    };

    std::string title;
    std::map<int, Vertex> vertices;  // maps vertex ID to unique Vertex object

public:
    Graph();
    
    void setTitle(std::string title);
    std::string getTitle();
    
    void addVertex(int id);
    void addEdge(int from, int to, int weight);
    void SSSP(int source);
    void relax(int u, int v, int w);

    static std::vector<Graph*> parseGraphList(std::vector<std::string>& list);
};

#endif