#include <iostream>
#include <sstream>
#include <string>
#include "board.h"
#include "block.h"
#include "player.h"
#include "tile.h"
#include "building.h"
#include "acBuilding.h"
#include "gym.h"
#include "residence.h"
using namespace std;

void takeInput() {


}



int main() {

	cout << "WELCOME TO BB7K!" << endl;
	cout << "Number of players: ";
	int n;
	cin >> n;
	Board board(n);

	for (int i = 0; i < 4; i++) {
		cout << "Player " << i << ", choose a piece: " << endl;
		string s;
		cin >> s;
		board.addPlayer(s.at(0));
	}

	cout << "DONE FOR NOW" << endl;


}
