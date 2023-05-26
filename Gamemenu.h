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

    void setBeginnerLevel();
    void setIntermediateLevel();
    void setAdvancedLevel();

    int getNumRows();
    int getNumCols();
    int getNumMines();
};

#endif
