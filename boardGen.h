#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <iomanip>


class arr {
public:
	int mines[10];
	int mtrx[10][10];
	arr generateBoard();
	arr flagshit(arr board);
};
