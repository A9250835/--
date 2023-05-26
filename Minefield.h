#ifndef MINEFIELD_H
#define MINEFIELD_H
#include "Cell.h"
#include <vector>

class Minefield
{
private:
    vector<vector<Cell>> field;
    int rows;
    int cols;
    int totalMines;//總共有幾顆炸彈
    int minesRemaining;//剩餘炸彈數量

public:
    Minefield(int numRows, int numCols, int numMines);
    int countAdjacentMines(int row, int col);
    void checkOpenCell(int row, int col, bool& s);
    void openAdjacentCells(int row, int col);
    void flagCell(int row, int col);
    void cencleFlagCell(int row, int col);
    void printField();
    void checkWin(bool& index);
    void gameOver(bool& index);
};

#endif
