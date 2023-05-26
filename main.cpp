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

    cout << "踩地雷遊戲" << endl;
    cout << "1. 初級" << endl;
    cout << "2. 中級" << endl;
    cout << "3. 高級" << endl;
    cout << "4. 自訂" << endl;
    cout << "請選擇遊戲等級：";

    int choice;
    cin >> choice;
    
    while(choice <=0 || choice >4)
    {
        cout << "無效的選擇，重新選擇。" << endl;
        cin >> choice;
        cout << "踩地雷遊戲" << endl;
        cout << "1. 初級" << endl;
        cout << "2. 中級" << endl;
        cout << "3. 高級" << endl;
        cout << "4. 自訂" << endl;
        cout << "請選擇遊戲等級：";
    }
    
    
    switch (choice)
    {
        case 1:
            gameMenu.setBeginnerLevel();
            break;
        case 2:
            gameMenu.setIntermediateLevel();
            break;
        case 3:
            gameMenu.setAdvancedLevel();
            break;
        case 4:
            gameMenu.EnterRowColMines();
            break;
    }


    int numRows = gameMenu.getNumRows();
    int numCols = gameMenu.getNumCols();
    int numMines = gameMenu.getNumMines();

    Minefield game(numRows, numCols, numMines);

    int command, row, col;
    bool i = true;
    
    while (i == true)
    {
        game.printField();

        cout << "請輸入指令（1: 打開格子，2: 標示地雷，3: 取消標記):";
        cin >> command;

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
    
    game.printField();
    
    return 0;
}
