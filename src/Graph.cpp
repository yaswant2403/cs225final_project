#include "Graph.h"
#include "utils.h"

Graph::Graph() {
    size = 0;
    adj_list = new unordered_map<Vertex, list<Vertex>>();
    visited = new unordered_map<Vertex, bool>();
}

Graph::~Graph() {
    delete visited;
    delete adj_list;
}

// Doesn't account for disconnected component with no edges
// Can assume for our purpose that no single node will be disconnected
void Graph::BuildGraph(const string & filename) {
    string file = file_to_string(filename);
    vector<string> edges;
    SplitString(file, '\n', edges);
    for (auto edge : edges) {
        vector<string> e;
        SplitString(edge, ' ', e);
        // If the edge (no start & end node) then continue
        if (e.size() != 2) {
            continue;
        }
        AddVertex(stoi(e.at(0)));
        AddVertex(stoi(e.at(1)));
        AddEdge(stoi(e.at(0)), stoi(e.at(1)));
    }
}

vector<Vertex> Graph::getAllVertices() {
    vector<Vertex> vertices;
    for (auto it = adj_list->begin(); it != adj_list->end(); ++it) {
        vertices.push_back(it->first);
    }
    return vertices;
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
        list<Vertex> v1_neighbors = adj_list->find(id1)->second;
        return !(find(v1_neighbors.begin(), v1_neighbors.end(), id2) == v1_neighbors.end());
    }
}

int Graph::getSize() {
    return size;
}

vector<Vertex> Graph::BFS() {
    // Reset visited incase someone does BFS twice
    delete visited;
    visited = new unordered_map<Vertex, bool>();
    // Grabs all vertices
    vector<Vertex> vertices = getAllVertices();
   
    for (auto v : vertices) {
        visited->insert(make_pair(v, false));
    }
    vector<Vertex> output;

    // Does BFS on each vertex in vertices if vertex hasn't been visited yet
    for (int idx = 0; idx < size; ++idx) {
        int vertex = vertices.at(idx);
        if (visited->find(vertex)->second == false) {
            BFSHelper(vertex, output);
        }
    }
    return output;
}

void Graph::BFSHelper(Vertex id, vector<Vertex>& out) {
    queue<Vertex> q;
    // enqueue starting node
    q.push(id);
    // setting starting node as visited
    visited->find(id)->second = true;
    while (!(q.empty())) {
        // dequeue vertex
        int currVertex = q.front();
        out.push_back(currVertex);
        q.pop();

        // Get currVertex Neighbors
        list<Vertex> currNeighbors = adj_list->find(currVertex)->second;
        for (auto neighbor : currNeighbors) {
            // if vertex hasn't been visited AKA visited == false
            if (!visited->find(neighbor)->second) {
                visited->find(neighbor)->second = true;
                q.push(neighbor);
            }
        }
    }
}

list<Vertex> Graph::PageRank(int num_places, double alpha) {
    // Handle cases of bad alpha values
    if (alpha > 1) {
        alpha = 1;
    } else if (alpha < 0) {
        alpha = 0;
    }
    list<Vertex> ranking;
    unordered_map<int, Vertex> idx_map;
    unordered_map<Vertex, int> reverse_idx;
    // map n indices to the ids of nodes, store a map of indices to the ID of each node 
    // to make building Markov Matrix & ranking list possible 
    int i = 0;
    for (auto it = adj_list->begin(); it != adj_list->end(); it++) {
        idx_map.insert(make_pair(i, it->first));
        reverse_idx.insert(make_pair(it->first, i));
        i++;
    }
    // Make Adjacency/Markov Matrix 
    Matrix M = makeAdjMatrix(reverse_idx);

    // Create Google PageRank Matrix of our graph which of 
    // size n x n where n is size of graph/number of vertices
    // G = alpha * M + ((1-alpha) / n * 1)
    // Where M is Markov adjacency matrix & 1 is a matrix of all ones
    Matrix ones(size, size, 1.0);
    double ones_coeff = (1 - alpha) / size;
    Matrix aM = alpha * M;
    Matrix O = ones_coeff * ones;
    Matrix G = aM + O;

    // Generate a normalized starting state vector of size n x 1
    Matrix x0(size, 1, 0);
    x0(0, 0) = 1;
    //Perform Matrix vector multiplication until change in vector between iterations is 
    // under some tolerance/ we reach a specificed maximum number of iterations
    // TODO: Add loop break if the change in vectors is under a certain tolerance
    for (int i = 0; i < 20; i++) {
        Matrix x = G * x0;
        double norm = 0.0;
        for (unsigned j = 0; j < x.getRows(); j++) {
            norm += abs(x(j, 0));
        }
        norm = 1 /norm;
        x0 = x * norm;
    }
    
    //Sort the indices of the output vector from largest to smallest & pull the ids of these indices from the map 
    // Take the indices of the largest num_places values and create ranking 
    // If num_place > num vertices, then list will be of size num vertices
    vector<int> ranks(x0.getRows());
    iota(ranks.begin(), ranks.end(), 0);
    stable_sort(ranks.begin(), ranks.end(), [&](int i, int j){return x0(i, 0) > x0(j, 0);});
    for (auto i = 0; i < min(num_places, size); i++) {
        ranking.push_back(idx_map.find(ranks.at(i))->second);
    }
    return ranking;
}

Matrix Graph::makeAdjMatrix(unordered_map<Vertex, int>& reverse_idx) {
    Matrix M(size, size, 0);
    for (auto it = adj_list->begin(); it != adj_list->end(); it++) {
        list<Vertex> V = it->second;
        Vertex col = reverse_idx.find(it->first)->second;

        double value;
        double sz = V.size();

        if (V.size() == 0) {
            value = 1 / size;
        } else {
            value = 1 / sz;
        }
    
        for (Vertex node : V) {
            Vertex row = reverse_idx.find(node)->second;
            M(row, col) = value;
        }
    }
    return M;
}

void Graph::BetweennessCentrality(int num_places) {
    vector<std::pair<Vertex, int>> bc;
    //get BC for each vertice
    for (auto v : getAllVertices()) {
        bc.push_back(std::make_pair(v, getUserBetweennessCentrality(v)));
    }
    //sort vector based on BC value
    std::stable_sort(bc.begin(), bc.end(), [](auto &one, auto &two) {
        return one.second > two.second;
    });
    
    //output rankings
    cout << "BETWEENNESS CENTRALITY RANKINGS:" << endl; 
    cout << "BC represents the percentage of shortest paths of all pairs in the network that the user is part of" << endl;
    for (int i = 0; i < num_places; ++i) {
        cout << "#" << (i+1) << ". " << bc[i].first;
        cout << ", BC: " << bc[i].second << "%" << endl;
    }
}

int Graph::getUserBetweennessCentrality(int id) {
    //temp return, obviously wrong rn
    return id;
}



void Graph::AddVertex(Vertex id) {
    if (!vertexExists(id)) {
        adj_list->insert(make_pair(id, list<Vertex>()));
        visited->insert(make_pair(id, false));
        size++;
    }
}

void Graph::AddEdge(Vertex id1, Vertex id2) {
    if (vertexExists(id1) && vertexExists(id2) && !(edgeExists(id1, id2))) {
        adj_list->at(id1).push_back(id2);
        adj_list->at(id2).push_back(id1);
    }
}

vector<Vertex> Graph::getDisconnectedNodes() {
    vector<Vertex> vertices = getAllVertices();
    vector<Vertex> result;
    for (auto v : vertices) {
        if (adj_list->find(v)->second.size() <= 1) {
            result.push_back(v);
        }
    }
    return result;
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