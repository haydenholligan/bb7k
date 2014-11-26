#include "residence.h"
#include "player.h"

Residence::Residence(string name, int purchaseCost) : Building(name, purchaseCost) {}

int Residence::getFee() {
    
}

void Residence::purchase(Player *newOwner) {
	Building::purchase(newOwner);
	newOwner->addResidence();
}