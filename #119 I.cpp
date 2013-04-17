#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

int search(string& maze, int position, int gridSize, int steps){
	if(maze[position] == 'W'){
		return -1;
	}
	if(maze[position] == 'E'){
		return steps + 1;
	}
	maze[position] = 'W';
	int right = search(maze, position + 1, gridSize, steps + 1);	
	int left = search(maze, position - 1, gridSize, steps + 1);
	int up = search(maze, position - gridSize, gridSize, steps + 1);
	int down = search(maze, position + gridSize, gridSize, steps + 1);	
	int leastSteps = 999999;
	if(right != -1 && right < leastSteps)
		leastSteps = right;
	if(left != -1 && left < leastSteps)
		leastSteps = left;
	if(up != -1 && up < leastSteps)
		leastSteps = up;
	if(down != -1 && down < leastSteps)
		leastSteps = down;
	if(leastSteps == 999999)
		return -1;
	return leastSteps;
}

void buildWall(string& input, int gridSize){
	for(int i = 0; i < (gridSize+2); i++){
		input += 'W';
	}
}

void buildMaze(string& input, int gridSize){
	//Make top wall
	buildWall(input, gridSize);	
	for(int i = 0; i < gridSize; i++){
		input += 'W'; //Make left wall
		string tempInput;
		cin >> tempInput;
		input += tempInput;
		input += 'W'; //Make right wall
	}
	//Make bottom wall
	buildWall(input, gridSize);
}

void displayMaze(string& input, int gridSize){
	for(int i = 0; i < gridSize; i++){
		for(int j = 0; j < gridSize; j++){
			int position = (i * gridSize + j);
			cout << input[position];
		}
		cout << endl;
	}
}

int main(void){
	int gridSize;
	cin >> gridSize;
	string input;
	buildMaze(input, gridSize);
	displayMaze(input, gridSize + 2);
	int result = search(input, gridSize + 4, gridSize + 2, 0);
	if(result != -1){
		cout << "True. " << result << "steps." << endl;
	}
	else{
		cout << "False." << endl;
	}
	return 0;
}
