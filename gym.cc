#include "gym.h"

Gym::Gym(string name, int purchaseCost) : Building(name, purchaseCost) {}

int getFee() {
    
}

void Gym::purchase(Player *newOwner) {
	Buidling::purchase(newOwner);
	newOwner->incGyms();
}