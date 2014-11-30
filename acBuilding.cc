#include "acBuilding.h"
#include "block.h"

AcademicBuilding::AcademicBuilding(int index, string name, double purchaseCost, double improveCost, Block *block) : Building(index, name, purchaseCost),  improveCost(improveCost), block(block), numImproves(0) {
	block->addBuilding(this);
}

void AcademicBuilding::setTuition(int l0, int l1, int l2, int l3, int l4, int l5) {
	tuition[0] = l0;
	tuition[1] = l1;
	tuition[2] = l2;
	tuition[3] = l3;
	tuition[4] = l4;
	tuition[5] = l5;
}

double AcademicBuilding::getFee() {
    return tuition[numImproves];
}

double AcademicBuilding::getImproveCost() {
	return improveCost;
}

int AcademicBuilding::getNumImproves() {
	return numImproves;
}

void AcademicBuilding::improve() {
    if (numImproves == 5) {
        cerr << "Error: Reached maximum number of improvements" << endl;
        
    }
    else if (numImproves <5) {
	numImproves++;
    }
}

void AcademicBuilding::unimprove() {
	numImproves--;
}

// override Building mortgage method
// AcademicBuildings need to sell off improvements
double AcademicBuilding::mortgage() {
	double cash = Building::mortgage();
	// sell all improvements at half price
	while (numImproves > 0) {
		cash += improveCost / 2;
		numImproves--;
	}
	return cash;
}