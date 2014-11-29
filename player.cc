#include "player.h"
#include "building.h"
#include "acBuilding.h"
#include "prng.h"
#include "board.h"

Player::Player(char piece) : pos(0), piece(piece), money(1500), numResidences(0), numGyms(0), turnsInTims(0) {}


void Player::pay(int amount) { 
  money -= amount;
}

void Player::collect(int amount) { 
  money += amount;
}

void Player::move(int x) {
  int newPos = pos + x;
  if (newPos >= 40) {
    newPos -= 40;
    collect(200); // pass collect OSAP
  }
  pos = newPos;
}

void Player::purchase(Building *b) { 
  int result = money - b->getPurchaseCost();
  if (result >= 0) {
  	money = result;
  	b->purchase(this);
  } else {
  	// insufficient funds
  }
}

void Player::improve(AcademicBuilding *ab) { 
	int result = money - ab->getImproveCost();
	if (result >= 0) {
		money = result;
		ab->improve();
	} else {
		// insufficient funds
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
	money += b->mortgage();
}

void Player::unmortgage(Building *b) { 
  int cost = b->getPurchaseCost();
  int result = money - ((cost / 2) + (0.10 * cost));
  if (result >= 0) {
    money = result;
    b->unmortgage();
  }
}

int Player::getBalance() { 
  return money;
}

char Player::getPiece() { 
  return piece;
}

void Player::roll() { 
  move(Board::roll());
}

void Player::skip() { 

}

void Player::goToTims() { 
  pos = 10; // 10th tile is DC Tims Line
  turnsInTims++;
}

void Player::tryToLeaveTims() { 
  if (turnsInTims >= 4) {
    turnsInTims = 0;
    roll();
  } else {
    turnsInTims++;
    // stuck in Tims for this turn
  }
  // player can also use rollup cup to escape Tims
  // TODO
}

void Player::SLC() {
    int oldPos = pos;
    int newPos = rand() % 39;
    int numMoved;
    
    if (oldPos < newPos) {
        numMoved = newPos - oldPos;
        move (newPos);
    }
    else if (oldPos >= pos) {
        
    }
}

void Player::NeedlesHall() {
    
}



