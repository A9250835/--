//
//  Minefield.cpp
//  踩地雷
//
//  Created by Gary on 2023/5/25.
//

#include "Minefield.h"

Minefield::Minefield(int numRows, int numCols, int numMines) {
    rows = numRows;
    cols = numCols;
    totalMines = numMines;
    minesRemaining = numMines;

    field.resize(rows, vector<Cell>(cols));//設置地圖大小為rows*cols
    

    // 隨機放置地雷
    srand(time(NULL));
    int count = 0;
    while (count < totalMines) {
        int row = rand() % rows;
        int col = rand() % cols;

        if (!field[row][col].hasMine()) {
            field[row][col].setMine();
            count++;
        }
    }

    // 計算每個格子周圍的地雷數量
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
        {
            int count = countAdjacentMines(i, j);
            field[i][j].setAdjacentMines(count);
        }
    }
}
//查看以(row,col)為中心點的九宮格有幾顆炸彈
int Minefield::countAdjacentMines(int row, int col)
{
    int count = 0;
    for (int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            int newRow = i;
            int newCol = j;

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                if (field[newRow][newCol].hasMine())
                {
                    count++;
                }
            }
        }
    }
    return count;
}
//檢查此格子狀態，以及該格子是否超出範圍
void Minefield::checkOpenCell(int row, int col , bool &s)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols)
        cout << "座標超出範圍！" << endl;


    Cell& cell = field[row][col];

    if (cell.isCellOpened())
        cout << "該座標已經被打開！" << endl;
    
    cell.openCell();//打開格子

    if (cell.hasMine())//是否有炸彈
        gameOver(s);

    if (cell.getAdjacentMines() == 0)
        openAdjacentCells(row, col);
    

    checkWin(s);
}
/*如果該座標沒有地雷, 程式會印出該座標點四周八格有幾個地雷, 如果該座標點四週八格沒有地雷,
程式會把四週八格一一打開, 並且進一步印出該座標點四周八格有幾個地雷*/
void Minefield::openAdjacentCells(int row, int col)
{
    for (int i = row-1; i <= row+1; i++)
    {
        for (int j = col-1; j <= col+1; j++)
        {
            int newRow = i;
            int newCol = j;
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols)
            {
                Cell& cell = field[newRow][newCol];
                if (!cell.isCellOpened())
                {
                    cell.openCell();
                    if (cell.getAdjacentMines() == 0) {
                        openAdjacentCells(newRow, newCol);
                    }
                }
            }
        }
    }
}
//插旗子
void Minefield::flagCell(int row, int col)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols)
        cout << "座標超出範圍！" << endl;

    Cell& cell = field[row][col];

    if (cell.isCellOpened())
        cout << "該座標已經被打開！" << endl;

    if (!cell.isFlaggedCell())
    {
        cell.setFlag();
        if(field[row][col].hasMine())//如果插上去是炸彈，炸彈-1
            minesRemaining--;
    }
    
}
//取消插旗子
void Minefield::cencleFlagCell(int row, int col)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols)
        cout << "座標超出範圍！" << endl;

    Cell& cell = field[row][col];

    if (cell.isFlaggedCell())
        cell.takeFlag();

}
//印出地圖，以及剩餘炸彈數量
void Minefield::printField() {
    cout << "剩餘地雷數量: " << minesRemaining << endl;
    cout << "  ";
    for (int j = 0; j < cols; j++) {
        if (j < 9)
            cout << "0" << j+1 << " ";
        else
            cout << j+1 << " ";
    }
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        if (i < 9)
            cout << "0" << i+1 << " ";
        else
            cout << i + 1 << " ";

        for (int j = 0; j < cols; j++)
        {
            Cell& cell = field[i][j];
            if (cell.isCellOpened())
            {
                if (cell.hasMine())
                    cout << "*  ";
                else
                {
                    int adjacentMines = cell.getAdjacentMines();
                    if (adjacentMines > 0)
                        cout << adjacentMines << "  ";
                    else
                        cout << "0  ";
                }
            }
            else if(cell.isFlaggedCell())
                cout << "F  ";
            else
                cout << ".  ";
             
        }
        cout << endl;
    }
}
//檢查是否贏得遊戲
void Minefield::checkWin(bool &index) {
    int openedCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (field[i][j].isCellOpened()) {
                openedCount++;
            }
        }
    }
    if (openedCount == rows * cols - totalMines)
    {
        cout << "恭喜你贏得了遊戲！" << endl;
        index = false;
    }
}
//檢查是否輸掉遊戲
void Minefield::gameOver(bool &index) {
    cout << "你踩到地雷，遊戲結束！" << endl;
    // 印出所有格子的狀態
    printField();
    index = false;
}
