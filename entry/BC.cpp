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
    cout << "Here is the top " << num_place << " of this social network graph based on Betweenness Centrality: " << endl;
    cout << endl;
    int i = 0;
    for (auto& v : ranked) {
        if (i != num_place) {
            cout << i + 1 << ": " << " User with ID - " << v;
            cout << ",  BC Value: " << g.getUserBetweennessCentrality(ranked.at(i));
            cout << ",  As Percentage: " << g.getPercentUserBetweennessCentrality(ranked.at(i)) << "%" << endl;
        }
        i++;
    }
    cout << endl;
    cout << "Here is the number 1 user in this social network graph based on BC! " << endl;
    cout << "User: " << ranked.at(0) << ", BC Value: " << g.getUserBetweennessCentrality(ranked.at(0)) <<endl;
    cout << "This is their BC Value as a percentage of estimated number of shortest paths: " << g.getPercentUserBetweennessCentrality(ranked.at(0)) << "%" << endl;
    cout << endl;
    return 0;
}