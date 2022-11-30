#include <catch2/catch_test_macros.hpp>

#include "Graph.h"


TEST_CASE("BuildGraph Small") {
    Graph g;
    g.BuildGraph("../data/small_test.txt");
    //g.print();
    REQUIRE(g.vertexExists(1));
    REQUIRE(g.vertexExists(2));
    REQUIRE(g.vertexExists(3));
    REQUIRE(g.vertexExists(4));
    REQUIRE(g.vertexExists(9));
} 

TEST_CASE("BuildGraph Disconnected") {
    Graph g;
    g.BuildGraph("../data/disconnected.txt");
    //g.print();
    REQUIRE(g.vertexExists(1));
    REQUIRE(g.vertexExists(2));
    REQUIRE(g.vertexExists(3));
    REQUIRE(g.vertexExists(4));
    REQUIRE(g.vertexExists(5));
    REQUIRE(g.vertexExists(6));

    REQUIRE_FALSE(g.edgeExists(4, 1));
    REQUIRE_FALSE(g.edgeExists(4, 2));
    REQUIRE_FALSE(g.edgeExists(4, 3));
    REQUIRE_FALSE(g.edgeExists(5, 1));
    REQUIRE_FALSE(g.edgeExists(5, 2));
    REQUIRE_FALSE(g.edgeExists(5, 3));
    REQUIRE_FALSE(g.edgeExists(6, 1));
    REQUIRE_FALSE(g.edgeExists(6, 2));
    REQUIRE_FALSE(g.edgeExists(6, 3));
}

TEST_CASE("Build Graph Dataset") {
    Graph g;
    g.BuildGraph("../data/686.edges");
    REQUIRE(g.getSize() == 168);
    REQUIRE(g.edgeExists(830, 819));
    REQUIRE(g.edgeExists(819, 830));
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

