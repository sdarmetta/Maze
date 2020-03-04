/*maze.cpp
 *
 * Salvatore D'Armetta
 *
 * maze source file with constructor and member
 * functions necessary to initialize an object of
 * class maze and search for the exit.
 */

#include "maze.h"

//default constructor
Maze::Maze(){

	int temp[row][col] = {
		{'+','+','+','+','+','+','+'},
		{'+','O','O','+','E','O','+'},
		{'+','O','+','O','O','+','+'},
		{'+','O','O','O','O','+','+'},
		{'+','+','+','O','+','+','+'},
		{'+','+','+','+','+','+','+'}
	};
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			maze[i][j] = temp[i][j];
		}
	}

	exitFound = false;
}

//function to print maze
void Maze::printMaze(){

	cout << "Printing Maze: " << endl << endl;
	
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << maze[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

//function to check if user entered position is valid
bool Maze::isValid(int r, int c){

	bool valid = false;

	if(maze[r][c] == 'O' || maze[r][c] == 'E')
		valid = true;

	return valid;
}

//recursive function to find a way out of the maze
bool Maze::escape(int r, int c){

	//base case
	if(maze[r][c] == 'E'){	

		exitFound = true;
	}
	else{
		if(isValid(r,c)){		//if position is an open position
			maze[r][c] = 'V';	//change to visited
		
			exitFound = escape(r-1,c);	//up
			if(!exitFound)
				exitFound = escape(r,c-1);	//left
			if(!exitFound)
				exitFound = escape(r,c+1);	//right
			if(!exitFound)
				exitFound = escape(r+1,c);	//down
		}
	
	}

	return exitFound;
}			
				

