#include "player.h"
#include "building.h"
#include "acBuilding.h"

void Player::pay(int amount) { 
  money -= amount;
  // amount goes somewhere...
}

void Player::collect(int amount) { 
  money += amount;
  // amount comes from somewhere...
}

void Player::move(int x) {
  int newPos = pos + x;
  if (newPos >= 40) {
    newPos -= 40;
    collect(200); // pass collect OSAP
  }
  pos = newPos;
}

void Player::moveTo(int newPos) {
  pos = newPos;
}

void Player::purchase(Building *b) { 
  int result = money - b->getPurchaseCost();
  if (result >= 0) {
  	money = result;
  	b->purchase(this);
  } else {
  	// insuficient funds
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

int Player::addResidence() {
	numResidences++;
}

int Player::addGym() {
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

}

int Player::getBalance() { 

}

char Player::getPiece() { 

}

void Player::roll() { 

}

void Player::skip() { 

}

void Player::goToTims() { 

}

void Player::geeseAttack() { 

}

void Player::leaveTims() { 

}

void Player::useRollupCup() { 

}
