#ifndef MINEFIELD_H //踩地雷地圖
#define MINEFIELD_H
#include "Cell.h"
#include <vector>

class Minefield 
{
private:
    vector<vector<Cell>> field;
    int rows;//長
    int cols;//寬
    int totalMines;//地雷總數
    int minesRemaining;

public:
    Minefield(int numRows, int numCols, int numMines);
    int countAdjacentMines(int row, int col);
    void openCell(int row, int col);
    void openAdjacentCells(int row, int col);
    void flagCell(int row, int col);
    void printField();
    void checkWin();
    void gameOver();
};

#endif
