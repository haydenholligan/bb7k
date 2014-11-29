#include "block.h"
#include "building.h"
#include "player.h"
#include "acBuilding.h"

Block::Block() : numBuildings(0) {}
//check buildings() for correctness


void Block::addBuilding(AcademicBuilding *ab) {
    buildings[numBuildings++] = ab;
}

bool Block::isMonopoly() {
    if (buildings[0]->getOwner()->getPiece() == buildings[1]->getOwner()->getPiece()) {
        if (numBuildings == 2) {
            return true;
        }
        else if (numBuildings == 3) {
            if (buildings[1]->getOwner()->getPiece() == buildings[2]->getOwner()->getPiece()) {
                return true;
            }
        }
        
    }
        return false;
}
