#include "Graph.h"
#include "utils.h"

Graph::Graph() {
    size = 0;
    adj_list = new unordered_map<Vertex, list<Vertex>>();
}

Graph::~Graph() {
    delete adj_list;
}

void Graph::BuildGraph(const string & filename) {
    string file = file_to_string(filename);
    vector<string> edges;
    SplitString(file, '\n', edges);
    for (auto edge : edges) {
        vector<string> e;
        SplitString(edge, ' ', e);
        AddVertex(stoi(e.at(0)));
        AddVertex(stoi(e.at(1)));
        AddEdge(stoi(e.at(0)), stoi(e.at(1)));
    }
}

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

list<Vertex> Graph::BFS() {
    return list<Vertex>();
}
  
list<Vertex> Graph::PageRank(int num_places) {
    return list<Vertex>();
}

int Graph::BetweennessCentrality() {
    return 1;
}

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

void Graph::print() const {
    for (auto it = adj_list->begin(); it != adj_list->end(); it++) {
        cout << "Node " << it->first << " : ";
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            cout << *it2 << ' ';
        }
        cout << endl;
    }
    cout << endl;
}