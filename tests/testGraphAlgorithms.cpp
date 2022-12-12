#include <catch2/catch_test_macros.hpp>

#include "Graph.h"
#include <map>

using namespace std;

// Helper Functions for Test Cases

vector<Vertex> generateBFS(string filename, int startV) {
    Graph g;
    g.BuildGraph(filename);
    vector<Vertex> bfs;
    g.BFSHelper(startV, bfs);
    return bfs;
}

TEST_CASE("Small Graph - BFS Traversal","[algo][BFS]") {
    // Building Graph from https://www.programiz.com/dsa/graph-bfs
    // All Possible BFS Traversals from this Graph 
    // key: starting vert value: traversal 
    map<int, vector<Vertex>> all_traversals;
    all_traversals[0] = {0, 1, 2, 3, 4};
    all_traversals[1] = {1, 0, 2, 3, 4};
    all_traversals[2] = {2, 0, 1, 4, 3};
    all_traversals[3] = {3, 0, 1, 2, 4};
    all_traversals[4] = {4, 2, 0, 1, 3}; // after 2 gets popped, it goes to 0 because that's next in queue

    // Using BFS Helper to verify that all traversals are correct regardless of where you start
    REQUIRE(all_traversals[0] == generateBFS("../data/small_graph.txt", 0));
    REQUIRE(all_traversals[1] == generateBFS("../data/small_graph.txt", 1));
    REQUIRE(all_traversals[2] == generateBFS("../data/small_graph.txt", 2));
    REQUIRE(all_traversals[3] == generateBFS("../data/small_graph.txt", 3));
    REQUIRE(all_traversals[4] == generateBFS("../data/small_graph.txt", 4));

    // Manually building Graph
    Graph g;
    g.AddVertex(0);
    g.AddVertex(1);
    g.AddVertex(2);
    g.AddVertex(3);
    g.AddVertex(4);

    g.AddEdge(0,1);
    g.AddEdge(0,2);
    g.AddEdge(0,3);
    g.AddEdge(1,2);
    g.AddEdge(2,4);
    // g.print();

    // Creating Random BFS using BFS Function
    vector<Vertex> bfs = g.BFS();
    int starting_vertex = bfs.at(0);
    // Asserting that random BFS also generates correct traversal
    REQUIRE(bfs == generateBFS("../data/small_graph.txt",starting_vertex));
    REQUIRE(int(bfs.size()) == g.getSize());
}

TEST_CASE("First Small Disconnected - BFS Traversal", "[algo][BFS]") {
    Graph g;
    g.BuildGraph("../data/small_disconnected.txt");
    vector<Vertex> bfs = g.BFS();
    vector<Vertex> answer = {6, 5, 4, 3, 2, 1}; 
    REQUIRE(answer == bfs);
}

TEST_CASE("Second Small Disconnected - BFS Traversal","[algo][BFS]") {
    // Building Graph from https://www.programiz.com/dsa/graph-bfs
    // All Possible BFS Traversals from this Graph 
    // key: starting vert value: traversal 
    map<int, vector<Vertex>> all_traversals;
    all_traversals[0] = {0, 1, 2, 3};
    all_traversals[1] = {1, 0, 2, 3};
    all_traversals[2] = {2, 0, 1, 3};
    all_traversals[3] = {3, 0, 1, 2};
    all_traversals[4] = {4, 6};
    all_traversals[6] = {6, 4};

    // Using BFS Helper to verify that all traversals are correct regardless of where you start
    REQUIRE(all_traversals[0] == generateBFS("../data/small_2_disconnected.txt", 0));
    REQUIRE(all_traversals[1] == generateBFS("../data/small_2_disconnected.txt", 1));
    REQUIRE(all_traversals[2] == generateBFS("../data/small_2_disconnected.txt", 2));
    REQUIRE(all_traversals[3] == generateBFS("../data/small_2_disconnected.txt", 3));
    REQUIRE(all_traversals[4] == generateBFS("../data/small_2_disconnected.txt", 4));
    REQUIRE(all_traversals[6] == generateBFS("../data/small_2_disconnected.txt", 6));

    // Building Graph
    Graph g;
    g.BuildGraph("../data/small_2_disconnected.txt");

    // Creating Random BFS using BFS Function
    vector<Vertex> bfs = g.BFS();
    // should contain all the vertices (even disconnected)
    REQUIRE(int(bfs.size()) == g.getSize());
}

TEST_CASE("Small Graph - Multiple BFS Traversal","[algo][BFS]") {
    Graph g;
    g.BuildGraph("../data/small_2_graph.txt");
    vector<Vertex> bfs = g.BFS();
    //Double check that someone doing BFS more than once still returns same thing
    vector<Vertex> bfs2 = g.BFS();
    vector<Vertex> answer = {4, 9, 1, 2, 3};
    REQUIRE(answer == bfs);
    REQUIRE(answer == bfs2);
}

TEST_CASE("Graph from Dataset - BFS Traversal","[algo][BFS]") {
    Graph g;
    g.BuildGraph("../data/686.edges");
    //g.print();
    vector<Vertex> bfs = g.BFS();
    // should contain all the vertices (even disconnected)
    REQUIRE(int(bfs.size()) == g.getSize());
}

/**
 * Tests for PageRank Algo
*/
TEST_CASE("Small Connected PageRank", "[algo][PG]") {
    Graph g;
    g.BuildGraph("../data/small_2_graph.txt");
    vector<Vertex> rank = g.PageRank(10, 1000);
    REQUIRE(rank.at(0) == 9);
    REQUIRE(rank.at(4) == 4);
}

TEST_CASE("Small Disconnected PageRank", "[algo][PG]") {
    Graph g;
    g.BuildGraph("../data/small_disconnected.txt");
    vector<Vertex> rank = g.PageRank(10);
    vector<Vertex> expected = {6,5,4,3,2,1};
    REQUIRE(rank == expected);
}

TEST_CASE("Graph from DataSet test", "[algo][PG]") {
    Graph g;
    g.BuildGraph("../data/686.edges");
    vector<Vertex> rank = g.PageRank(10, 1000);
    vector<Vertex> expected = {828,713,705,719,805,745,747,824,694,823};
    REQUIRE(rank == expected);
}

/**
 * Tests for Betweeness Centrality
*/
TEST_CASE("Small Connected BC", "[algo][BC]") {
    Graph g;
    g.BuildGraph("../data/small_2_graph.txt");
    vector<Vertex> expected = {9, 4, 3, 2, 1};
    g.BetweennessCentrality();
    vector<Vertex> topUsers = g.getTopIDs(5);
    REQUIRE(expected == topUsers);
    REQUIRE(g.getUserBetweennessCentrality(9) == 0.5);
    REQUIRE(g.getUserBetweennessCentrality(1) == 0);
    REQUIRE(g.getUserBetweennessCentrality(2) == 0);
    REQUIRE(g.getUserBetweennessCentrality(3) == 0);
    REQUIRE(g.getUserBetweennessCentrality(4) == 0);
    REQUIRE(g.getUserBetweennessCentrality(420) == -1);
}

TEST_CASE("Small Disconnected BC", "[algo][BC]") {
    Graph g;
    g.BuildGraph("../data/small_disconnected.txt");
    vector<Vertex> expected = {6, 5, 4, 3, 2}; 
    g.BetweennessCentrality();
    vector<Vertex> topUsers = g.getTopIDs(5);
    REQUIRE(expected == topUsers);
    REQUIRE(g.getUserBetweennessCentrality(6) == 0);
    REQUIRE(g.getUserBetweennessCentrality(1) == 0);
    REQUIRE(g.getUserBetweennessCentrality(2) == 0);
    REQUIRE(g.getUserBetweennessCentrality(3) == 0);
    REQUIRE(g.getUserBetweennessCentrality(4) == 0);
    REQUIRE_FALSE(g.getUserBetweennessCentrality(69) == 1);
}

TEST_CASE("Dataset BC", "[algo][BC]") {
    Graph g;
    g.BuildGraph("../data/686.edges");
    vector<Vertex> expected = {828, 713, 705, 719, 805};
    g.BetweennessCentrality();
    vector<Vertex> topUsers = g.getTopIDs(5);
    REQUIRE(expected == topUsers);
    REQUIRE(g.getUserBetweennessCentrality(828) == 9213);
    // rounding to three decimal places
    REQUIRE (round(g.getNormalizedUserBetweennessCentrality(828) * 1000.0)/1000.0 == 0.665);
    REQUIRE(g.getUserBetweennessCentrality(713) == 8686);
    REQUIRE(g.getUserBetweennessCentrality(705) == 7972);
    REQUIRE(g.getUserBetweennessCentrality(719) == 7600);
    REQUIRE(g.getUserBetweennessCentrality(805) == 6537);
    REQUIRE(g.getUserBetweennessCentrality(420) == -1);
}