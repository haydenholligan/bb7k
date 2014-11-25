#ifndef __a5__block__
#define __a5__block__
#include <stdio.h>
#include "acBuilding.h"
#include "player.h"

class Block {
    static int numBuildings;
    AcademicBuilding *buildings[123];
public:
    Player *getOwner();
    void addBuilding(AcademicBuilding *ab);
    
};

#endif