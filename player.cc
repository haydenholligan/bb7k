#include <cstdlib>
#include "player.h"
#include "building.h"
#include "acBuilding.h"
#include "block.h"
#include "board.h"

Player::Player(char piece, int playerIndex) : pos(0), piece(piece), playerIndex(playerIndex), money(1500), numResidences(0), numGyms(0), turnsInTims(0), netWorth(1500), hasRollupCup(false) {}


int Player::getPos() {
	return pos;
}

int Player::getPlayerIndex() {
	return playerIndex;
}

int Player::move(int x) {
	int newPos = pos + x;
	if (newPos >= 40) {
		newPos -= 40;
		money += 200;
		netWorth += 200;
	}
	if (newPos < 0) {
		newPos += 40;
	}
	pos = newPos;
	return newPos;
}

void Player::pay(double amount) {
	cout << "Player " << piece << ": " << money << " - " << amount << " = " << money - amount << endl;
	money -= amount;
	netWorth -= amount;
}

void Player::collect(double amount) {
	cout << "Player " << piece << ": " << money << " + " << amount << " = " << money + amount << endl;
	money += amount;
	netWorth += amount;
}

void Player::purchase(Building *b) {
	pay(b->getPurchaseCost());
	b->purchase(this);
}

void Player::improve(AcademicBuilding *ab, bool buy) {
	if (ab->getOwner()->getPlayerIndex() == this->playerIndex && ab->getBlock()->isMonopoly()) {
		if (ab->getNumImproves() <= 4) {
			pay(ab->getImproveCost());
			ab->improve();
		}
		else {
			cout << "Cannot improve " << ab->getName() << " any more (max 5 improvements)." << endl;
		}
	}
	else {
		cout << "You cannot buy/sell improvements for " << ab->getName() << " since you do not own all the buildings in its Monopoly Block." << endl;
		ab->getBlock()->printBuildingList();
	}
}

//void Player::unimprove(AcademicBuilding *ab) {
//	int numImproves = ab->getNumImproves();
//	if (numImproves > 0) {
//		collect(ab->getImproveCost() / 2);
//		ab->unimprove();
//	}
//}

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
	double mortgageVal = b->mortgage();
	money += mortgageVal;
	netWorth += mortgageVal;
}

void Player::unmortgage(Building *b) {
	double cost = b->getPurchaseCost();

	double price = (cost / 2) + (0.10 * cost);
	double result = money - price;
	if (result >= 0) {
		money = result;
		netWorth -= price;
		b->unmortgage();
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

void Player::skip() {

}

void Player::giveRollupCup() {
	hasRollupCup = true;
}

void Player::goToTims() {
	pos = 10; // 10th tile is DC Tims Line
	turnsInTims++;
}

void Player::tryToLeaveTims() {
	if (turnsInTims >= 4) {
		turnsInTims = 0;
		// player takes turn
	}
	else {
		turnsInTims++;
		// stuck in Tims for this turn
	}
	// player can also use rollup cup or pay money to escape Tims
	//adjust net worth
	// TODO
}

void Player::payTution(int option) {
	if (option == 1) {
		pay(300);
	}
	else if (option == 2) {
        pay(netWorth);
	}
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


