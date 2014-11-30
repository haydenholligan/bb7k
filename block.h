#ifndef __a5__block__
#define __a5__block__
#include <stdio.h>
#include "player.h"

class AcademicBuilding;

class Block {
    int numBuildings;
    AcademicBuilding *buildings[3];
public:
	Block();
    bool isMonopoly();
    void addBuilding(AcademicBuilding *ab);
	void printBuildingList();
};

#endif