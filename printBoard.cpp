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
void plusdash(); void nums(vector <int>check, vector<int> r, bool end, int row, int col, int secondNum);




void print(arr b, int row, int col, bool end, int r, int c) {
	/*for (int abc = 0; abc < 50; abc++) {
		cout << endl;
	}*/
	system("cls");
	cout << "   ";
	for (int ii = 1; ii <= 10; ii++) {
		cout << "   " << ii << "";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << "\033[30m";
		cout << "\033[40m\033[37m";
		cout << "   ";
		cout << "\033[30m\033[42m";

		plusdash();
		cout << "\033[40m\033[37m";
		if (i != 9) {
			cout << " " << i + 1 << " ";
		}
		else {
			cout << i + 1 << " ";

		}
		cout << "\033[30m\033[42m";

		nums(b.backBoard[i], b.dugBoard[i], end, r, c, i);
		if (i == 9) {
			cout << "\033[40m\033[37m";
			cout << "   ";
			cout << "\033[30m\033[42m";
			plusdash();
		}


	}


}

void plusdash() {
	int xi = 0;
	cout << "\033[42m ";
	while (xi <= 10) {
		if (xi == 10) {
			cout << "+ ";
		}
		else {
			cout << "+ - ";
		}

		xi++;
	}
	cout << "\033[40m";
	cout << endl;
}

void nums(vector<int> check, vector<int> r, bool end, int row, int col, int secondNum) {

	cout << "\033[42m ";
	for (int i = 0; i < 10; i++) {
		int status = r[i];
		cout << "\033[30m| ";
		if (end == false) {
			if (secondNum == row && i == col) {
				cout << "\033[46m";
			}
			switch (status) {
			case 1:
				if (check[i] != -1 && end == true) {

					cout << "\033[41m \033[40m ";
				}
				else if (check[i] != -1) {
					printf("\033[37m%d ", check[i]);

				}
				else {
					cout << "  ";
				}
				break;
			case 0:
				cout << "  ";
				break;

			case -1:
				cout << "\033[31m< ";
				break;

			default:
				break;
			}

			cout << "\033[42m";





		}
		else { //if end is true
			if (check[i] == -1) {
				cout << "\033[41m\033[37m!\033[42m\033[30m ";
			}
			else if (r[i] == 1) {
				printf("\033[37m%d ", check[i]);
			}
			else if (r[i] == -1) {
				cout << "\033[31m< ";
			}
			else {
				cout << "  ";
			}
		}
		if (i == 9) {
			cout << "\033[30m| ";
		}
	}
	cout << "\033[40m";
	cout << endl;
}
