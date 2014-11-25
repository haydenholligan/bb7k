#include "player.h"

void Player::move(int x) {
  pos += x;
}

void Player::moveTo(int newPos) {
  pos = newPos;
}

void Player::purchase(Building *b) { 
  int result = money - b->getPurchaseCost();
  if (result >= 0) {
  	money = result;
  	b->setOwner(this); // set the owner to be THIS player
  } else {
  	// insuficient funds!!
  }
}

void Player::improve(AcademicBuilding *ab) { 

}

int Player::getNumResidences() { 

}

int Player::getNumGyms() { 

}

void Player::mortgage(Building *b) { 

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

void Player::pay(int amount) { 

}

void Player::collect(int amount) { 

}

void Player::geeseAttack() { 

}

void Player::leaveTims() { 

}

void Player::useRollupCup() { 

}
