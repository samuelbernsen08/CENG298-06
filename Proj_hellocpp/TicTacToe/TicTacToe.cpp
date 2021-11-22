// CENG 298 - 06
// Samuel Bernsen
// bernsen@chapman.edu
// 11/14/2021

// TicTacToe.cpp

#include <string>
#include <cmath>
#include <iostream>
#include "TicTacToe.h"
#include <tuple>
#include <random>

using namespace std;



void TicTacToeGame::resetGrid() {

	this->initGrid();

}

void TicTacToeGame::playGame() {
	int iRow = 0;
	int iColumn = 0;
	bool isOccupied = false;

	cout << "Tic Tac Toe game against the computer: " << endl;
	cout << "Grids and Rows start at 0 and end at 2..." << endl;

	// this->initGrid();
	this->resetGrid();
	this->displayGrid();


	// looping until the game ends
	while (!checkWin() || !checkDraw()) {

		do {
			// userMove();

			tie(iRow, iColumn) = userMove();
			// cout << "after usermove" << endl;
			if (this->pp_cGrid[iRow][iColumn] != '~') {
				// cout << "within conditional" << endl;
				isOccupied = true;
				cout << "This position is taken. Choose another: " << endl;
			}
			else {
				isOccupied = false;
			}
		} while (isOccupied);
		// Sets the location from user as an 'X'
		this->pp_cGrid[iRow][iColumn] = 'X';
		this->displayGrid();

		// Checks if a gameOver condition has been met
		if (checkWin() || checkDraw()) {
			return;
		}
		else {
			// Performs a move for the cpu
			// cout << "before cpu move " << endl;
			cpuMove();
			// cout << "after cpu move" << endl;
			this->displayGrid();

			// Checks if a gameOver condition has been met
			if (checkWin() || checkDraw()) {
				return;
			}
		}

	}
}

TicTacToeGame::TicTacToeGame() : m_nGridRows(k_nGridRowsDefault), m_nGridColumns(k_nGridColumnsDefault) { // constructor
	
	initGrid();
}

TicTacToeGame::~TicTacToeGame() { // destructor
	for (int iRow = 0; iRow < 3; iRow++) {
		delete[] pp_cGrid[iRow];
	}
	delete[] pp_cGrid;
}

void TicTacToeGame::initGrid() {


	this->pp_cGrid = new char* [3]; // three pointers to char on heap

	for (int iRow = 0; iRow < 3; iRow++) {
		this->pp_cGrid[iRow] = new char[3];
	}


	for (int iRow = 0; iRow < k_nGridRowsDefault; iRow++)
	{
		for (int iColumn = 0; iColumn < k_nGridColumnsDefault; iColumn++)
		{
			this->pp_cGrid[iRow][iColumn] = '~'; // initializes the grid to have ~s in empty spots
		}
	}
	return;
}

void TicTacToeGame::displayGrid() { // displays the contents of the initialized grid
	cout << endl;
	for (int iRow = 0; iRow < this->m_nGridRows; iRow++)
	{
		for (int iColumn = 0; iColumn < this->m_nGridColumns; iColumn++)
		{
			cout << this->pp_cGrid[iRow][iColumn];
		}
		cout << endl;
	}
}


tuple<int, int> TicTacToeGame::userMove()
{
	int iRow = 0;
	int iColumn = 0;

	cout << "Please enter grid row number: " << endl;
	cin >> iRow;
	iRow = checkUserInput(iRow); // checks to make sure this is a valid position


	cout << "Please enter grid column number: " << std::endl;
	cin >> iColumn;
	iColumn = checkUserInput(iColumn);// checks to make sure this is a valid position


	tuple<int, int> tupleCoord = make_tuple(iRow, iColumn); // stores the values in a tuple

	return tupleCoord;

}

void TicTacToeGame::cpuMove() { // random number generator
	int iRow;
	int iColumn;
	bool isSelected = true;

	do {
		random_device randomDevice;

		default_random_engine randomNumbreGenerator(randomDevice());

		uniform_int_distribution<int> uniformIntegerDistributionRows(0, (this->m_nGridRows - 1));

		iRow = uniformIntegerDistributionRows(randomNumbreGenerator);

		uniform_int_distribution<int> uniformIntegerDistributionColumns(0, (this->m_nGridColumns - 1));

		iColumn = uniformIntegerDistributionColumns(randomNumbreGenerator);

		if (this->pp_cGrid[iRow][iColumn] != '~') {
			isSelected = true;
		}
		else {
			isSelected = false;
		}

	} while (isSelected);
	this->pp_cGrid[iRow][iColumn] = 'O';
	return;

}

bool TicTacToeGame::checkWin() {
	char winner = 'B';
	bool isOver = false;
	char char_tl = this->pp_cGrid[0][0]; // top left character
	char char_tr = this->pp_cGrid[2][0]; // top right character
	char middleChar = this->pp_cGrid[1][1]; // middle character
	char char_br = this->pp_cGrid[2][2]; // bottom right character
	char char_bl = this->pp_cGrid[0][2]; // bottom left character 

	// checking for winning diagonals:
	if (char_tl != '~' && (char_tl == middleChar && char_tl == char_br)) {
		winner = middleChar;
		isOver = true;
	}
	else if (char_tr != '~' && (char_tr == middleChar && char_tr == char_bl)) {
		winner = middleChar;
		isOver = true;
	}

	// checking for winning rows

	for (int iRow1 = 0; iRow1 < this->m_nGridRows; ++iRow1) {

		if ((this->pp_cGrid[iRow1][0] != '~') && (this->pp_cGrid[iRow1][0] == this->pp_cGrid[iRow1][1]) && (this->pp_cGrid[iRow1][1] == this->pp_cGrid[iRow1][2])) {
			winner = this->pp_cGrid[iRow1][0];
			isOver = true;
		}

	}

	// checking for winning columns
	for (int iColumn1 = 0; iColumn1 < this->m_nGridColumns; ++iColumn1) {

		if ((this->pp_cGrid[0][iColumn1] != '~') && (this->pp_cGrid[0][iColumn1] == this->pp_cGrid[1][iColumn1]) && (this->pp_cGrid[1][iColumn1] == this->pp_cGrid[2][iColumn1])) {
			winner = this->pp_cGrid[0][iColumn1];
			isOver = true;
		}
	}
	if (winner == 'X' || winner == 'O') {
		cout << "We have a winner!" << endl;
		cout << "WINNER: " << winner << endl;
	}
	return isOver;
}


bool TicTacToeGame::checkDraw() { // checks for a draw condition
	int numOpenSpaces = 0;
	bool isOverDraw = false;

	for (int iRow = 0; iRow < this->m_nGridRows; ++iRow) {
		for (int iColumn = 0; iColumn < this->m_nGridColumns; ++iColumn) {
			if (this->pp_cGrid[iRow][iColumn] == '~') {
				numOpenSpaces += 1;
	
			}
		}
	}
	if (numOpenSpaces == 0) { // if all of the spaces are filled up, we have a draw
		isOverDraw = true;
		cout << "This game ends in a draw!" << endl;
	}
	return isOverDraw;
}

int TicTacToeGame::checkUserInput(int userInput) { // checks for valid input (between 0 and 2 inclusive)
	while ((userInput < 0) || (userInput > 2)) {
		cout << "Your input must be between 0 and 2" << endl;
		cout << "Renter valid location on the grid: " << endl;
		cin >> userInput;
	}
	return userInput;
}
