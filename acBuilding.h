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
    int getFee();
};

#endif