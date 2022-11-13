## Leading Question 
For this project, we are hoping to produce a Facebook profile search tool where users can input a user profile and receive their importance within the Facebook network. We define importance as the amount of social connections that a user has. Thus, the more important a user, the more information flows through them. We will use two measures of popularity to show this, in particular, a rank of how important the user is in the network as well as a percentage of how many connections the user is integral to in the network. With enough time, we also hope to output a visualization of all user profiles and how they’re connected to each other within the Facebook egocentric network. 
 
## Dataset Acquisition
 
## Data Format
We will be using the ego-Facebook dataset from Stanford’s Large Network Dataset Collection (http://snap.stanford.edu/data/ego-Facebook.html).This dataset provides friend lists from survey participants so that each survey participant’s network is represented as an undirected graph. Each survey participant is represented as an ego node and there are over 4000 nodes representing their friends. We plan to use a random sample of ~1000 participants. 
## Data Correction
 
The dataset features 10 people and their respective circles, to keep the size of our graph reasonable we will be picking one person and performing all the algorithms on that network. To ensure the data is correct, we will check the text file with all the edges to ensure that there is no missing edge/incorrect edge. For example if a line only has one user id listed instead of 2, we will ignore that line. Since this is an undirected graph, we will add to the adjacency lists of both the edges listed in a given line.
 
## Data Storage
We will use an undirected & unweighted graph to represent the friend circle. We will create a user class which will act as the nodes for our graph. Each node will have an i.d to differentiate between each user. An edge between users signifies that the two users have friendship. We will use an adjacency list for our graph implementation as this simplifies things and lets us add a node (user) more easily to the graph. This method implementation is better storage wise since we don’t need to allocate space for edges that don’t exist like in an adjacency matrix.
	For an estimate of storage, let V be the number of nodes and E be the number of edges. We need to store an user i.d. for each node and an adjacency list for each of these nodes . So, a Big O estimate for storage is:
 O(V + E)
 
 
## Algorithm 
#### 1) PageRank Algorithm  
######Function Inputs: 
 The expected input for our algorithm would be all users. The PageRank algorithm can be used to rank nodes from most to least important, as it was originally created to rank webpages from most to least important. Thus, in this case, we can use the PageRank algorithm to rank users from most to least important, and specifically to give one user information about their importance within the network. 
######Function Outputs:  
The expected output would be in the form of a list of userIds sorted from most to least important according to the PageRank algorithm. Based on this list, we could also implement features so that users can input one userID and receive back that user’s rank within their network, or that users could see the top 10 most important users. 
 
######Function Efficiency:  
The target goal for time complexity would be O(n^2 + cn^3), where n is the number of nodes, & c is the number of iterations, using Big-O this simplifies to O(n^3), we dropped the c since we have set a constant upper limit on the number of iterations. Building the Markov(or Google Matrix) for page rank takes O(n^2) time since we need to go through each node and then check how many nodes it is adjacent to to build one column of the matrix. for each iteration we use matrix multiplication which has a Big-O run time of O(n^3). 

We will choose to iterate ~20 times or until the change between iterations is negligible(We can use can use the 2 norm of the difference between the initial and updated state vector for each iteration & when this value is below a certain tolerance we can stop the iteratons since we have reached a steady state). Our estimated space complexity goal is O(E), where e denotes the number of edges in the graph.
 
####2) Betweenness Centrality  
######Function Inputs:   
Betweenness centrality of a node refers to the number of times a node is in the shortest path between other nodes, as a measure of how important one user may be to other users’ connections with other users. Thus, our inputs would be one user ID, to see the centrality of this one user to the whole network. 
######Function Outputs:  
Our output will include the betweenness centrality value of the given node in the form of a percentage. This value is calculated by finding all of the shortest paths between two nodes and then finding which percent of those are required to pass through the given node. This can also give a sense of how “popular” the given user is as a high value means that they are aware and connected to multiple social networks. 
######Function Efficiency:  
The goal time complexity for the degree centrality algorithm is O(V*E + V^2 log V), where V is the number of vertices or users in the graph, and E is the number of edges or relationships in the graph. The goal space complexity is also O(V+E). 
 
#### 3) BFS Traversal
######Function Input:  
List of Nodes & Edges, If we decide to create a visualization of the friend network, this function would add nodes & edges between them to the visualization.   
######Function Outputs:  
A BFS traversal of our friend graph, and if time permits a visualization of the friend circle.   
######Function Efficiency:   
The efficiency of this traversal is O( V + E ) where V are the nodes and E are the edges since we need to process all nodes & edges. The space complexity is O (V) since we may need to hold all nodes on a queue at once.
 
## Timeline
######Week 1: 10/31 - 11/4: 
Project Planning: finish and submit project proposal by November 4th  
######	Week 2: 11/7 - 11/11:   
Data acquisition and data processing: 
	obtain and choose files for subset of data to be used for project, 
	correct and finalize data, organize data into data structure.    
######	Week 3: 11/14 - 11/18:  
Finish first algorithm, create tests for proposed algorithms  
######	BREAK: 11/19 - 11/27: 
(catch up if needed)  
######	Week 4: 11/28 -  12/2:  
Finish other two algorithms
######	Week 5: 12/5 - 12/9:   
 Finalize and organize project deliverables, create Mediaspace video and write up 
