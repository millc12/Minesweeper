#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <iomanip>
#include <queue>   
#include <fstream>
#include "boardGen.h"
#include "printBoard.h"
#include "ms3.h"
#include "intro.h"
#include <conio.h>
using namespace std;

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define DIG 50
#define FLAG 49

#define w_key 119
#define a_key 97
#define s_key 115
#define d_key 100

#define comma 44
#define period 46

void print(arr b, int row, int col, bool end, int r, int c);



//int row, col = board.size;
void endGame(vector<vector<int>> mtrx, int size) {
	cout << "\033[37m\nYou lost!!!!\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
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
	cout << "\033[37mYou win!\n";
}

struct Cell {
	int x, y;
};

// Function to reveal surrounding empty spaces safely
arr digSurrondings(arr board, int i, int j) {
	queue<Cell> q;
	q.push({ i, j });
	board.dugBoard[i][j] = 1; // Mark as visited

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
			if (newX >= 0 && newX < board.size && newY >= 0 && newY < board.size) {
				// If not a mine and not already revealed
				if (board.backBoard[newX][newY] != -1 && board.dugBoard[newX][newY] == 0) {
					board.dugBoard[newX][newY] = 1;  // Mark as visited

					// If it's an empty space, continue digging
					if (board.backBoard[newX][newY] == 0) {
						q.push({ newX, newY });  // Push only once
					}
				}
			}
		}
	}
	for (int x = 0; x < board.size; x++) {
		for (int y = 0; y < board.size; y++) {
			if (board.dugBoard[x][y] != 1 && board.dugBoard[x][y] != -1) {
				board.dugBoard[x][y] = 0;
			}
		}
	}
	return board;
}

class child : public arr {
public: //there are no rules specifying eveyrthing can't be public

};


/*************************************************************/
int main() {
	int exit = 0;
	int r, c;
	srand(static_cast<unsigned int>(time(NULL)));
	display();
	string line;
	ifstream file("instructions.txt");
	do {
		string code = "\033";
		string FAKE = "\\033";
		size_t position = line.find(FAKE);
		while (position != string::npos) {
			line.replace(position, FAKE.length(), code);
			position = line.find(FAKE, position + code.length());
		}
		cout << line << endl;
	} while (getline(file, line));
	file.close();
	arr board = board.generateBoard();
	board.surrondingSpaces(board); 
	r = 0; c = 0;
	//simple move maker
	cout << "Enter 1 to begin: ";
	cin >> exit;
	print(board, board.size, board.size, false, r, c);
	while (exit != 0) {
		int choice;
		cout << "\033[37m ";
		choice = _getch();
		switch (choice) {
		case UP:
			if (r > 0) {
				r--;
				print(board, board.size, board.size, false, r, c);
			}
			break;
		case DOWN:
			if (r < 9) {
				r++;
				print(board, board.size, board.size, false, r, c);
			}
			break;
		case LEFT:
			if (c > 0) {
				c--;
				print(board, board.size, board.size, false, r, c);
			}
			break;
		case RIGHT:
			if (c < 9) {
				c++;
				print(board, board.size, board.size, false, r, c);
			}
			break;
		case FLAG: //*****************************************************
			if (board.flags != 0) {
				if (board.dugBoard[r][c] != -1) {
					board.flags--;
					board.dugBoard[r][c] = -1;
					print(board, board.size, board.size, false, r, c);
				}
				else {
					board.dugBoard[r][c] = 0;
					board.flags++;
					print(board, board.size, board.size, false, r, c);
				}
			}
			else {
				cout << "All availible flags have already been placed\n";
			}
			break;
		case DIG: //*****************************************************
			board.dugBoard[r][c] = 1;
			if (board.backBoard[r][c] == -1) {
				print(board, board.size, board.size, true, r ,c);
				endGame(board.mineBoard, board.size);
				exit = 0;
			}
			else {
				board = digSurrondings(board, r, c);
				print(board, board.size, board.size, false, r, c);
			}

			break;
		default:
			//cout << "error switch statment for flag vs dig" << endl;
			break;
		}
		
		int spacesRemaining = 88;
		for (int xx = 0; xx < board.size; xx++) {
			for (int yy = 0; yy < board.size; yy++) {
				if (board.dugBoard[xx][yy] == 1) {
					spacesRemaining--;
				}
			}
		}
		if (spacesRemaining == 0) {
			exit = 0;
			winGame();
		}
	}


	return 0;
}

