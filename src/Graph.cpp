#include "Graph.h"
#include "utils.h"

Graph::Graph() {
    size = 0;
    adj_list = new unordered_map<Vertex, list<Vertex>>();
}

void Graph::BuildGraph(string filename) {}

list<Vertex> Graph::getAdjacencyList (Vertex id) {
    if (vertexExists(id)) {
        return adj_list->at(id);
    } else {
        return list<Vertex>(1, -1);
    }
}

bool Graph::vertexExists(Vertex id) {
    return !(adj_list->find(id) == adj_list->end());
}
    
bool Graph::edgeExists(Vertex id1, Vertex id2) {
    if (!vertexExists(id1) || !vertexExists(id2)) {
        return false;
    } else {
        list<Vertex> idl = adj_list->find(id1)->second;
        return !(find(idl.begin(), idl.end(), id2) == idl.end());
    }
}

int Graph::getSize() {
    return size;
}

list<Vertex> Graph::BFS() {}
  
list<Vertex> Graph::PageRank(int num_places = 10) {}

int Graph::BetweennessCentrality() {}

void Graph::AddVertex(Vertex id) {
    if (!vertexExists(id)) {
        adj_list->insert(make_pair(id, list<Vertex>()));
        size++;
    }
}

void Graph::AddEdge(Vertex id1, Vertex id2) {
    if (vertexExists(id1) && vertexExists(id2) && !(edgeExists(id1, id2))) {
        adj_list->at(id1).push_back(id2);
        adj_list->at(id2).push_back(id1);
    }
}