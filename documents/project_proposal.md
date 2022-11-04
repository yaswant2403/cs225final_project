## Project Proposal
## Leading Question 
For this project, we are hoping to produce a general Facebook profile search tool where users are able to input an interest and receive users in that interest pool or other relevant interest groups. If time permits, we would expand upon the project by allowing users to search up a community and return people in those groups/communities (most active, new members, etc). We could also output a visualization of all user profiles in a certain category given a user inputted category (job position, college, company).

## Dataset Acquisition

## Data Format
We will be using the ego-Facebook dataset from Stanford’s Large Network Dataset Collection (http://snap.stanford.edu/data/ego-Facebook.html).This dataset provides friend lists from survey participants so that each survey participant’s network is represented as an undirected graph. Each survey participant is represented as an ego node and there are over 4000 nodes representing their friends. We plan to use a random sample of 1000 participants and their specific features. In addition to this, their features / affiliations are provided, but the interpretation of those features have been obscured. For example, where the original dataset may have contained a feature "political=Democratic Party", the new data would simply contain "political=anonymized feature 1". Thus, it’s still possible to use this anonymized data to determine whether two users have the same political affiliations, but not what their individual political affiliations represent. However, if we want the user to be able to input a certain feature, we will have to label each of the feature ids. For example, the feature education year has an id of 542 and we would give that specific id a value of 1999. This may introduce bias because not all features may be represented within the dataset.

## Data Correction
 
The dataset features 10 people and their respective circles, to keep the size of our graph reasonable we will be picking one person and performing all the algorithms on that network. Due to the anonymized features, we will have to come up with some names for each feature id in order for a user to be able to input from a list of features and find an interest group. We will make sure that each line in our edge list has a starting and ending node, since this is an undirected graph, both nodes will have that edge in their edge list. If a line in the edge list does not have two values, then we won’t use that line as an edge. When building the feature list for a node, we will go through the feature list file & if there is a missing input for a feature, we will treat it as though that node/user doesn’t have that feature. During this stage we will also map each feature id to a string in order for a user to be able to use our program with actual feature names rather than inputting feature ids.

## Data Storage
We will use an undirected & unweighted graph to represent the friend circle. We will create a user class which will act as the nodes for our graph. Each node will have an i.d. and an array of features ( a feature represents an aspect of a user's profile like job, interests, location, etc). We are using an array in order to give each feature a unique id,, and the feature array of a node will contain a 1 or 0 to signify whether a user has that feature or not. For example if a feature “UIUC student” with id 9. Then a 1 in the 8th index of a user’s feature array will indicate they have this feature. We are picking an array over a linked list as it will allow us to access and compare whether users share two features in constant time at the cost of having a large features array. Lastly, we will have a preprocessed mapping of feature names as string to their unique feature id. This will let the user input an actual feature name rather than using an id that doesn’t mean anything. 
	For an estimate of storage, let V be the number of nodes, E be the number of edges and F be the number of features. We need to store all the nodes and edges in addition to F number of features per node. We will also need to store the map of feature names to values, let M represent the space needed for this mapping. So a Big O estimate for storage is:
 O(E + V * F + M)


## Algorithm 
#### 1) Dijisktra’s Algorithm  
###### Function Inputs: 
 The expected inputs for our algorithm would be two user ids. Our dataset currently is given as an adjacency list, however, which nodes are connected to which are already given. Thus, we would build our graphs with these nodes and then find the shortest connection between the two user ids.  

###### Function Outputs:  
The expected output would be in the form of a string displaying the shortest edges that are traveled through to get to the end user-id. If time permits, we would also visualize the shortest connection and generate a PNG.  

###### Function Efficiency:  
The target goal for time complexity would be O((E + V) LogV) where E represents the edges of the graph and V represents the nodes/vertices of the graph. The space complexity goal is O(V) where V denotes the number of nodes in the graph.

####2) Degree Centrality  
###### Function Inputs:   
Degree centrality of a node refers to the number of edges attached to the node. Thus, our inputs would be two user ids and we could compare which user has a higher degree centrality allowing us to determine which user is the most “popular”.  

###### Function Outputs:  
Out outputs will be the number of edges attached to each user, as well which user is most “popular” based on degree centrality.  

###### Function Efficiency:  
The goal time complexity for the degree centrality algorithm is O(V^2) as that’s the runtime of degree centrality for all the nodes in a graph. Ideally, we would want a smaller runtime, as we would only find the degree centrality of two given nodes. The goal space complexity is also O(V^2), where V is all the nodes in the graph. 

#### 3) BFS Traversal
###### Function Input:  
List of Nodes & Edges, If we decide to create a visualization of the friend network, this function would add a nodes & edges between them to the visulization.   
###### Function Ouputs:  
A BFS traversal of our friend graph, and if time permits a visualization of the friend circle.   
###### Function Efficiency:   
The efficiency of this traversal is O( V + E ) where V are the nodes and E are the edges since we need to process all nodes & edges. The space complexity is O (V) since we may need to hold all nodes on a queue at once.

## Timeline
###### Week 1: 10/31 - 11/4: 
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
Finsih other two algorithims
######	Week 5: 12/5 - 12/9:   
 Finalize and organize project deliverables, create Mediaspace video and write up 
