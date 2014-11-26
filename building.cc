#include "building.h"

Building::Building(string name, int purchaseCost) : name(name), purchaseCost(purchaseCost), owner(NULL), mortgaged(false) {}

Player* Building::getOwner() {
    return owner;
}

int Building::getPurchaseCost() {
    return purchaseCost;
}

int Building::mortgage() {
	mortgaged = true;
	return purchaseCost / 2;
}

void Building::purchase(Player *newOwner) {
	owner = newOwner;
}