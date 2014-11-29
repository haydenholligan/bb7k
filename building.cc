#include "building.h"

Building::Building(int index, string name, int purchaseCost) : Tile(index, name), purchaseCost(purchaseCost), owner(NULL), mortgaged(false) {}

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

void Building::unmortgage() {
	mortgaged = false;
}

void Building::purchase(Player *newOwner) {
	owner = newOwner;
}

