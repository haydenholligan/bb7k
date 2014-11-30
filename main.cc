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

	bool rolled = false;

	// DRAW BOARD
	b->reDraw();

	cout << "----- " << p->getName() << " -----" << endl;

	while (true) {

		cout << "Options: help, ";
		if (!rolled) cout << "roll, ";
		cout << "next, trade, improve, mortgage, unmortgage, bankrupt, assets, save" << endl;

		string command;
		cin >> command;
		if (!cin) {
			// READ ERROR
		}

		if (command == "next") {
			cout << endl << endl;
			b->incrIterator();
			return;
		}

		// *****ROLL*****
		else if (!rolled && command == "roll") {
			rolled = true;
			int oldPos = p->getPos();
			p->roll();
			int newPos = p->getPos();
			b->movePlayer(newPos, oldPos);

			cout << "You landed on " << b->getTile(newPos)->getName() << "." << endl;

			if (newPos == 0) {
				// COllECT OSAP
				cout << "Congratulations! Collect $200!" << endl;
				// player already gets 200 from roll function
			}

			else if (newPos == 2 || newPos == 33) {
				// SLC
				p->SLC(b);
			}

			else if (newPos == 4) {
				// TUITON
				cout << "You have to pay tuition! Options: " << endl
					<< "    1) $300 or" << endl
					<< "    2) 10% of your total worth?" << endl;
				string option;
				cin >> option;
				istringstream ss(option);
				int n;
				ss >> n;
				p->payTution(n);
			}

			else if (newPos == 10) {
				// DC Tims line
				cout << "Nothing happens!" << endl;
			}

			else if (newPos == 20) {
				// Goose Nesting
				cout << "GEESE ATTACK YOU!! LOL" << endl;
			}
			else if (newPos == 7 || newPos == 22 || newPos == 36) {
				// Needles hall
				p->NeedlesHall(b);
			}
			else if (newPos == 30) {
				// GO TO TIMS
				cout << "You must go to the DC Tims Line. Wait 3 turns to get out." << endl;
				p->goToTims();
			}
			else if (newPos == 38) {
				// COOP FEE
				cout << "You must pay $150" << endl;
				p->pay(150);
			}
			else {
				// otherwise, player has landed on property (academic building, residence, or gym)
				// if no one owns this property
				//   player can buy, or do nothing
				// if someone owns this property already
				//   player must pay rent

				Building *building = (Building *)b->getTile(newPos);
				if (building->getOwner() == NULL) {
					// no owner
					cout << "Would you like to purchase " << building->getName() << " for $" << building->getPurchaseCost() << "? (y/n) ";
					string answer;
					cin >> answer;
					if (answer.at(0) == 'y') {
						p->purchase(building);
					}
				}
				else if (building->getOwner()->getPiece() == p->getPiece()) {
					// current player owns this building already
					cout << "You own " << building->getName() << " already!" << endl;
				}
				else {
					// someone else owns it, player must pay fee
					Player *owner = building->getOwner();
					double fee = building->getFee();
					cout << "You must pay " << fee << " to Player " << owner->getPiece() << endl;
					p->pay(fee);
					owner->collect(fee);
				}
			}
		}
		else if (command == "improve") {
			string propertyName, buyorsell;
			cin >> propertyName;
			cin >> buyorsell;
			Tile *t = b->getTile(propertyName);
			int i = 0;
			if (t) i = t->getIndex();
			// not proud of this
			// if tile is not ACADEMICBUILDING
			if (i == 0 || i == 2 || i == 4 || i == 5 || i == 7 || i == 10 || i == 12 ||
				i == 15 || i == 17 || i == 20 || i == 22 || i == 25 || i == 28 ||
				i == 30 || i == 33 || i == 35 || i == 36 || i == 38) {
				cout << "You cannot buy/sell any improvements on " << propertyName << "." << endl;
			}
			// if the tile is an AcademicBuilding
			else {
				AcademicBuilding* ab = (AcademicBuilding*)b->getTile(propertyName);
				if (buyorsell == "buy") p->improve(ab, true);
				if (buyorsell == "sell") p->improve(ab, false);
			}
		}
		else if (command == "mortgage" || command == "unmortgage") {
			string propertyName;
			cin >> propertyName;
			Tile *t = b->getTile(propertyName);
			int i = 0;
			if (t) i = t->getIndex();
			// not proud of this
			// if tile is not BUILDING
			if (i == 0 || i == 2 || i == 4 || i == 7 || i == 10 ||
				i == 17 || i == 20 || i == 22 ||
				i == 30 || i == 33 || i == 36 || i == 38) {
				cout << "You cannot mortgage " << propertyName << "." << endl;
			}
			else {
				Building *building = (Building *)b->getTile(propertyName);
				if (command == "mortgage") p->mortgage(building);
				if (command == "unmortgage")p->unmortgage(building);
			}




		}
		else if (command == "trade") {
			// trade
			// trade <name> <give> <receive>
			string partner, give, receive;
			cin >> partner;
			cin >> give;
			cin >> receive;

			if (!b->playerExists(partner)) {
				cout << partner << " is not a valid player." << endl;
			}
			else {
				int nGive, nReceive;
				istringstream ssGive(give);
				if (ssGive >> nGive) {
					// receive is a property then
					Tile *t = b->getTile(receive);
					int i = 0;
					if (t) i = t->getIndex();
					// not proud of this
					// if tile is not BUILDING
					if (i == 0 || i == 2 || i == 4 || i == 7 || i == 10 ||
						i == 17 || i == 20 || i == 22 ||
						i == 30 || i == 33 || i == 36 || i == 38) {
						cout << "You cannot trade $" << nGive << " for " << receive << "." << endl;
					}
					else {
						Building *building = (Building *)b->getTile(receive);
						if (building->getOwner()->getName() != partner) {
							cout << partner << " does not own " << receive << endl;
						}
						//cout << partner << ", do you accept the trade"
						//	string response;

					}
				}
			}
		}
		else if (command == "assets") {
			// assets
		}
		else if (command == "save") {
			// save 
		}
		else {
			cout << "Not a valid command!" << endl;
		}
	}


}

int main(int argc, char* argv[]) {
	cout << "Welcome to BB7K!" << endl;
	cout << "Enter number of players: (2-6) ";
	int n = 0;

	while (n < 2 || n > 6) {
		string s;
		cin >> s;
		istringstream ss(s);
		ss >> n;
	}

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

	// Players are setup here
	for (int i = 0; i < n; i++) {
		cout << "Enter player name: " << endl;
		string name;
		cin >> name;

		cout << "---Available pieces---" << endl;
		for (it iterator = pieces.begin(); iterator != pieces.end(); iterator++) {
			cout << "  " << iterator->first << ": " << iterator->second << endl;
		}
	   
		cout << name << ", choose a piece: " << endl;

		char piece;
        //if piece chosen is valid
		if (cin >> piece && pieces.count(piece) > 0) {
            //add player's piece to board
			board.addPlayer(name, piece);
            //remove piece from list of pieces
			pieces.erase(piece);
		} else {
			cout <<  "Unavailable, choose another piece" << endl;
			i--;
		}
    }

	while (true) { // stop loop, TODO
		// Players turn
		Player *player = board.nextPlayer();
		takeTurn(&board, player);
	}
	
}