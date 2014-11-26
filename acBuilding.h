#ifndef __a5__acBuilding__
#define __a5__acBuilding__
#include <stdio.h>
#include "building.h"
#include <string>

class Block;

class AcademicBuilding : public Building {
    
    Block *block;
    int improveCost;
    int numImproves;
    int tuition[6];
public:
    AcademicBuilding(string name, int purchaseCost, int improveCost, Block *block, int tuition[6]);
    int getFee();
    int getImproveCost();
    void improve();
    int mortgage();
    ~AcademicBuilding();
};

#endif