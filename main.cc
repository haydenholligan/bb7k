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
#include <map>
using namespace std;

void takeInput() {


}



int main() {

	cout << "WELCOME TO BB7K!" << endl;
	cout << "Number of players: ";
	int n;
	cin >> n;
	Board board;

	map<char, string> pieces;
	pieces['G'] = "Goose";
	pieces['B'] = "GRT Bus";
	pieces['D'] = "Tims Donut";
	pieces['P'] = "Professor";
	pieces['S'] = "Student";
	pieces['$'] = "Money";
	pieces['L'] = "Laptop";
	pieces['T'] = "Pink tie";

	typedef map<char, string>::iterator it;

	for (int i = 0; i < n; i++) {
		cout << "---Available pieces---" << endl;
		for (it iterator = pieces.begin(); iterator != pieces.end(); iterator++) {
			cout << "  " << iterator->first << ": " << iterator->second << endl;
		}
		cout << "Player " << i + 1 << ", choose a piece: " << endl;

		char piece;
		if (cin >> piece && pieces.count(piece) > 0) {
			board.addPlayer(piece);
			pieces.erase(piece);
		} else {
			cout << "Unavailable, choose another piece" << endl;
			i--;
		}
	}

	
}
