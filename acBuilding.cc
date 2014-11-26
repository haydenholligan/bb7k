#include "acBuilding.h"

AcademicBuilding::AcademicBuilding(string name, int purchaseCost, Block *block, int numImproves, int tuition[6]) : Building(name, purchaseCost, owner), block(block), numImproves(numImproves), tuition() {}
//check tuition initialization for correctness

int AcademicBuilding::getFee() {
    
}

int AcademicBuilding::getImproveCost() {
	return improveCost;
}

void AcademicBuilding::improve() {
	numImproves++;
	// should have a check to make sure we dont go over 5 improvements
}

// override Building mortgage method
// AcademicBuildings need to sell off improvements
int AcademicBuilding::mortgage() {
	mortgaged = true;
	cash = purchaseCost / 2;
	// sell all improvements at half price
	while (numImproves > 0) {
		cash += improveCost / 2;
		numImproves--;
	}
	return cash;
}