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
	cout << "Options: roll, skip" << endl;
	string first;
	cin >> first;

	// command interpreter
	if (first == "roll") {
		int oldPos = p->getPos();
		p->roll();
		int newPos = p->getPos();
		b->movePlayer(newPos, oldPos);

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
			cout << "Pay 1) $300 or"
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
			cout << "You landed on the DC Tims Line! Nothing happens!" << endl;
		}

		else if (newPos == 20) {
			// Goose Nesting
			cout << "GEESE ATTACK YOU!! LOL" << endl;
		}
		else if (newPos == 7 || newPos == 22 || newPos == 36) {
			// Needles hall
			cout << "You landed on Needles Hall!" << endl;
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

			Building *building = (Building *) b->getTile(newPos);
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
	else if (first == "skip") {
		b->incrIterator();
		return;
	}
	else {
		cout << "Not a valid command." << endl;
		cout << "Valid options: roll, skip" << endl;
	}

	// AFTER ROLL TURN OPTIONS: trade, improve, mortgage, unmortgage, bankrupt, assets, save

	cout << "Would you like to do anything else in this turn?" << endl
		<< "Valid commands: trade, improve, mortgage, unmortgage, bankrupt, assets, save" << endl
		<< "done - finish turn" << endl;
	string second;
	while (cin >> second) {
		if (second == "done") {
			b->incrIterator();
			return;
		}
        else if (second == "improve") {
			string propertyName, buyorsell;
			cin >> propertyName;
			cin >> buyorsell;
			AcademicBuilding *ab = (AcademicBuilding *)b->getTile(propertyName);
			if (buyorsell == "buy") p->improve(ab);
			if (buyorsell == "sell") p->unimprove(ab);
		}
		else if (first == "mortgage" || first == "unmortgage") {
			string propertyName;
			cin >> propertyName;
			Building *building = (Building *)b->getTile(propertyName);
			if (first == "mortgage") p->mortgage(building);
			if (first == "unmortgage")p->unmortgage(building);
		}
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
		}//not sure if i+1 is right
		cout << "Player " << i + 1 << ", choose a piece: " << endl;

		char piece;
        //if piece chosen is valid
		if (cin >> piece && pieces.count(piece) > 0) {
            //add player's piece to board
			board.addPlayer(piece);
            //remove piece from list of pieces
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