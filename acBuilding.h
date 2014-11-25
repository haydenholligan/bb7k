#ifndef __a5__acBuilding__
#define __a5__acBuilding__
#include <stdio.h>
#include "building.h"
#include <string>

class Block;

class AcademicBuilding : public Building {
    
    Block *block;
    int numImproves;
    int tuition[6];
public:
    AcademicBuilding(string name, int purchaseCost, Player *owner, Block *block, int numImproves, int tuition[6]);
    int getFee();
    ~AcademicBuilding();
};

#endif