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

TEST_CASE("BFS small & multiple") {
    Graph g;
    g.BuildGraph("../data/small_test.txt");
    vector<Vertex> bfs = g.BFS();
    //Double check that someone doing BFS more than once still returns same thing
    vector<Vertex> bfs2 = g.BFS();
    vector<Vertex> answer = {4, 9, 1, 2, 3};
    REQUIRE(answer == bfs);
    REQUIRE(answer == bfs2);
}

TEST_CASE("BFS Disconnected") {
    Graph g;
    g.BuildGraph("../data/disconnected.txt");
    vector<Vertex> bfs = g.BFS();
    vector<Vertex> answer = {6, 5, 4, 3, 2, 1}; 
    REQUIRE(answer == bfs);
}

TEST_CASE("BFS Dataset") {
    Graph g;
    g.BuildGraph("../data/686.edges");
    vector<Vertex> bfs = g.BFS();
    size_t size = g.getSize();
    REQUIRE(bfs.size() == size);
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
    REQUIRE(all_traversals[0] == generateBFS("../data/small_bfs_test.txt", 0));
    REQUIRE(all_traversals[1] == generateBFS("../data/small_bfs_test.txt", 1));
    REQUIRE(all_traversals[2] == generateBFS("../data/small_bfs_test.txt", 2));
    REQUIRE(all_traversals[3] == generateBFS("../data/small_bfs_test.txt", 3));
    REQUIRE(all_traversals[4] == generateBFS("../data/small_bfs_test.txt", 4));

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
    // cout << "Random BFS" << endl;
    // for (auto v : bfs) {
    //     cout << v << " ";
    // }
    int starting_vertex = bfs.at(0);
    // Asserting that random BFS also generates correct traversal
    REQUIRE(bfs == generateBFS("../data/small_bfs_test.txt",starting_vertex));
    REQUIRE(int(bfs.size()) == g.getSize());
}

TEST_CASE("Small Graph Disconnected - BFS Traversal","[algo][BFS]") {
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
    REQUIRE(all_traversals[0] == generateBFS("../data/small_bfs_test_disc.txt", 0));
    REQUIRE(all_traversals[1] == generateBFS("../data/small_bfs_test_disc.txt", 1));
    REQUIRE(all_traversals[2] == generateBFS("../data/small_bfs_test_disc.txt", 2));
    REQUIRE(all_traversals[3] == generateBFS("../data/small_bfs_test_disc.txt", 3));
    REQUIRE(all_traversals[4] == generateBFS("../data/small_bfs_test_disc.txt", 4));
    REQUIRE(all_traversals[6] == generateBFS("../data/small_bfs_test_disc.txt", 6));

    // Building Graph
    Graph g;
    g.BuildGraph("../data/small_bfs_test_disc.txt");
    // g.print();

    // Creating Random BFS using BFS Function
    vector<Vertex> bfs = g.BFS();
    // cout << "Random BFS" << endl;
    // for (auto v : bfs) {
    //     cout << v << " ";
    // }

    // should contain all the vertices (even disconnected)
    REQUIRE(int(bfs.size()) == g.getSize());
}

TEST_CASE("Graph from Dataset - BFS Traversal","[algo][BFS]") {
    Graph g;
    g.BuildGraph("../data/686.edges");
    g.print();
    vector<Vertex> bfs = g.BFS();
    // cout << "Random BFS" << endl;
    // for (auto v : bfs) {
    //     cout << v << " ";
    // }
    // cout << endl;
    // in mp_traversals/tests/tests_part1-4x4.cpp, they only checked small cases
    // in order for us to truly verify this, we'd have to do the traversal by hand
    
    // should contain all the vertices (even disconnected)
    REQUIRE(int(bfs.size()) == g.getSize());
}

/**
 * Tests for PageRank Algo
*/
TEST_CASE("Small Connected PageRank", "[algo][PG]") {
    Graph g;
    g.BuildGraph("../data/small_test.txt");
    list<Vertex> rank = g.PageRank(10, 1000);
    list<Vertex> expected = {9,3,2,1,4};
    REQUIRE(rank == expected);
}

TEST_CASE("Small Disconnected PageRank", "[algo][PG]") {
    Graph g;
    g.BuildGraph("../data/disconnected.txt");
    list<Vertex> rank = g.PageRank(10);
    list<Vertex> expected = {6,5,4,3,2,1};
    REQUIRE(rank == expected);
}

TEST_CASE("Graph from DataSet test", "[algo][PG]") {
    Graph g;
    g.BuildGraph("../data/686.edges");
    list<Vertex> rank = g.PageRank(10, 1000);
    list<Vertex> expected = {828,713,705,719,805,745,747,824,694,823};
    REQUIRE(rank == expected);
}

/**
 * Tests for Betweeness Centrality
*/
TEST_CASE("Small Connected BC", "[algo][BC]") {
    Graph g;
    g.BuildGraph("../data/small_test.txt");
    //g.getBetweennessCentrality(5);
    vector<Vertex> expected = {9, 1, 2, 3, 4}; 
    auto bc = g.BetweennessCentrality();
    for (size_t i = 0; i < expected.size(); ++i) {
        REQUIRE(expected[i] == bc[i].first);
    }
}
TEST_CASE("Small Disconnected BC", "[algo][BC]") {
    Graph g;
    g.BuildGraph("../data/disconnected.txt");
    vector<Vertex> expected = {1, 2, 3, 4, 5}; 
    //g.getBetweennessCentrality(5);
    auto bc = g.BetweennessCentrality();
    for (size_t i = 0; i < expected.size(); ++i) {
        REQUIRE(expected[i] == bc[i].first);
    }
    
}
TEST_CASE("Dataset BC", "[algo][BC]") {
    Graph g;
    g.BuildGraph("../data/686.edges");
    g.getBetweennessCentrality(5);
    vector<Vertex> expected = {828, 713, 705, 719, 805}; 
    auto bc = g.BetweennessCentrality();
    for (size_t i = 0; i < expected.size(); ++i) {
        REQUIRE(expected[i] == bc[i].first);
    }
}