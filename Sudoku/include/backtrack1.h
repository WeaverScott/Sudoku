#include <iostream>

#define N 9
#define UNASSIGNED 0

/**********************************************************************
Method used to find unassigned cells on the sudoku board.
Returns true if the cell is empty and false if already assigned.
**********************************************************************/
bool findEmptyCell(int grid[N][N], int &row, int &col) {
	
	for (row = 0; row < N; row++) {
		for (col = 0; col < N; col++) {
			if(grid[row][col] == UNASSIGNED) {
				return true;
			}
		}
	}
	return false;
}

/**********************************************************************
Method used to determine if the given num is used in the given row.
Returns true if the row contains the given num and false if not.
**********************************************************************/
bool usedInRow(int grid[N][N], int row, int num) {

	for (int col = 0; col < N; col++) {
		if(grid[row][col] == num) {
			return true;
		}
	}
	return false;
}

/**********************************************************************
Method used to determine if the given num is used in the given col.
Returns true if the col contians the given num and false if not.
**********************************************************************/
bool usedInCol(int grid[N][N], int col, int num) {

	for (int row = 0; row < N; row++) {
		if(grid[row][col] == num) {
			return true;
		}
	}
	return false;
}

/**********************************************************************
Method used to determine if a given num  is used within a 3x3 square.
Returns true if found and false if not.
**********************************************************************/
bool usedInSquare(int grid[N][N], int startRow, int startCol, int num) {
	
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if(grid[row+startRow][col+startCol] == num) {
				return true;
			}
		}
	}
	return false;
}

/**********************************************************************
Method used to determine if the given num can be assigned for the row
and col.
**********************************************************************/
bool isSafe(int grid[N][N], int row, int col, int num) {
	
	return !usedInRow(grid, row, num) && !usedInCol(grid, col, num)
	&& !usedInSquare(grid, row - row % 3, col - col % 3, num);
}

/**********************************************************************
Function that prints out the solved sudoku board
**********************************************************************/
void printGrid(int grid[N][N]) {
	
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			printf("%2d", grid[row][col]);
		}
		printf("\n");
	}	
}

/**********************************************************************
Method that performs the backtracking that is necessary in order to 
solve the sudoku board.
**********************************************************************/
bool solve(int grid[N][N]) {
	
	int row;
	int col;

	if(!findEmptyCell(grid, row, col)) {
		return true;
	}
	for (int num = 1; num <= 9; num++) {
		if(isSafe(grid, row, col, num)) {
			grid[row][col] = num;

			if(solve(grid)) {
				return true;
			}
			grid[row][col] = UNASSIGNED;
		}
	}
	return false;
}
