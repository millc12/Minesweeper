#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <iomanip>

using namespace std;

class arr {
public:

	vector<vector<int>> backBoard;

	vector<vector<int>> mineBoard;
	vector<vector<int>> dugBoard;
	int size;
	int spacesLeft;
	int flags;



	arr() {
		backBoard.resize(10, vector<int>(10));
		mineBoard.resize(10, vector<int>(10));
		dugBoard.resize(10, vector<int>(10));
		size = 10;
		spacesLeft = 88;
		flags = 12;
	}
	arr generateBoard();
	void surrondingSpaces(arr& matrix);
};
