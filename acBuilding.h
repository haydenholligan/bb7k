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
    AcademicBuilding(int index, string name, int purchaseCost, int improveCost, Block *block);
    void setTuition(int l0, int l1, int l2, int l3, int l4, int l5);
    int getFee();
    int getImproveCost();
    void improve();
    int mortgage();
    ~AcademicBuilding();
};

#endif