#include "Graph.h"

int main(int argc, char *argv[]) {
    if (argc > 2) {
        cout << "Invalid amount of arguments for BFS. Check the Running Code section in our repository" << endl;
        return 0;
    }
    string filename = "../data/686.edges";
    if (argc == 2) {
        filename = string(argv[1]);
    }
    Graph g;
    g.BuildGraph(filename);
    vector<Vertex> bfs = g.BFS();
    cout << "Here is the BFS traversal order of this social network graph: " << endl;
    int i = 0;
    for (auto v : bfs) {
        cout << v << " ";
        if (i == 10) {
            i = 0;
            cout << endl;
        } else {
            i++;    
        }
    }
    cout << endl;
    return 0;
}