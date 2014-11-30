#include <cstdlib>
#include "player.h"
#include "building.h"
#include "acBuilding.h"
#include "board.h"

Player::Player(char piece) : pos(0), piece(piece), money(1500), numResidences(0), numGyms(0), turnsInTims(0), netWorth(1500), hasRollupCup(false) {}


int Player::getPos() {
	return pos;
}

int Player::move(int x) {
  int newPos = pos + x;
  if (newPos >= 40) {
    newPos -= 40;
      money +=200;
      netWorth +=200;
  }
  if (newPos < 0) {
      newPos +=40;
  }
  pos = newPos;
  cout << "Moved " << x << " spaces" << endl;
  return newPos;
}

void Player::purchase(Building *b) { 
  double result = money - b->getPurchaseCost();
  if (result >= 0) {
  	money = result;
  	b->purchase(this);
      //buildings[numBuildings] = b;
      //numBuildings++;
  } else {
  	// insufficient funds
  }
}

void Player::improve(AcademicBuilding *ab) { 
	double result = money - ab->getImproveCost();
	if (result >= 0) {
		money = result;
		ab->improve();
	} else {
		// insufficient funds
	}
}

void Player::unimprove(AcademicBuilding *ab) {

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
    netWorth -=price;
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
    int x =  (rand() % 6 + 1) + (rand() % 6 + 1);
    move(x);
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
    roll();
  } else {
    turnsInTims++;
    // stuck in Tims for this turn
  }
  // player can also use rollup cup or pay money to escape Tims
  //adjust net worth
  // TODO
}

void Player::payTution() {
    //wait until command
    int x = 0;
    if (x==0) {
        money -=300;
        netWorth -=300;
    }
    else if (x==1) {
        //adjust money and networth
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
            money -=200;
            netWorth -=200;
        }
        else if (rand18 >= 2 && rand18 <= 3) {
            money -=100;
            netWorth -=100;
        }
        else if (rand18 >= 4 && rand18 <= 6) {
            money -=50;
            netWorth -=50;
        }
        else if (rand18 >= 7 && rand18 <= 12) {
            money +=25;
            netWorth +=25;
        }
        else if (rand18 >= 13 && rand18 <= 15) {
            money +=50;
            netWorth +=50;
        }
        else if (rand18 >= 16 && rand18 <= 17) {
            money +=100;
            netWorth +=100;
        }
        else if (rand18 == 18) {
            money +=200;
            netWorth +=200;
        }
    }
}


