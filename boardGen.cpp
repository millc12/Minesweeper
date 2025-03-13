#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <iomanip>

using namespace std;

class arr {
public:
	/**************************************
	* BB : takes MB to add the numbers(-1 = mine now)
	* MB : 1 = mine; 0 = not - initilizing mines
	* DB : 1 = space dug; 0 = not dug; -1 = flag
	**************************************/
	//int backBoard[10][10];
	vector<vector<int>> backBoard;
	//int frontBoard[10][10];
	vector<vector<int>> mineBoard;
	vector<vector<int>> dugBoard;
	int size;
	int spacesLeft;
	int flags;
	arr() {
		size = 10;
		backBoard.resize(size, vector<int>(size));
		mineBoard.resize(size, vector<int>(size));
		dugBoard.resize(size, vector<int>(size));
		spacesLeft = 88;
		flags = 12;
	}
	arr generateBoard();
	void surrondingSpaces(arr& matrix);
};


arr arr::generateBoard() {
	arr board;

	int xRandNum, yRandNum; int i = 0;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			board.mineBoard[x][y] = 0;
		}
	}
	/*board.mineBoard[0][0] = 0;
	board.mineBoard[0][1] = 0;
	board.mineBoard[1][0] = 0;*/
	while (i < 12) {
		xRandNum = rand() % 10;
		yRandNum = rand() % 10;
		if (board.mineBoard[xRandNum][yRandNum] == 0) {
			board.mineBoard[xRandNum][yRandNum] = 1;
			i++;
		}



	}
	for (int i = 0; i < board.size; i++) {
		for (int j = 0; j < board.size; j++) {
			board.dugBoard[i][j] = 0;
		}
	}
	return board;
}

void arr::surrondingSpaces(arr& matrix) {
	/*arr matrix;
	matrix.generateBoard();*/
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			matrix.backBoard[x][y] = 0;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (matrix.mineBoard[i][j] == 1) {
				if (i < 9 && matrix.mineBoard[i + 1][j] != 1) {
					matrix.backBoard[i + 1][j]++;
				}
				if (j < 9 && matrix.mineBoard[i][j + 1] != 1) {
					matrix.backBoard[i][j + 1]++;
				}
				if (i < 9 && j < 9 && matrix.mineBoard[i + 1][j + 1] != 1) {
					matrix.backBoard[i + 1][j + 1]++;
				}
				if (i > 0 && matrix.mineBoard[i - 1][j] != 1) {
					matrix.backBoard[i - 1][j]++;
				}
				if (j > 0 && matrix.mineBoard[i][j - 1] != 1) {
					matrix.backBoard[i][j - 1]++;
				}
				if (i > 0 && j > 0 && matrix.mineBoard[i - 1][j - 1] != 1) {
					matrix.backBoard[i - 1][j - 1]++;
				}
				if (i < 9 && j > 0 && matrix.mineBoard[i + 1][j - 1] != 1) {
					matrix.backBoard[i + 1][j - 1]++;
				}
				if (i > 0 && j < 9 && matrix.mineBoard[i - 1][j + 1] != 1) {
					matrix.backBoard[i - 1][j + 1]++;
				}
				matrix.backBoard[i][j] = -1;
			}
		}
	}
	//return matrix;
}
