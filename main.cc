#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "board.h"
#include "block.h"
#include "player.h"
#include "tile.h"
#include "building.h"
#include "acBuilding.h"
#include "gym.h"
#include "residence.h"
#include <map>
#include <cstdlib>

using namespace std;

bool runMain = true;
bool isTesting = false;

void roll(Board *b, Player *p) {
	int newPos, oldPos;
	if (isTesting == true) {
		int x, y, sum;
		cin >> x;
		cin >> y;
		sum = x + y;
		oldPos = p->getPos();
		p->move(sum);
		newPos = p->getPos();
		b->movePlayer(newPos, oldPos);
	}
	else if (isTesting == false) {
		oldPos = p->getPos();
		p->roll();
		newPos = p->getPos();
		b->movePlayer(newPos, oldPos);
	}
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
		cout << "GEESE ATTACK YOU!!" << endl;
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
		if (!p->pay(150)) bankrupt(b, p);
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

void mortgage(Board *b, Player *p, string command) {
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
		if (command == "unmortgage") p->unmortgage(building);
	}
}

void improve(Board *b, Player *p, string command) {
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

void trade(Board *b, Player *p) {
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
				cout << partner << ", do you accept the trade? (y/n) ";
				string response;
				cin >> response;
				if (response.at(0) == 'y') {
					p->pay(nGive);
					b->getPlayer(partner)->collect(nGive);
					building->setOwner(p);
				}

			}
		}
		else {
			// offer property for $$$
			istringstream ssReceive(receive);
			if (ssReceive >> nReceive) {
				Tile *t = b->getTile(give);
				int i = 0;
				if (t) i = t->getIndex();

				if (i == 0 || i == 2 || i == 4 || i == 7 || i == 10 ||
					i == 17 || i == 20 || i == 22 ||
					i == 30 || i == 33 || i == 36 || i == 38) {
					cout << "You cannot trade " << give << " for $" << nReceive << "." << endl;
				}
				else {
					Building *building = (Building *)b->getTile(give);
					if (building->getOwner()->getName() != p->getName()) {
						cout << "You do not own " << give << endl;
					}
					else {
						cout << partner << ", do you accept the trade? (y/n) ";
						string response;
						cin >> response;
						if (response.at(0) == 'y') {
							p->collect(nReceive);
							b->getPlayer(partner)->pay(nReceive);
							building->setOwner(b->getPlayer(partner));
						}
					}
				}
			}
		}
	}
}

void assets(Board *b, Player *p) {

}

void save(Board *b) {

}

void bankruptOption(Board *b, Player *p) {
	cout << "Options: bankrupt, mortgage, trade" << endl;

}

void takeTurn(Board *b, Player *p) {

	bool rolled = false;

	// DRAW BOARD
	b->reDraw();

	cout << "----- " << p->getName() << "'s turn -----" << endl;

	while (true) {

		cout << "Options: help, ";
		if (!rolled) cout << "roll, ";
		cout << "next, trade, improve, mortgage, unmortgage, assets, save" << endl;

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
		else if (!rolled && command == "roll") {
			rolled = true;
			roll(b, p);
		}
		else if (command == "improve") {
			improve(b, p, command);
		}
		else if (command == "mortgage" || command == "unmortgage") {
			mortgage(b, p, command);
		}

		else if (command == "trade") {
			trade(b, p);
		}
		else if (command == "assets") {
			assets(b, p);
		}
		else if (command == "save") {
			save(b);
		}
		else {
			cout << "Not a valid command!" << endl;
		}
	}
}

void newGame(Board *board) {

}

int main(int argc, char* argv[]) {
	if (argc > 1) {
		string str(argv[1]);
		//argv[0] is the program
		//argv[1] is -load or -testing
		//if argv[1] is -load, argv[2] is a filename
		if (str == "-load") {
			runMain = false;
			ifstream  f;
			char *file = argv[2];
			string name, owner;
			int numPlayers, money, position, dc, dcnum, improvements;
			Board board;

			char pieces[8];
			pieces[0] = 'G';
			pieces[1] = 'B';
			pieces[2] = 'D';
			pieces[3] = 'P';
			pieces[4] = 'S';
			pieces[5] = '$';
			pieces[6] = 'L';
			pieces[7] = 'T';


			f.open(file);

			if (!f.is_open()) {
				exit(EXIT_FAILURE);
			}

			f >> numPlayers;

			Player *listofPlayers[6];
			for (int i = 0; i < numPlayers; i++) {
				int piece = (rand() % 8);
				f >> owner;
				Player *p = board.addPlayer(owner, pieces[piece]);
				f >> money;
				p->money = money;
				f >> position;
				p->pos = position;
				if (position == 10) {
					f >> dc;
					if (dc == 1) {
						f >> dcnum;
						p->turnsInTims = dcnum;
					}
					else dcnum = 0;
				}
				listofPlayers[i] = p;
			} //end for

			for (int i = 0; i < 40; i++) {
				if (i == 0 || i == 2 || i == 4 || i == 7 || i == 10 || i == 17 || i == 20 || i == 22 || i == 30 || i == 33 || i == 36 || i == 38) {
					break;
				}

				else {
					f >> name;
					f >> owner;
					Player *p1 = board.getPlayer(name);
					Building *b = (Building *)board.getTile(i);
					b->setOwner(p1);

					f >> improvements;
					while (improvements > 0) {
						AcademicBuilding *ab = (AcademicBuilding *)b;
						ab->improve();
						improvements--;
					}
				}
			}
			while (true) { // stop loop, TODO
				// Players turn
				Player *player = board.nextPlayer();
				takeTurn(&board, player);
			}
		}
		else if (str == "-testing") {
			isTesting = true;
			runMain = true;
		}

	}

	if (runMain == true) {
		cout << "Welcome to BB7K!" << endl;
		if (isTesting == true) {
			cout << "Testing mode enabled" << endl;
		}
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
			}
			else {
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

}