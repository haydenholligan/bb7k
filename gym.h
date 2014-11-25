#ifndef __a5__gym__
#define __a5__gym__
#include <stdio.h>
#include "building.h"

class Gym : Building{

public:
    Gym(string name, int purchaseCost, Player *owner);
    int getFee();
    ~Gym();
};

#endif