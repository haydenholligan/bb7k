#ifndef __a5__block__
#define __a5__block__
#include <stdio.h>
#include "player.h"

class AcademicBuilding;

class Block {
    int numBuildings;
    AcademicBuilding *buildings[123];
public:
    Block(int numBuildings, AcademicBuilding *buildings[123]);
    Player *getOwner();
    void addBuilding(AcademicBuilding *ab);
    Block();
};

#endif