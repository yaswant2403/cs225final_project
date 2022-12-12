#include <iostream>
#include "../src/Graph.h"

using namespace std;
// Temporary Testing File to ensure Cmake is working correctly 
int main() {
    cout << endl;
    cout << "Welcome to Y'ALL's profile search tool!" << endl;
    cout << "_______________________________________" << endl;
    Graph g;
    g.BuildGraph("../data/686.edges");


    string ID; 
    cout << endl;
    cout << "(Enter 'done' or CTRL+C to stop using the tool)" << endl;
    while (ID != "done") {
        cout << "Enter a user ID to get back their rank according to PageRank and Betweenness Centrality. " << endl;
        cout << "Example input for user ID 828: '828'" << endl;
        cout << endl;
        cout << "User ID: ";

        cin >> ID; 
        if (ID == "done") return 0;

        while (!g.vertexExists(stoi(ID))) {
            cout << "Invalid user ID! Try again." << endl;
            cout << "User ID: ";
            cin >> ID;
            if (ID == "done") return 0;
        }
        int x = stoi(ID);

        int graphSize = g.getSize();
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
        cout << "____________________" << endl;
        cout << endl;
    }
    return 0;
}
