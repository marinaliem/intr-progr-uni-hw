#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;

#define STEPPEDON 9;
// tui kato na vs mesta v masiva stoinostite sa mejdu -3 i 3 nqma kak nikude da e 9,
// t.e. ako ima 9 nqkude shte znaem che tam e stupvano

int random(int min, int max) {
	return rand() % (max - min + 1) + min;
}
int main()
{
	int array[50];
	int n;
	cout << "How long should the tunnel be?" << endl;
	do {
		cin >> n;
	} while (n < 0);
	array[0] = 0;
	array[n - 1] = 0;
	for (int i = 1; i < n - 1; i++) {
		array[i] = random(-3, 3);
	}
	int current = random(1, 2);
	cout << "First is Player N " << current << endl;
	bool endGame = false;
	int index_player1 = 0, index_player2 = 0; // na koi index e igracha v momenta

	do {
		cout << "Current player, please make a wish aka pick an index to go to!" << endl;
		do {
			if (current % 2 == 0) {
				cin >> index_player2;
			}
			else
			{
				cin >> index_player1;
			}
		} while (index_player1 >= n - 1 || index_player2 >= n - 1);
		if (current % 2 == 0) {
			if (array[index_player2] != 9) {
				int temp1 = array[index_player2];
				array[index_player2] = STEPPEDON;
				index_player2 += temp1;

			}
		}
		else {
			if (array[index_player1] != 9) {
				int temp2 = array[index_player1];
				array[index_player1] = STEPPEDON;
				index_player1 += temp2;
			}
		}

		if (index_player1 >= n - 1 || index_player2 >= n - 1) endGame = true;
		current++;
		cout << "pl1 - " << index_player1 << " i pl2 - " << index_player2 << endl;
	} while (endGame == false);
	cout << "Winner: " << ((index_player1 == n - 1) ? "Player 1!" : "Player 2!") << endl;
	return 0;
}

