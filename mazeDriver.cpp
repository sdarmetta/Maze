/*mazeDriver.cpp
 *
 * Salvatore D'Armetta
 *
 * Driver program for the class maze
 * asking user for starting position
 * and determining if there is a way out.
 */

#include "maze.h"

int main(){

	Maze m;
	int r, c;

	m.printMaze();

	//user input position	
	cout << "Input Starting Position: "; 
	cin >> r >> c;

	//while input is not valid, keep entering
	while(!m.isValid(r,c)){
		cout << "Not an open position, try again: ";
		cin >> r >> c;
	}

	//if the exit was found
	if(m.escape(r,c))
		cout << "Exit was found!" << endl;
	else
		cout << "Trapped! Exit was not found." << endl;
	
	m.printMaze();

}
