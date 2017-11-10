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

	return false;
}

void changeSpot() {
	
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

	while (!gameOver) {

		cout << "Player 1 it's your turn" << endl;
		cin >> p1;
		


	}

	return 0;

}

