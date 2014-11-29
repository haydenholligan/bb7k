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

void takeTurn(Board *b, Player *p) {
	b->reDraw();
	cout << "-----Player " << p->getPiece() << "'s turn----" << endl;
	string first;
	cin >> first;

	// command interpreter
	if (first == "roll") {
		p->roll();
		cout << b->getTile(p->getPos())->getName() << endl;
		// take action on square they land on
	}
	else if (first == "next") {
		return;
	}
	else if (first == "trade") {
		// TODO
	}
	else if (first == "improve") {
		string propertyName, buyorsell;
		cin >> propertyName;
		cin >> buyorsell;
		AcademicBuilding *ab = (AcademicBuilding *) b->getTile(propertyName);
		if (buyorsell == "buy") p->improve(ab);
		if (buyorsell == "sell") p->unimprove(ab);
	}
	else if (first == "mortgage") {
		string propertyName;
		cin >> propertyName;
		Building *building = (Building *) b->getTile(propertyName);
		p->mortgage(building);
	}
	else if (first == "unmortgage") {
		string propertyName;
		cin >> propertyName;
		Building *building = (Building *) b->getTile(propertyName);
		p->unmortgage(building);
	}
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

	// Players choose pieces here
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

	while (true) { // stop loop, TODO
		// Players turn
		Player *player = board.nextPlayer();
		takeTurn(&board, player);
	}
	
}