// CENG 298 - 06
// Samuel Bernsen
// bernsen@chapman.edu
// 11/14/2021

// main.cpp


#include <string>
#include <cmath>
#include <iostream>
#include <tuple>
#include "TicTacToe.h"

using namespace std;

int main() {

	bool bPlay = true;

	while (bPlay)
	{
		TicTacToeGame* p_game = new TicTacToeGame;

		p_game->playGame();

		cout << endl;
		char cPlay = 'n';
		cout << "Play another game? (y/n)" << endl;
		// Get user input using cin
		cin >> cPlay;

		if (cPlay == 'n')
		{
			bPlay = false;
		}
		delete p_game;
	}
	return 0;
}