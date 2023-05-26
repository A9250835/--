#include "Cell.h" //地雷狀態

Cell::Cell() 
{
    isMine = false; //是否為地雷
    isFlagged = false; //是否設置為旗子
    isQuestionMark = false; //是否被標記問號
    isOpened = false; //是否被翻開
    adjacentMines = 0;
}

void Cell::setMine() 
{
    isMine = true;
}

bool Cell::hasMine() 
{
    return isMine;
}

void Cell::setFlag() 
{
    isFlagged = true;
}

bool Cell::isFlaggedCell() 
{
    return isFlagged;
}

void Cell::setQuestionMark() 
{
    isQuestionMark = true;
}

bool Cell::isQuestionMarkCell() 
{
    return isQuestionMark;
}

void Cell::openCell() 
{
    isOpened = true;
}

bool Cell::isCellOpened() 
{
    return isOpened;
}

void Cell::setAdjacentMines(int count) 
{
    adjacentMines = count;
}

int Cell::getAdjacentMines() 
{
    return adjacentMines;
}
