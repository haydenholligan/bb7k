#include "acBuilding.h"

AcademicBuilding::AcademicBuilding(string name, int purchaseCost, int improveCost, Block *block) : Building(name, purchaseCost),  improveCost(improveCost), block(block), numImproves(0) {}

void setTuition(int l1, int l2, int l3, int l4, int l5) {
	tuition[0] = l1;
	tuition[1] = l2;
	tuition[2] = l3;
	tuition[3] = l4;
	tuition[4] = l5;
}

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