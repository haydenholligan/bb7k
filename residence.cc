#include "residence.h"

Residence::Residence(string name, int purchaseCost) : Building(name, purchaseCost) {}

int getFee() {
    
}

void Residence::purchase(Player *newOwner) {
	Building::purchase(newOwner);
	newOwner->incResidences();
}