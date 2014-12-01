#include <cstdlib>
#include "player.h"
#include "building.h"
#include "acBuilding.h"
#include "block.h"
#include "board.h"

Player::Player(string name, char piece) : name(name), piece(piece), pos(0), money(1500), numResidences(0), numGyms(0), turnsInTims(0), netWorth(1500), hasRollupCup(false) {}


string Player::getName() {
	return name;
}

int Player::getPos() {
	return pos;
}

int Player::move(int x) {
	int newPos = pos + x;
	if (newPos >= 40) {
		newPos -= 40;
		cout << "Pass COLLECT OSAP: Collect $200" << endl;
		collect(200);
	}
	if (newPos < 0) {
		newPos += 40;
	}
	pos = newPos;
	return newPos;
}

bool Player::pay(double amount) {

	
	cout << name << ": " << money << " - " << amount << " = " << money - amount << endl;
	if (money - amount < 0) {
		cout << "Insufficient funds!" << endl;
		return false;
	}
	money -= amount;
	netWorth -= amount;
	return true;
}

void Player::collect(double amount) {
	cout << name << ": " << money << " + " << amount << " = $" << money + amount << endl;
	money += amount;
	netWorth += amount;
}

void Player::purchase(Building *b) {
	if (pay(b->getPurchaseCost())) b->purchase(this);
}

void Player::improve(AcademicBuilding *ab, bool buy) {
	Player *owner = ab->getOwner();
	if (owner && owner->getPiece() == this->piece && ab->getBlock()->isMonopoly()) {
		if (buy) {
			if (ab->getNumImproves() <= 4) {
				pay(ab->getImproveCost());
				ab->improve();
			}
			else {
				cout << "Cannot improve " << ab->getName() << " any more (max 5 improvements)." << endl;
			}
		}
		else {
			if (ab->getNumImproves() > 0) {
				ab->unimprove();
				collect(ab->getImproveCost() / 2);
			}
			else {
				cout << ab->getName() << " does not have any improvements." << endl;
			}
		}
	}
	else {
		cout << "You cannot buy/sell improvements for " << ab->getName() << " since you do not own all the buildings in its Monopoly Block." << endl;
		ab->getBlock()->printBuildingList();
	}
}

void Player::addResidence() {
	numResidences++;
}

void Player::addGym() {
	numGyms++;
}

int Player::getNumResidences() {
	return numResidences;
}

int Player::getNumGyms() {
	return numGyms;
}

void Player::mortgage(Building *b) {
	Player *owner = b->getOwner();
	if (owner && owner->getPiece() == piece) {
		if (b->isMortgaged()) {
			cout << b->getName() << " is already mortgaged!" << endl;
			return;
		}
		cout << "You have mortgaged " << b->getName() << "." << endl;
		collect(b->mortgage());
	}
	else {
		cout << "You do not own " << b->getName() << " - you cannot mortgage it." << endl;
	}
}

void Player::unmortgage(Building *b) {
	Player *owner = b->getOwner();
	if (owner && owner->getPiece() == piece) {
		if (!b->isMortgaged()) {
			cout << b->getName() << " is not mortgaged!" << endl;
			return;
		}
		double cost = b->getPurchaseCost();
		double toPay = (cost / 2) + (0.10 * cost);
		cout << "You must pay $" << toPay << " to unmortgage this property. Are you sure? (y/n) ";
		string answer;
		cin >> answer;
		if (answer.at(0) != 'y') return;
		pay(toPay);
		b->unmortgage();
	}
	else {
		cout << "You do not own " << b->getName() << " - you cannot unmortgage it." << endl;
	}
}

double Player::getBalance() {
	return money;
}

char Player::getPiece() {
	return piece;
}

void Player::roll() {
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	int sum = die1 + die2;
	cout << "You rolled: " << die1 << " + " << die2 << " = " << sum << endl;
	move(sum);
}

void Player::giveRollupCup() {
	hasRollupCup = true;
}

void Player::goToTims() {
	pos = 10; // 10th tile is DC Tims Line
	turnsInTims++;
}

bool Player::tryToLeaveTims(Board *b) {
	if (turnsInTims >= 4) {
		turnsInTims = 0;
		return true;
	}
	else if (hasRollupCup) {
		cout << "You have a rollup cup you can use to get out of the DC Tims Line! Use it? (y/n) ";
		string answer;
		cin >> answer;
		if (answer.at(0) == 'y') {
			hasRollupCup = false;
			for (int i = 0; i < 4; i++) {
				if (b->rollUp[i]->getPiece() == piece) {
					b->rollUp[i] = NULL;
				}
			}
			turnsInTims = 0;
			return true;
		}
	}
	// player can also use rollup cup or pay money to escape Tims
	//adjust net worth
	// TODO
	cout << 3 - turnsInTims << " more turns in Tims" << endl;
	turnsInTims++;
	return false;
}

bool Player::payTution(int option) {
	if (option == 1) {
		return pay(300);

	}
	else if (option == 2) {
        return pay(netWorth * 0.10);
	}
	return false;
}

void Player::SLC(Board *board) {
	int timsCheck = rand() % 100 + 1;
	if (timsCheck == 1) {
		board->giveRollupCup(this);
	}
	else {
		int newPos = rand() % 24 + 1;

		if (newPos >= 1 && newPos <= 3) {
			move(-3);
		}
		else if (newPos >= 4 && newPos <= 7) {
			move(-2);
		}
		else if (newPos >= 8 && newPos <= 11) {
			move(-1);
		}
		else if (newPos >= 12 && newPos <= 14) {
			move(1);
		}
		else if (newPos >= 15 && newPos <= 18) {
			move(2);
		}
		else if (newPos >= 19 && newPos <= 22) {
			move(3);
		}
		else if (newPos == 23) {
			goToTims();
		}
		else if (newPos == 24) {
			move(-pos);
		}
	}
}

void Player::NeedlesHall(Board *board) {
	int timsCheck = rand() % 100 + 1;
	if (timsCheck == 1) {
		board->giveRollupCup(this);
	}
	else {
		int rand18 = rand() % 18 + 1;

		if (rand18 == 1) {
			pay(200);
		}
		else if (rand18 >= 2 && rand18 <= 3) {
			pay(100);
		}
		else if (rand18 >= 4 && rand18 <= 6) {
			pay(50);
		}
		else if (rand18 >= 7 && rand18 <= 12) {
			collect(25);
		}
		else if (rand18 >= 13 && rand18 <= 15) {
			collect(50);
		}
		else if (rand18 >= 16 && rand18 <= 17) {
			collect(100);
		}
		else if (rand18 == 18) {
			collect(200);
		}
	}
}


