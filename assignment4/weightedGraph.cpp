#include "weightedGraph.h"

Graph::Vertex::Vertex() : id(0) {}

Graph::Vertex::Vertex(int num) : id(num) {}

Graph::Graph() : title(), vertices() {}

void Graph::setTitle(std::string title) {
    this->title = title;
}

std::string Graph::getTitle() {
    return title;
}

void Graph::addVertex(int id) {
    vertices[id] = Vertex(id);
}

void Graph::addEdge(int from, int to, int weight) {
    vertices[from].neighbors.push_back({to, weight});
}

const std::map<int, Graph::Vertex>& Graph::getVertices() {
    return vertices;
}