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
	Player *owner0 = buildings[0]->getOwner();
	Player *owner1 = buildings[1]->getOwner();
	Player *owner2 = NULL;
	if (numBuildings == 3) owner2 = buildings[2]->getOwner();
	
	if (owner0 && owner1 && owner0->getPiece() == owner1->getPiece()) {
        if (numBuildings == 2) {
            return true;
        }
        else if (numBuildings == 3) {
            if (owner2 && owner1->getPiece() == owner2->getPiece()) {
                return true;
            }
        }
        
    }
        return false;
}

void Block::printBuildingList() {
	for (int i = 0; i < numBuildings; i++) {
		cout << buildings[i]->getName() << ": ";
		Player *owner = buildings[i]->getOwner();
		if (owner) cout << owner->getName() << endl;
		else cout << " Bank" << endl;
	}
}
