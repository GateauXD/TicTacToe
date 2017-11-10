// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


string spot1 = "1";
string spot2 = "2";
string spot3 = "3";
string spot4 = "4";
string spot5 = "5";
string spot6 = "6";
string spot7 = "7";
string spot8 = "8";
string spot9 = "9";

bool gameOver() {
	if (spot1 == spot2 && spot2 == spot3)
		return true;
	else if (spot4 == spot5 && spot5 == spot6)
		return true;
	else if (spot6 == spot7 && spot8 == spot9)
		return true;
	else if (spot1 == spot4 && spot4 == spot7)
		return true;
	else if (spot2 == spot5 && spot5 == spot8)
		return true;
	else if (spot3 == spot6 && spot6 == spot9)
		return true;
	else if (spot1 == spot5 && spot5 == spot9)
		return true;
	else if (spot3 == spot5 && spot5 == spot7)
		return true;
	else
		return false;
}

void changeSpot(int value, string letter) {
	if (value == 1 && spot1 == "1") {
		spot1 = letter;
	}
	else if (value == 2 && spot2 == "2") {
		spot2 = letter;
	}
	else if (value == 3 && spot3 == "3") {
		spot3 = letter;
	}
	else if (value == 4 && spot4 == "4") {
		spot4 = letter;
	}
	else if (value == 5 && spot5 == "5") {
		spot5 = letter;
	}
	else if (value == 6 && spot6 == "6") {
		spot6 = letter;
	}
	else if (value == 7 && spot7 == "7") {
		spot7 = letter;
	}
	else if (value == 8 && spot8 == "8") {
		spot8 = letter;
	}
	else if (value == 9 && spot9 == "9") {
		spot9 = letter;
	}
	else {
		cout << "The spot you entered does not exit or already has already been taken" << endl;
	}
}

void drawTable() {


	cout << endl;

	cout << "  " << spot1 << "  |  " << spot2 << "  |  " << spot3 << "  " << endl;
	cout << "-----------------" << endl;
	cout << "  " << spot4 << "  |  " << spot5 << "  |  " << spot6 << "  " << endl;
	cout << "-----------------" << endl;
	cout << "  " << spot7 << "  |  " << spot8 << "  |  " << spot9 << "  " << endl;

}

int main()
{

	drawTable();

	int p1, p2;

	while (true) {

		cout << "Player 1 it's your turn" << endl;
		cin >> p1;
		
		changeSpot(p1, "X");

		drawTable();

		cout << "Player 2 it's your turn" << endl;
		cin >> p2;
		changeSpot(p2, "O");

		drawTable();

	}

	return 0;

}

