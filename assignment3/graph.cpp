#include "graph.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <sstream>

// graph / vertex constructors:
Graph::Graph() : title(), vertices(), matrix(), adjacent(), vertex_map() {}

Graph::Vertex::Vertex() : id(0), processed(false), neighbors() {}

Graph::Vertex::Vertex(int num) : id(num), processed(false), neighbors(std::vector<int>()) {}


// title setter / getters
void Graph::setTitle(std::string title) {
    this->title = title;
}

std::string Graph::getTitle() {
    return this->title;
}

Graph::Vertex& Graph::getFirstVertex() {
    return vertex_map[vertices[0]];
}


void Graph::addVertex(int id) {
     vertices.push_back(id);

    // adjust existing matrix to accomodate addition
     for (auto& row : matrix) {
        row.push_back(0);
    }
    // new row for additional vertex
    matrix.push_back(std::vector<int>(vertices.size(), 0));
    
    // add to adjacency list
    adjacent[id] = std::vector<int>();
    
    // add to map of linked vertex objects
    vertex_map[id] = Vertex(id);
};

void Graph::addEdge(int x, int y) {
    // find the index of each end of the edge in the list of vertices
    int xInd = std::find(vertices.begin(), vertices.end(), x) - vertices.begin();
    int yInd = std::find(vertices.begin(), vertices.end(), y) - vertices.begin();

    // mark the connection at each (mirrored) matrix position
    matrix[xInd][yInd] = 1;
    matrix[yInd][xInd] = 1;

    // mark the connecting edge to both vectors in the adjacency list
    adjacent[x].push_back(y);
    adjacent[y].push_back(x);

    // add each edge as a neighbor to both vertex objects
    vertex_map[x].neighbors.push_back(y);
    vertex_map[y].neighbors.push_back(x);


};

void Graph::printMatrix() {
    std::cout<< "\n----------Matrix Representation---------" << "\n";
    // Print column headers
    std::cout << "  ";
    for (int vertex : vertices) {
        std::cout << vertex << " ";
    }
    std::cout << "\n";
    
    // Print rows
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << vertices[i] << " ";
        for (int edge : matrix[i]) {
            std::cout << edge << " ";
        }
        std::cout << "\n";
    }
};

void Graph::printAdjList() {
    std::cout<< "\n----------Ajacency List Representation---------" << "\n";
    for (std::pair<const int, std::vector<int>> pair : adjacent) {
        std::cout << "[" << pair.first << "] ";
        for (int neighbor : pair.second) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
    }
};

void Graph::printDFS(Vertex& v) {
    if (!v.processed) {
        std::cout << v.id << " ";
        v.processed = true;
    }
    for (int neighborId : v.neighbors) {
        if (!vertex_map[neighborId].processed) {
            printDFS(vertex_map[neighborId]);
        }
    }
};

void Graph::printBFS(Vertex& v) {
    // reset all processed flags
    for (auto& pair : vertex_map) {
        pair.second.processed = false;
    }

    std::queue<Vertex*> q;
    q.push(&v);
    v.processed = true;

    while (!q.empty()) {
        Vertex* curr = q.front();
        q.pop();
        std::cout << curr->id << " ";
        for (int i : curr->neighbors) {
            Vertex& neighbor = vertex_map[i];
            if (!neighbor.processed) {
                q.push(&neighbor);
                neighbor.processed = true;
            }
        }
    }

    // check vertex_map for any disconnected components
    for (auto& pair : vertex_map) {
        if (!pair.second.processed) {
            Vertex& unvisited = pair.second;
            q.push(&unvisited);
            unvisited.processed = true;
            
            while (!q.empty()) {
                Vertex* curr = q.front();
                q.pop();
                std::cout << curr->id << " ";
                for (int i : curr->neighbors) {
                    Vertex& neighbor = vertex_map[i];
                    if (!neighbor.processed) {
                        q.push(&neighbor);
                        neighbor.processed = true;
                    }
                }
            }
        }
    }
    std::cout << "\n";
};

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
            ss >> temp;  // skips "vertex" or "edge"
            
            if (temp == "vertex") {
                int vertexId;
                ss >> vertexId;
                curr->addVertex(vertexId);
            }
            else if (temp == "edge") {
                int from, to;
                ss >> from;
                ss >> temp;  // skip the "-" character
                ss >> to;
                curr->addEdge(from, to);
            }
        }
    }

    if (curr != nullptr) {
        graphs.push_back(curr);
    }
    return graphs;
}