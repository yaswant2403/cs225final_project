#include <catch2/catch_test_macros.hpp>

#include "Graph.h"
#include "Matrix.h"

/**
 * Test cases for our abstract data types/ classes
 * Tests for Graph & Matrix are here 
*/

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

/**
 * Test Cases for Matrix class 
*/

TEST_CASE("Basic Matrix Construction & functions", "[matrix]") {
    Matrix m(3, 3, 9);
    //m.print();
    REQUIRE(m(0, 0) == 9);
    REQUIRE(m.getCols() == 3);
    REQUIRE(m.getRows() == 3);
}

TEST_CASE("Operator== sanity check", "[matrix]") {
    Matrix A(3, 3, 9);
    Matrix B(3, 3, 9);
    REQUIRE(A == B);
    Matrix C(3, 3, 2);
    REQUIRE_FALSE(A == C);
    Matrix D(3, 1, 9);
    REQUIRE_FALSE(A == D);
    REQUIRE_FALSE(C == D);
}

TEST_CASE("Square Matrix Matrix Multiplication", "[matrix]") {
    Matrix A(2, 2, 2);
    Matrix B(2, 2, 9);
    Matrix C = A * B;
    Matrix D(2, 2, 36);
    REQUIRE(C == D);
}

TEST_CASE("Bad Matrix Multiplication Dimensions", "[matrix]") {
    Matrix A(3, 2, 9);
    Matrix B(9, 3, 9);
    REQUIRE_THROWS(A * B);
}

TEST_CASE("Matrix Vector Multiplication", "[matrix]") {
    Matrix M(3, 3, 9);
    M(0, 0) = 3;
    M(1, 0) = 2;
    M(2, 0) = 1;
    Matrix v(3, 1, 3);
    v(1, 0) = 2;
    v(2, 0) = 1;
    Matrix x(3, 1, 36);
    x(1, 0) = 33;
    x(2, 0) = 30;
    REQUIRE(M * v == x);
}