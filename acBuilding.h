#ifndef __a5__acBuilding__
#define __a5__acBuilding__
#include <stdio.h>
#include "building.h"
#include <string>

class Block;

class AcademicBuilding : public Building {
    
    Block *block;
    double improveCost;
    int numImproves;
    int tuition[6];
public:
    AcademicBuilding(int index, string name, double purchaseCost, double improveCost, Block *block);
    void setTuition(int l0, int l1, int l2, int l3, int l4, int l5);
    double getFee();
    double getImproveCost();
    void improve();
    double mortgage();
    ~AcademicBuilding();
};

#endif