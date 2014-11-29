#include "block.h"
#include "building.h"
#include "player.h"

Block::Block() : numBuildings(0) {}
//check buildings() for correctness


void Block::addBuilding(AcademicBuilding *ab) {
    buildings[numBuildings++] = ab;
}

bool Block::isMonopoly() {
    if (buildings[0]->getOwner()->getPiece() == buildings[1]->getOwner()->getPiece) {
        
    }
}
