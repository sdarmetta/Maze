/*maze.h
 *
 * Salvatore D'Armetta
 *
 * header file for the class maze which instantiates
 * an object containing a pre-fixed maze.
 */

#include<iostream>
using namespace std;

class Maze{

public:
	
	//default constructor
	Maze();
	
	void printMaze();	//function to print maze

	bool isValid(int r, int c);	//function to check if position entered is valid
	bool escape(int r, int c);	//recursive function to find way out of maze


private:

	//private data members
	static const int row = 6;
	static const int col = 7;
	char maze[row][col];
	bool exitFound;
};
