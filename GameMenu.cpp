//
//  GameMenu.cpp
//  踩地雷
//
//  Created by Gary on 2023/5/25.
//

#include "GameMenu.h"
#include "iostream"
using namespace std;

GameMenu::GameMenu() {
    numRows = 9;
    numCols = 9;
    numMines = 10;
}
GameMenu::GameMenu(int numRows , int numCols , int numMines):numRows(numRows),numCols(numCols),numMines(numMines){}

void GameMenu::setBeginnerLevel() {
    numRows = 9;
    numCols = 9;
    numMines = 10;
}

void GameMenu::setIntermediateLevel() {
    numRows = 16;
    numCols = 16;
    numMines = 40;
}

void GameMenu::setAdvancedLevel() {
    numRows = 30;
    numCols = 16;
    numMines = 99;
}
void GameMenu::setUserDefined(int numRows , int numCols , int numMines)
{
    this->numRows = numRows;
    this->numCols = numCols;
    this->numMines = numMines;
}

int GameMenu::getNumRows() {
    return numRows;
}

int GameMenu::getNumCols() {
    return numCols;
}

int GameMenu::getNumMines() {
    return numMines;
}

void GameMenu::EnterRowColMines()
{
    int rows,cols,mines;
    cout << "輸入Rows: ";
    cin >> rows;
    cout << "輸入Cols: ";
    cin >> cols;
    cout << "輸入Mines: ";
    cin >> mines;
    if (reasonableMines(rows,cols,mines))
        setUserDefined(rows, cols, mines);
    else
    {
        cout << "超出範圍，請重新輸入" << endl;
        EnterRowColMines();
    }
}

bool GameMenu::reasonableMines(int rows , int cols , int mines)
{
    if (rows*cols/10*3 >= mines && mines >= 10 && rows >= 9 && cols >= 9)
        return true;
    else
        return false;
}

void GameMenu::gameInterface()
{
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
            setBeginnerLevel();
            break;
        case 2:
            setIntermediateLevel();
            break;
        case 3:
            setAdvancedLevel();
            break;
        case 4:
            EnterRowColMines();
            break;
    }
}
