#include "Graph.h"

int main(int argc, char *argv[]) {
    if (argc > 3) {
        cout << "Invalid amount of arguments for Betweeness Centrality (BC). Check the Running Code section in our repository" << endl;
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
    g.BetweennessCentrality();
    vector<Vertex> ranked = g.getTopIDs(num_place);
    cout << "Here is the top " << num_place << " of this social network graph:" << endl; 
    cout << "According to the Betweeness Centrality(BC) Algorithm " << endl;
    cout << "BC represents the number of shortest paths of all pairs in the network that the user is part of!" << endl;
    int i = 0;
    for (auto& v : ranked) {
        if (i != num_place) {
            cout << " #" << i + 1 << ": " << v << endl;
        }
        i++;
    }
    cout << "Here is the number 1 user in this social network graph! " << endl;
    cout << "User: " << ranked.at(0) << " and their BC Value: " << g.getUserBetweennessCentrality(ranked.at(0)) <<endl;
    cout << "And this is their normalized BC Value: " << g.getPercentUserBetweennessCentrality(ranked.at(0)) <<endl;
    cout << endl;
    return 0;
}