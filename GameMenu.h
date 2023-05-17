#ifndef Cell_H
#define Cell_H
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Cell 
{
private:
    bool isMine;
    bool isFlagged;
    bool isQuestionMark;
    bool isOpened;
    int adjacentMines;

public:
    Cell();
    void setMine();
    bool hasMine();
    void setFlag();
    bool isFlaggedCell();
    void setQuestionMark();
    bool isQuestionMarkCell();
    void openCell();
    bool isCellOpened();
    void setAdjacentMines(int count);
    int getAdjacentMines();
};

#endif
