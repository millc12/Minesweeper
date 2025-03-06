#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <iomanip>
//int x = 10; int y = 10;
struct array {
    //int x;
    int mines[10];
    int arr[10][10];
};
array generateBoard() {
    array board; int xRandNum, yRandNum; int i = 0;
    while(i < 10){
        xRandNum = rand() % 10;
        yRandNum = rand() % 10;
        bool alreadyExists = false;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (board[j][k] == 1) {
                    alreadyExists = true;
                }
            }
        }
        if (alreadyExists == false) {
            board[xRandNum][yRandNum]
            i++;
        }
    }
    return board;
}
