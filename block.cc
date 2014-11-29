#include "block.h"

Block::Block(int numBuildings) : numBuildings(numBuildings) {}
//check buildings() for correctness

//static int numBuildings;
//AcademicBuilding *buildings[123];

Player* Block::getOwner() {
    // todo
	return NULL;
}

void Block::addBuilding(AcademicBuilding *ab) {
    buildings[numBuildings++] = ab;
}