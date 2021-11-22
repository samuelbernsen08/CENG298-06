// CENG 298 - 06
// Samuel Bernsen
// bernsen@chapman.edu
// 11/14/2021

// TicTacToe.h

#if !defined(TicTacToe_H)
#define TicTacToe_H

#include <string>
#include <cmath>
#include <iostream>
#include <tuple>

using namespace std;

class TicTacToeGame {
public:
	static const int k_nGridRowsDefault = 3;
	static const int k_nGridColumnsDefault = 3;
	TicTacToeGame();
	~TicTacToeGame();
	void playGame();
	void initGrid();
	int checkUserInput(int userInput);
	void displayGrid();
	void resetGrid();
	tuple<int, int> userMove();
	void cpuMove();
	bool checkWin();
	bool checkDraw();


private:
	char **pp_cGrid = new char* [3];	// Pointer (p) to (pointer	to	character (p_c))
	int m_nGridRows;
	int m_nGridColumns;
};

#endif
