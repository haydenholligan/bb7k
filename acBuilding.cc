#include "acBuilding.h"

AcademicBuilding::AcademicBuilding(string name, int purchaseCost, Player *owner, Block *block, int numImproves, int tuition[6]) : Building(name, purchaseCost, owner), block(block), numImproves(numImproves), tuition() {}
//check tuition initialization for correctness

//string name;
//int purchaseCost;
//Player *owner = NULL;

Player *getOwner() {
    
}

int getPurchaseCost() {
    
}

int getFee() {
    
}