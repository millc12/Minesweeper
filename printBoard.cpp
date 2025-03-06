#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <iomanip>

using namespace std;
void plusdash(); void nums(int r[10], int check[10], bool end);


void print(int b[10][10], int row, int col, int db[10][10], bool end) {
	
	for (int i = 0; i < 10; i++) {
		cout << "\033[30m";
		plusdash();
		
		nums(b[i], db[i], end);
		if (i == 9) {
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

void nums(int check[10], int r[10], bool end) {
	cout << "\033[42m ";
	for (int i = 0; i < 10; i++) {
		int status = r[i];
		cout << "\033[30m| ";
		if (end == false) {
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
