#include "building.h"

Building::Building(int index, string name, double purchaseCost) : Tile(index, name), purchaseCost(purchaseCost), owner(NULL), mortgaged(false) {}

Player* Building::getOwner() {
    return owner;
}

double Building::getPurchaseCost() {
    return purchaseCost;
}

double Building::mortgage() {
	mortgaged = true;
	return purchaseCost / 2;
}

void Building::setOwner(Player *p) {
    owner = p;
}

void Building::unmortgage() {
	mortgaged = false;
}

void Building::purchase(Player *newOwner) {
	owner = newOwner;
}

bool Building::isMortgaged() {
	return mortgaged;
}

