# CS225 Final Project (Y'ALL)
## Contributors  
Yash Ejjagiri (yse2) \
Afif Shomali (shomali2) \
Lisa Jing Leung (ljleung2) \
Libby Codamon (ecoda2) 

## The link to our final presentation  (add later when we finish video)

## Insert link to final report

## Repo Structure
Team Contract, Proposal, Weekly Logs & Written Report can be found in [`documents/`](https://github.com/yaswant2403/cs225final_project/tree/main/documents)  
The dataset & testing data is stored as text files are stored in [`data/`](https://github.com/yaswant2403/cs225final_project/tree/main/data)   
The tests are stored in [`tests/`](https://github.com/yaswant2403/cs225final_project/tree/main/tests)  
All source code files are stored in [`src/`](https://github.com/yaswant2403/cs225final_project/tree/main/src)  
The entry point source files are stored in [`entry/`](https://github.com/yaswant2403/cs225final_project/tree/main/entry)  


## Running code 

First open the CS225 docker enviorment, and clone the repository locally by running this in the terminal:
```
git clone https://github.com/yaswant2403/cs225final_project.git
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
```
#### Here are the ways to run the programs:  

For `PageRank` run:
```
./PageRank [filename] [num_places]
```
Where `filename` is a string path to your file, for example `../data/686.edges`  
and `num_places` is an int for how many top nodes you want displayed  


For `Betweenness Centrality` run:
```
./BC [filename] [num_places]
```
Where `filename` is a string path to your file, for example `../data/686.edges`  
and `num_places` is an int for how many top nodes you want displayed  

(Todo: Add the rest of our demonstration files & how to correcty run them)
