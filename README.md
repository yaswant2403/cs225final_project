# CS225 Final Project (Y'ALL)
## Contributors  
Yash Ejjagiri (yse2) \
Afif Shomali (shomali2) \
Lisa Jing Leung (ljleung2) \
Libby Codamon (ecoda2) 

## The link to our final presentation is (add later when we finish video)

## Repo Structure
Team Contract, Proposal, Weekly Logs & Written Report can be found in [`documents/`](https://github.com/yaswant2403/cs225final_project/tree/main/documents)  
The dataset & testing data is stored as text files are stored in [`data/`](https://github.com/yaswant2403/cs225final_project/tree/main/data)   
The tests are stored in [`tests/`](https://github.com/yaswant2403/cs225final_project/tree/main/tests)  
All source code files are stored in [`src/`](https://github.com/yaswant2403/cs225final_project/tree/main/src)  
The entry point source files are stored in [`entry/`](https://github.com/yaswant2403/cs225final_project/tree/main/entry)  


## Running code 

First open the CS225 docker enviorment, and clone the repository locally:
```
git clone https://github.com/yaswant2403/cs225final_project.git
```
Then cd into the repository & create a build directory:
```
mkdir build 
cd build
```
To create a build directory, then run: 
```
cmake ..  
```
To initialize cmake, after this you can run: 
```
make main
./main 
```
(Todo: Replace the "make main" above with our actual entry and exectuable later)
