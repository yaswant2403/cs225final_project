#include "Graph.h"

int main(int argc, char *argv[]) {
    if (argc > 3) {
        cout << "Invalid amount of arguments for Betweenness Centrality. Check the Running Code section in our repository" << endl;
        return 0;
    }
    string filename = "../data/686.edges";
    int num_place = 10;
    if (argc == 2) {
        filename = string(argv[1]);
    } 
    if (argc == 3) {
        num_place = stoi(argv[2]);
    }
    Graph g;
    g.BuildGraph(filename);
    g.getBetweennessCentrality(num_place);
}