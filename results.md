# Y’ALL Final Results - Written Report:

## ADT Implementation:

To implement this project, we created a Graph class to handle creating graphs and the algorithms: BFS, PageRank, and Betweenness Centrality. We also implemented a Matrix class to make the PageRank algorithm simpler to implement, as we did not have access to a linear algebra library. 

## Algorithms:

### BFS:
Our Breadth First Search, BFS, algorithm traversal runs correctly and works on our larger dataset of Facebook profiles. Our BFS algorithm traverses through the friend network dataset to find connected components of the graph, and correctly searches the data structure using a first in-first out queue. To ensure BFS worked correctly, we made a few smaller test case graphs, including ones that have multiple connected components. 
Example Result:
```
Here is the BFS traversal order of this social network graph: 
4 9 1 2 3 

```
### PageRank: 
Our PageRank works correctly, and runs in a reasonable amount of time for our entire dataset. Similar to the original PageRank algorithm used by Google Search to rank web pages in their search engine results, we were able to measure the importance of Facebook friends within a network dataset by using an analysis algorithm that assigns a weight to each element. To test the PageRank algorithm we made a few smaller example graphs, including ones with multiple connected components and checked the results against the same Algorithm implemented in python. 
Example Result:
```
Here are the top 5 ranked users in this social network graph:
1: User with I.D. 828
2: User with I.D. 713
3: User with I.D. 705
4: User with I.D. 719
5: User with I.D. 805
```

### Betweenness Centrality:
Our Betweenness Centrality mostly works correctly, and runs in a reasonable amount of time for our dataset. Our runtime is Ө(n3), which is currently the fastest known time for this algorithm. The runtime we listed in the proposal is based on Brande’s Centrality (a faster way to implement Degree Centrality). Using our Betweenness Centrality algorithm, we were able to correctly measure the centrality of each node in a graph based on the total number of shortest path between Facebook profiles. More specifically, Betweenness Centrality represents the percentage of shortest paths of all pairs in the network that a user is a part of. The percentage is calculated through this formula:

(N-1)(N-2)/2 * total number of shortest paths that the current node is a part of.
(where N is number of nodes in Graph)

Nodes with higher betweenness centrality have more control and higher importance over the network of Facebook profiles, as more information passes through those nodes. To test our Betweenness Centrality algorithm, we wrote test cases for smaller graphs and then used Python with the networkX module for testing on our dataset.


Example Result:
```
Here is the Betweenness Centrality ranking of our dataset:
1:  User with ID - 828,  BC Value: 9213,  As Percentage: 66.4671%
2:  User with ID - 713,  BC Value: 8686,  As Percentage: 62.665%
3:  User with ID - 705,  BC Value: 7972,  As Percentage: 57.5139%
4:  User with ID - 719,  BC Value: 7600,  As Percentage: 54.8301%
5:  User with ID - 805,  BC Value: 6537,  As Percentage: 47.1611%

```
	
## Leading Question:

Is it possible to produce a Facebook profile search tool where users can input a user profile and receive their importance within the Facebook network? 

Yes, as a team we were able to create algorithms using Breadth First Search, PageRank, and Betweenness Centrality to create a tool that helps search for Facebook users of highest importance. We define importance as the amount of social connections that a user has. Thus, the more important a user, the more information flows through them. We were able to successfully measure this popularity through node importance using PageRank, display the percentage of how many connections the user is integral to using Betweenness Centrality, and traverse through our dataset using BFS. We discovered that a combination of these three types of algorithms can ultimately produce a profile search tool for finding Facebook profiles of high importance on a dataset.
