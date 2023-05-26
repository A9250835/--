#include "GameMenu.h"


GameMenu::GameMenu() {
	numRows = 9;
	numCols = 9;
	numMines = 10;
}

GameMenu::GameMenu(int numRows, int numCols, int numMines):numRows(numRows),numCols(numCols),numMines(numMines) {}

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

int GameMenu::getNumRows() {
	return numRows;
}

int GameMenu::getNumCols() {
	return numCols;
}

int GameMenu::getNumMines() {
	return numMines;
}
