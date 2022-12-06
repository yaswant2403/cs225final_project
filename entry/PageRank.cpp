#include "Graph.h"

int main(int argc, char *argv[]) 
{   
    if (argc > 3) {
        cout << "Invalid amount of arguments for PageRank. Check the Running Code section in our repository" << endl;
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
    list<Vertex> result = g.PageRank(num_place);
    cout << "Here are the top " << num_place << " ranked users in this social network graph:" << endl;
    int i = 1;
    for (auto x : result) {
        cout << i << ": User with I.D. " << x << endl;
        i++;
    }
}