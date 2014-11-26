#include "gym.h"
#include "player.h"

Gym::Gym(string name, int purchaseCost) : Building(name, purchaseCost) {}

int Gym::getFee() {
<<<<<<< HEAD
    int die1 = PRNG::prng(1,6);
    int die2 = PRNG::prng(1,6);
    int sum = die1+die2;
    int numGyms = Building::getOwner()->getNumGyms();
    
    if (numGyms == 1) {
        return sum * 4;
    }
    else if (numGyms == 2) {
        return sum * 10;
    }
    return 0;
=======
	
>>>>>>> FETCH_HEAD
}

void Gym::purchase(Player *newOwner) {
	Building::purchase(newOwner);

	newOwner->addGym();
}

