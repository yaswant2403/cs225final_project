#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

typedef int Vertex;

/**
 * Graph representation of friend network
*/
class Graph
{
public:
    /**
     * Default Constructor to create an empty graph.
    */
    Graph();

    /**
     * Builds a graph from a file of edges.
     * Format should be two int ids seperated by space per line.
     * @param filename - the path of file from which to build the graph
    */
    void BuildGraph(string filename);

    /**
     * Return adjacency list of a Vertex with passed id
     * @param id - ID of the vertex we want adj list for
     * @return - A std::list of Vertices that the passed Vertex is adj to
     *         - Empty list if Vertex is not connected
     *         - list with -1 if vertex doesn't exist
    */
    list<Vertex> getAdjacencyList (int id);

    /**
     * Check if a vertex with passed id exists
     * @param id - ID of vertex we want to find
    */
    bool vertexExists(int id);
    
    /**
     * Check if an edge between two vertices exists
     * @param id1 - First vertex ID
     * @param id2 - Second vertex ID
     * @return - True or False depending on if there is an edge
     *         - Should Throw error if any of the ids aren't in the graph
    */
    bool edgeExists(int id1, int id2);

    /**
     * Returns the Size of the graph which will be the number of nodes
    */
    int getSize();

    /**
     * Performs BFS traversal of the graph
     * @returns - vector of Vertices in BFS order
    */
    list<Vertex> BFS();
    /**
     * Performs PageRank on our graph to see who the "most important/popular" person is
     * @param num_places -How many places of rankings to return (eg top 5, 10, etc), default is top 10
     * @return -List of size num_places with the top num_places vertices in the graph according to PageRank
    */
    list<Vertex> PageRank(int num_places = 10);

    /**
     * Performs BetweenessCentrality on our Graph
    */
    int BetweennessCentrality();

    /**
     * Adds a vertex to the graph
    */
    void AddVertex(int id);

    /**
     * Adds an edge between two vertices
    */
    void AddEdge(int id1, int id2);
    
    //uncomment this below if we do a visual output, we would also need to add 
    //225 PNG class/ add a lib folder with all the 225 stuff
    //PNG DrawGraph();

private:
    // If our graph becomes too big to store on stack, we can make this into a pointer
    mutable unordered_map<Vertex, list<Vertex>> *adj_list;
    // Size of graph/number of vertices
    int size;

};
