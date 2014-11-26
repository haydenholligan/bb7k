#include "gym.h"
#include "player.h"

Gym::Gym(string name, int purchaseCost) : Building(name, purchaseCost) {}

int getFee() {
    
}

void Gym::purchase(Player *newOwner) {
	Building::purchase(newOwner);
	newOwner->addGym();
}