#include <iostream>
#include "../src/Graph.h"

using namespace std;
// Temporary Testing File to ensure Cmake is working correctly 
int main() {
    cout << "Welcome to Y'ALL's profile search tool!" << endl;
    Graph g;
    g.BuildGraph("../data/686.edges");


    int x; 
    cout << "Enter a user ID to get back their rank according to PageRank and Betweenness Centrality: ";
    cin >> x; 

    int graphSize = g.getAllVertices().size();
    vector<Vertex> bcAll = g.getTopIDs(graphSize);
    int rank = 0;
    for (Vertex v : bcAll) {
        rank++;
        if (v == x) break;
    }
    cout << "Their rank according to BC is " << rank << " / " << graphSize << "." << endl;

    vector<Vertex> prAll = g.PageRank(graphSize, 1000);
    rank = 0;
    for (Vertex v : prAll) {
        rank++;
        if (v == x) break;
    }
     cout << "Their rank according to PageRank is " << rank << " / " << graphSize << "." << endl;
 
    return 0;
}