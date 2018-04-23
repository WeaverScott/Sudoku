#include <iostream>

#define N 9
#define UNASSIGNED 0

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

bool usedInRow(int grid[N][N], int row, int num) {

	for (int col = 0; col < N; col++) {
		if(grid[row][col] == num) {
			return true;
		}
	}
	return false;
}

bool usedInCol(int grid[N][N], int col, int num) {

	for (int row = 0; row < N; row++) {
		if(grid[row][col] == num) {
			return true;
		}
	}
	return false;
}

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

bool isSafe(int grid[N][N], int row, int col, int num) {
	
	return !usedInRow(grid, row, num) && !usedInCol(grid, col, num) && !usedInSquare(grid, row - row % 3, col - col % 3, num);
}

void printGrid(int grid[N][N]) {
	
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			printf("%2d", grid[row][col]);
		}
		printf("\n");
	}	
}

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
