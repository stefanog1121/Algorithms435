#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <map>

class Graph {
private:
    struct Vertex {
        int id;
        std::vector<std::pair<int, int>> neighbors;  // pairs = (destination_vertex, weight)
        
        Vertex();
        Vertex(int num);
    };

    std::string title;
    std::map<int, Vertex> vertices;  // maps vertex ID to unique Vertex object

public:
    Graph();
    
    void setTitle(std::string title);
    std::string getTitle();
    
    void addVertex(int id);
    void addEdge(int from, int to, int weight);
    
    const std::map<int, Vertex>& getVertices();
};

#endif