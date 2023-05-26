//
//  GameMenu.hpp
//  踩地雷
//
//  Created by Gary on 2023/5/25.
//

#ifndef GAME_MENU_H
#define GAME_MENU_H

class GameMenu {
private:
    int numRows;
    int numCols;
    int numMines;

public:
    GameMenu();
    GameMenu(int numRows , int numCols , int numMines);
    void gameInterface();

    void setBeginnerLevel();
    void setIntermediateLevel();
    void setAdvancedLevel();
    void setUserDefined(int numRows , int numCols , int numMines);

    int getNumRows();
    int getNumCols();
    int getNumMines();
    
    void EnterRowColMines();
    bool reasonableMines(int rows , int cols , int mines);
};

#endif
