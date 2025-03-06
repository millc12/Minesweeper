#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <iomanip>
#include <queue>   
#include "boardGen.h"
#include "printBoard.h"
#include "minesweeper.h"
#include "intro.h"
using namespace std;


void print(int b[10][10], int row, int col, int db[10][10], bool end);


int row, col = 10;
void endGame(int mtrx[10][10]) {
	cout << "\033[37m\nYou lost!!!!\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (mtrx[i][j] == 1) {
				cout << "\033[41m";
			}
			
			cout << mtrx[i][j] << "\033[40m ";
		}
		cout << endl;
	}

	cout << "\033[40m";

}

void winGame() {
	cout << "You win!\n";
}

struct Cell {
	int x, y;
};

// Function to reveal surrounding empty spaces safely
arr digSurrondings(arr board, arr uM, int i, int j) {
	std::queue<Cell> q;
	q.push({ i, j });
	uM.mtrx[i][j] = 1; // Mark as visited

	// Direction vectors for 8 adjacent cells
	int dx[] = { -1, -1, -1,  0,  0,  1, 1, 1 };
	int dy[] = { -1,  0,  1, -1,  1, -1, 0, 1 };

	while (!q.empty()) {
		Cell current = q.front();
		q.pop();

		for (int d = 0; d < 8; d++) {
			int newX = current.x + dx[d];
			int newY = current.y + dy[d];

			// Check bounds
			if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10) {
				// If not a mine and not already revealed
				if (board.mtrx[newX][newY] != -1 && uM.mtrx[newX][newY] == 0) {
					uM.mtrx[newX][newY] = 1; // Mark as visited

					// If it's an empty space, continue digging
					if (board.mtrx[newX][newY] == 0) {
						q.push({ newX, newY });
					}
				}
			}
		}
	}  

	return uM;
}


/*************************************************************/
int main() {
	
	srand(static_cast<unsigned int>(time(NULL)));
	display();
	arr gottem = gottem.generateBoard();
	gottem.mtrx[0][0] = 1;
	arr flaggem = flaggem.flagshit(gottem);
	//int board[10][10];//gotta assign it one by one for some god damn reason
	int spacesRemaining = 88;
	int flags = 12;
	int exit = 1; int r, c;
	arr uncovered;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			uncovered.mtrx[i][j] = 0;
		}
	}
	//simple move maker
	while (exit != 0) {
		int choice;
		cout << "\033[37m ";
		cout << "Flag(1) or Dig(2): "; cin >> choice;
		cout << "Row: ";
		cin >> r;
		cout << "Column: ";
		cin >> c;
		r--;
		c--;
		switch (choice) {
		case 1:
			if (flags != 0) {
				flags--;
				uncovered.mtrx[r][c] = -1;
				print(flaggem.mtrx, 10, 10, uncovered.mtrx, false);
			}
			else {
				cout << "All availible flags have already been placed\n";
			}
			break;
		case 2:
			
			uncovered.mtrx[r][c] = 1;
			if (flaggem.mtrx[r][c] == -1) {
				print(flaggem.mtrx, 10, 10, uncovered.mtrx, true);
				endGame(gottem.mtrx);
				exit = 0;
			}
			else {
				spacesRemaining--;
				uncovered = digSurrondings(flaggem, uncovered, r, c);
				print(flaggem.mtrx, 10, 10, uncovered.mtrx, false);
			}

			break;
		default:

			break;
		}
		if (spacesRemaining == 0) {
			exit = 0;
			winGame();
		}
	}
	

	return 0;
}

