#include "Graph.h"
#include "utils.h"

using namespace std;

Graph::Graph() {
    size = 0;
    adj_list = new unordered_map<Vertex, list<Vertex>>();
}

Graph::~Graph() {
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

void Graph::AddVertex(Vertex id) {
    if (!vertexExists(id)) {
        adj_list->insert(make_pair(id, list<Vertex>()));
        visited[id] = false;
        size++;
    }
}

void Graph::AddEdge(Vertex id1, Vertex id2) {
    if (vertexExists(id1) && vertexExists(id2) && !(edgeExists(id1, id2))) {
        adj_list->at(id1).push_back(id2);
        adj_list->at(id2).push_back(id1);
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
    // Grabs all vertices
    vector<Vertex> vertices = getAllVertices();

    // Reset visited if any of the vertices have been visited
    // In case someone does BFS Twice
    if (visited.begin()->second) {
        visited.clear();
        for (auto& v : vertices) {
            visited.insert(make_pair(v, false));
        }
    }

    vector<Vertex> output;

    // Does BFS on each vertex in vertices if vertex hasn't been visited yet
    for (int idx = 0; idx < size; ++idx) {
        int vertex = vertices.at(idx);
        if (visited[vertex] == false) {
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
    visited[id] = true;
    while (!(q.empty())) {
        // dequeue vertex
        int currVertex = q.front();
        out.push_back(currVertex);
        q.pop();

        // Get currVertex Neighbors
        list<Vertex> currNeighbors = (*adj_list)[currVertex];
        for (auto neighbor : currNeighbors) {
            // if vertex hasn't been visited AKA visited == false
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

vector<Vertex> Graph::PageRank(int num_places, int num_iter, double alpha, double tol) {
    // Handle cases of bad alpha values
    if (alpha > 1) {
        alpha = 1;
    } else if (alpha < 0) {
        alpha = 0;
    }
    vector<Vertex> ranking;
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
    for (int i = 0; i < num_iter; i++) {
        Matrix x = G * x0;
        double norm = calcNorm(x);
        norm = 1 / norm;
        if (calcNorm(x - x0) <= tol) {
            x0 = x * norm;
            break;
        } else {
            x0 = x * norm;
        }
    }
    // Add back if we want to show number of iterations for pagerank
    //cout << "Number of iterations needed to converge to steady state for PageRank: " << k << endl;
    //Sort the indices of the output vector from largest to smallest & pull the ids of these indices from the map 
    // Take the indices of the largest num_places values and create ranking 
    // If num_place > num vertices, then list will be of size num vertices
    // Sorting by index reference:
    // https://stackoverflow.com/questions/1577475/c-sorting-and-keeping-track-of-indexes 

    vector<int> ranks(x0.getRows());
    iota(ranks.begin(), ranks.end(), 0);
    stable_sort(ranks.begin(), ranks.end(), [&](int i, int j){return x0(i, 0) > x0(j, 0);});
    for (auto i = 0; i < min(num_places, size); i++) {
        ranking.push_back(idx_map.find(ranks.at(i))->second);
    }
    return ranking;
}

double Graph::calcNorm(Matrix vec) const{
    double norm = 0.0;
    for (unsigned j = 0; j < vec.getRows(); j++) {
        norm += abs(vec(j, 0));
    }
    return norm;
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


void Graph::BetweennessCentrality() {
    // incase user calls Betweeness Centrality twice
    betweennessCentrality.clear();
    //grab all vertices
    vector<Vertex> vertices = getAllVertices();

    //initial BC for every vertice is 0
    for (auto& bcv : vertices) {
        betweennessCentrality[bcv] = 0;
    }
    int pathcount = 0;
    for (auto& v : vertices) {
        //initialize maps for all vertices
        /**NOTE: could use vector easier and use one line to fill, but user IDs more complicated
        could maybe write helper to take user id and get matching index based on whatever index
        it would be in getAllVertices()
        for now, ill just match the code from BFS
        **/
        unordered_map<Vertex, int> sps; //shortest path count
        unordered_map<Vertex, vector<Vertex>> pred; //predecessors of each vertex on sps
        unordered_map<Vertex, bool> visited;
        for (auto& tmpv : vertices) {
            sps[tmpv] = -1;
            pred.insert(make_pair(tmpv, 0));
            visited[tmpv] = false;
        }
        //push starting vertex, mark visited and shortest paths
        queue<Vertex> q;
        q.push(v);
        visited[v] = true;
        sps[v] = 0;

        while (!q.empty()) {
            //dequeue vertex
            int currVertex = q.front();
            q.pop();
            //set sp to 0
            sps[currVertex] = 0;

            //for each neighbor
            for (auto& neighbor : adj_list->find(currVertex)->second) {
                // if not visited
                if (!visited[neighbor]) {
                    //mark as visited
                    visited[neighbor] = true;
                    //add dist + 1
                    sps[neighbor] = sps[currVertex] + 1;
                    pred[neighbor].push_back(currVertex);
                    q.push(neighbor);
                }
                //if already visited
                else if (sps[neighbor] == sps[currVertex] + 1) {
                    pred[neighbor].push_back(currVertex);
                }
            }
        }
        for (auto& vert : vertices) {
            if (vert != v) {
                for (auto& predvert : pred[vert]) {
                    //if actual path has more than 2 verts
                    if (pred[predvert].size() > 2) {
                        betweennessCentrality[predvert]++;
                        pathcount++;
                    }
                }
            }
        }
    }
    // cout << pathcount << endl;
    //intialize vector to sort 
    vector<pair<Vertex, float>> sorted_bc;
    // Pushing all Vertices and BC into this vector
    for (auto& pair : betweennessCentrality) {
        sorted_bc.push_back(pair);
    }
    //sort based on BC value descending because unordedmap acts as 
    // vector when inserting so highest BC val will be first pair
    stable_sort(sorted_bc.begin(), sorted_bc.end(), [](auto& pairA, auto& pairB) {
        return pairA.second < pairB.second;
    });
    // putting back into betweenessCentrality map and it's unordered so should be the same order as sorted
    betweennessCentrality.clear();
    for (auto& pair : sorted_bc) {
        betweennessCentrality[pair.first] = pair.second;
    }
    // setting calculatedBC to be true
    calculatedBC = true;
}

vector<Vertex> Graph::getTopIDs(int num_places) {
    // if betweenessCentrality hasn't been calculated, go calculate it first
    if (!calculatedBC) {
        BetweennessCentrality();
    } 
    // output vector for top X number of users
    vector<Vertex> topUsers;
    // Returns dummy vector if num_places > size of graph
    if (num_places > size) {
        return {-1,-1};
    }
    int count = 0;
    for (auto it = betweennessCentrality.begin(); count != num_places && it != betweennessCentrality.end(); ++it) {
        topUsers.push_back(it->first);
        count++;
    }
    return topUsers;
}

float Graph::getUserBetweennessCentrality(int id) {
    // if betweenessCentrality hasn't been calculated, go calculate it first
    if (!calculatedBC) {
        BetweennessCentrality();
    }
    //return corresponding BC value for vertex
    if (vertexExists(id)) {
        return betweennessCentrality[id];
    }
    return -1.0;
}

float Graph::getPercentUserBetweennessCentrality(int id) {
    // if betweenessCentrality hasn't been calculated, go calculate it first
    if (!calculatedBC) {
        BetweennessCentrality();
    }
    //return corresponding normalized BC value for vertex
    if (vertexExists(id)) {
        // normalizing BC Value for undirected graph
        // formula is dividing through each pair not including current vertex
        // by (N - 1)(N - 2)/2 where N is the number of nodes in the graph
        float scaleFactor = 2.0 / ((size - 1) * (size - 2));
        return betweennessCentrality[id] * scaleFactor;
    }
    return -1.0;
}

unordered_map<Vertex, float> Graph::getAllBetweennessCentrality() {
    // if betweenessCentrality hasn't been calculated, go calculate it first
    if (!calculatedBC) {
        BetweennessCentrality();
    }
    return betweennessCentrality;
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