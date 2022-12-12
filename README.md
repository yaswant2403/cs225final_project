# CS225 Final Project (Y'ALL)
## Contributors  
Yash Ejjagiri (yse2) \
Afif Shomali (shomali2) \
Lisa Jing Leung (ljleung2) \
Libby Codamon (ecoda2) 

## [The link to our final presentation](https://mediaspace.illinois.edu/media/t/1_l5or08r0)

## [Written Final Report link](https://github.com/yaswant2403/facebook_famous/blob/main/results.md)

## Repo Structure
Team Contract, Proposal, Weekly Logs & Written Report can be found in [`documents/`](https://github.com/yaswant2403/facebook_famous/tree/main/documents)  
The dataset & testing data is stored as text files are stored in [`data/`](https://github.com/yaswant2403/facebook_famous/tree/main/data)   
The tests are stored in [`tests/`](https://github.com/yaswant2403/facebook_famous/tree/main/tests)  
All source code files are stored in [`src/`](https://github.com/yaswant2403/facebook_famous/tree/main/src)  
The entry point source files are stored in [`entry/`](https://github.com/yaswant2403/facebook_famous/tree/main/entry)  


## Running code 

First open the CS225 docker enviorment, and clone the repository locally by running this in the terminal:
```
git clone https://github.com/yaswant2403/facebook_famous.git
```
Then cd into the repository, create a build directory & cd into it:
```
mkdir build 
cd build
```
Then to initialize the build directory run: 
```
cmake ..  
```
Then run the command below to make all the executables:
```
make
```
Or run make on the individual executables:
```
make BFS
make PageRank
make BC
make test
make main
```
#### Here are the ways to run the programs:  
If you want to use your own file to build a graph, you need to feed the programs an edge list text file. Take a look at our data folder for examples of edge list text files. Each line contatins an edge and each edge is two `int` node ids seperated by a comma.  

##### For `Search a specific profile ID` run:
#### Note: This automatically uses the default file which is `../data/686.edges`
```
./main
```
Input a valid user ID and and it will return their ranking according to BC and PageRank.

##### For `Betweenness Centrality` run:
```
./BC [filename] [num_places]
```
Where `filename` is a string path to your file, for example `../data/686.edges`  
and `num_places` is an int for how many top nodes you want displayed 

##### For `BFS` run:  
```
./BFS [filename]
```
Where `filename` is a string path to your file, for example `../data/686.edges`  

##### For `PageRank` run:
```
./PageRank [filename] [num_places]
```
Where `filename` is a string path to your file, for example `../data/686.edges`  
and `num_places` is an int for how many top nodes you want displayed  

##### For `Betweenness Centrality` run:
```
./BC [filename] [num_places]
```
Where `filename` is a string path to your file, for example `../data/686.edges`  
and `num_places` is an int for how many top nodes you want displayed  

#### For `Test` just run:
```
./test
```


