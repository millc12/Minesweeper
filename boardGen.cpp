#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <iomanip>

using namespace std;
//int x = 10; int y = 10;
class arr {
public:
      /*int row = 10;
      int col = 10;*/
      int mines[10];
int mtrx[10][10];
//    vector<vector<int>> mx;
//arr()  : mx(10, vector<int >(10, 0)) {}
      arr generateBoard();
      arr flagshit(arr board);
};
arr arr::generateBoard() {
      arr board;
      /* int c, r;
      cout << "How many rows? "; cin >> r;
      cout << "How many columns? "; cin >> c;
      board.mx.resize(r, vector<int>(5));*/
      int xRandNum, yRandNum; int i = 0;
      for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                  board.mtrx[x][y] = 0;
            }
      }
      board.mtrx[0][0] = 0;
      board.mtrx[0][1] = 0;
      board.mtrx[1][0] = 0;
      while (i < 12) {
            xRandNum = rand() % 10;
            yRandNum = rand() % 10;
            if (board.mtrx[xRandNum][yRandNum] == 0) {
                  board.mtrx[xRandNum][yRandNum] = 1;
                  i++;
            }
            
            
                  
      }

      return board;
}

arr arr::flagshit(arr board) {
      arr matrix;
      //just to set it to 0
      for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                  matrix.mtrx[x][y] = 0;
            }
      }
      for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                  if (board.mtrx[i][j] == 1) {
                        if (board.mtrx[i+1][j] != 1 && i != 9) {
                              matrix.mtrx[i+1][j]++;
                        }
                        if (board.mtrx[i][j+1] != 1 && j != 9) {
                              matrix.mtrx[i][j+1]++;
                        }
                        if (board.mtrx[i + 1][j+1] != 1 && i != 9 && j != 9) {
                              matrix.mtrx[i+1][j+1]++;
                        }
                        if (board.mtrx[i-1][j] != 1 && i != 0) {
                              matrix.mtrx[i-1][j]++;
                        }
                        if (board.mtrx[i][j-1] != 1 && j != 0) {
                              matrix.mtrx[i][j-1]++;
                        }
                        if (board.mtrx[i-1][j-1] != 1 && i != 0 && j != 0) {
                              matrix.mtrx[i-1][j-1]++;
                        }
                        if (board.mtrx[i+1][j-1] != 1 && i != 9 && j != 0) {
                              matrix.mtrx[i+1][j-1]++;
                        }
                        if (board.mtrx[i-1][j+1] != 1 && i != 0 && j != 9) {
                              matrix.mtrx[i-1][j+1]++;
                        }
                        matrix.mtrx[i][j] = -1;
                  }
            }
      }
      return matrix;
}
