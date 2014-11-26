#include "residence.h"
#include "player.h"
#include <cmath>

Residence::Residence(string name, int purchaseCost) : Building(name, purchaseCost) {}

int Residence::getFee() {
    int numRes = Building::getOwner()->getNumResidences();
    
   return 25 * pow(2, (numRes-1));
}

void Residence::purchase(Player *newOwner) {
	Building::purchase(newOwner);
	newOwner->addResidence();
}