#include "residence.h"
#include "player.h"
#include <cmath>

Residence::Residence(int index, string name, int purchaseCost) : Building(index, name, purchaseCost) {}

double Residence::getFee() {
    int numRes = Building::getOwner()->getNumResidences();
    
   return 25 * pow(2, (numRes-1));
}

void Residence::purchase(Player *newOwner) {
	Building::purchase(newOwner);
	newOwner->addResidence();
}