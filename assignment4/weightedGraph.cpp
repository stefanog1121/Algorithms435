#include "weightedGraph.h"
#include <iostream>
#include <sstream>

Graph::Graph() : title(), vertices() {}

void Graph::setTitle(std::string title) {
    this->title = title;
}

std::string Graph::getTitle() {
    return title;
}

void Graph::addVertex(int id) {
    vertices.emplace(id, Vertex(id));
}

void Graph::addEdge(int from, int to, int weight) {
    vertices[from].neighbors.push_back({to, weight});
}

std::vector<Graph*> Graph::parseGraphList(std::vector<std::string>& list) {
    std::vector<Graph*> graphs;
    Graph* curr = nullptr;
    std::string currentTitle;

    for (const auto& line : list) {
        // grab title from comment lines
        if (line.substr(0, 2) == "--") {
            currentTitle = line;
            continue;
        }
        if (line.empty()) continue;
        
        std::stringstream ss(line);
        std::string command, temp;
        
        ss >> command;
        
        if (command == "new") {
            if (curr != nullptr) {
                graphs.push_back(curr);
            }
            curr = new Graph();
            curr->setTitle(currentTitle);
        }
        else if (command == "add") {
            ss >> temp;  // skips to "vertex" or "edge"
            
            if (temp == "vertex") {
                int vertexId;
                ss >> vertexId;
                curr->addVertex(vertexId);
            }
            else if (temp == "edge") {
                int from, to, weight;
                ss >> from;
                ss >> temp;  // skip the "-" character
                ss >> to;
                ss >> weight;
                curr->addEdge(from, to, weight);
            }
        }
    }

    if (curr != nullptr) {
        graphs.push_back(curr);
    }
    return graphs;
}

void Graph::SSSP(int source) {
    vertices[source].distance = 0;
    
    // relax edges |V| - 1 times
    int V = vertices.size();
    for (int i = 1; i <= V - 1; i++) {
        for (const auto& vertex : vertices) {
            int u = vertex.first;
            for (const auto& edge : vertex.second.neighbors) {
                int v = edge.first;   // destination vertex
                int w = edge.second;  // edge weight
                relax(u, v, w);
            }
        }
    }
    
    // negative weight cycle check
    for (const auto& vertex : vertices) {
        int u = vertex.first;
        for (const auto& edge : vertex.second.neighbors) {
            int v = edge.first;
            int w = edge.second;
            if (vertices[u].distance != INT_MAX && 
                vertices[u].distance + w < vertices[v].distance) {
                std::cout << "Graph contains negative weight cycle!" << std::endl;
                return;
            }
        }
    }
    
    // pretty pritning
    for (const auto& vertex : vertices) {
        int v = vertex.first;
        if (v != source) {  
            std::cout << source << " --> " << v << " Cost: " 
                     << vertices[v].distance << " | Path: ";
            
            std::vector<int> path;
            int current = v;
            while (current != -1) {
                path.push_back(current);
                current = vertices[current].predecessor;
            }
            
            for (int i = path.size() - 1; i >= 0; i--) {
                std::cout << path[i];
                if (i > 0) std::cout << " --> ";
            }
            std::cout << std::endl;
        }
    }
}

void Graph::relax(int u, int v, int w) {
    if (vertices[u].distance != INT_MAX && 
        vertices[u].distance + w < vertices[v].distance) {
        vertices[v].distance = vertices[u].distance + w;
        vertices[v].predecessor = u;
    }
}