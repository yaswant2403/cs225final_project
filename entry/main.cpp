#include <iostream>
#include "../src/Graph.h"

using namespace std;
// Temporary Testing File to ensure Cmake is working correctly 
int main() {
    Graph g;
    g.BuildGraph("../data/686.edges");
    g.print();

    // Using to check that bfs got these nodes
    vector<Vertex> disc = g.getDisconnectedNodes();
    cout << endl;
    for (auto v : disc) {
        cout << v << " ";
    }
    vector<Vertex> bfs = g.BFS();
    return 0;
}