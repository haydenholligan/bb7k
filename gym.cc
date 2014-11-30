#include "gym.h"
#include "player.h"
#include "board.h"

Gym::Gym(int index,string name, int purchaseCost) : Building(index, name, purchaseCost) {}

int Gym::getFee() {

    int sum =  (rand() % 6 + 1) + (rand() % 6 + 1);
    int numGyms = Building::getOwner()->getNumGyms();
    
    if (numGyms == 1) {
        return sum * 4;
    }
    else if (numGyms == 2) {
        return sum * 10;
    }
    return 0;
}

void Gym::purchase(Player *newOwner) {
	Building::purchase(newOwner);

	newOwner->addGym();
}

