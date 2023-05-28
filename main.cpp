//
//  main.cpp
//  踩地雷
//
//  Created by Gary on 2023/5/25.
//
#include "Minefield.h"
#include "GameMenu.h"

int main() {
    GameMenu gameMenu;
    gameMenu.gameInterface();


    int numRows = gameMenu.getNumRows();
    int numCols = gameMenu.getNumCols();
    int numMines = gameMenu.getNumMines();

    Minefield game(numRows, numCols, numMines);

    int command, row, col;
    bool i = true;
    
    while (i == true)
    {
        game.printField();

        cout << "請輸入指令（1: 打開格子，2: 標示地雷，3: 取消標記，4: 重新開始):";
        cin >> command;
        if (command == 4)
        {
            gameMenu.gameInterface();
            int numRows = gameMenu.getNumRows();
            int numCols = gameMenu.getNumCols();
            int numMines = gameMenu.getNumMines();
            Minefield game(numRows, numCols, numMines);
            game.printField();
            cout << "請輸入指令（1: 打開格子，2: 標示地雷，3: 取消標記，4: 重新開始):";
            cin >> command;
        }

        cout << "請輸入座標（列 行）：";
        cin >> row >> col;

        if (command == 1) {
            game.checkOpenCell(row-1, col-1,i);
        }
        else if (command == 2) {
            game.flagCell(row-1, col-1);
        }
        else if (command == 3) {
            game.cencleFlagCell(row - 1, col - 1);
        }
        else {
            cout << "無效的指令！" << endl;
        }
    }
    
    return 0;
}
