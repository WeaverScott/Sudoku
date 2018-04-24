#include "backtrack1.h"
#include <iostream>

/**********************************************************************
Main function that has the sudoku board we wish to solve.
**********************************************************************/
int main(int argc, char** argv) {

	 int grid[9][9] = {{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },
                  	   { 0, 9, 0, 0, 0, 0, 0, 8, 5 },
                  	   { 5, 0, 0, 0, 8, 0, 4, 0, 0 },
                  	   { 4, 0, 7, 2, 0, 6, 8, 9, 0 },
                  	   { 0, 1, 0, 8, 0, 9, 0, 4, 0 },
                  	   { 0, 8, 9, 5, 0, 1, 3, 0, 2 },
                  	   { 0, 0, 3, 0, 1, 0, 0, 0, 9 },
                  	   { 9, 4, 0, 0, 0, 0, 0, 1, 0 },
                  	   { 0, 7, 0, 0, 0, 0, 0, 3, 0 }
			};

	// if solvable, print the output
	if(solve(grid) == true)
		printGrid(grid);

	return 0;

}
