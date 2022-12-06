# CS225 Final Project (Y'ALL)
## Contributors  
Yash Ejjagiri (yse2) \
Afif Shomali (shomali2) \
Lisa Jing Leung (ljleung2) \
Libby Codamon (ecoda2) 

## The link to our final presentation  (add later when we finish video)

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
After this use the follow to make & run the executables: 
```
make main
./main 
```
(Todo: Replace the "make main" above with our actual entry and exectuable later)
