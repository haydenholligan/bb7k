#ifndef __a5__gym__
#define __a5__gym__
#include <stdio.h>
#include "building.h"

class Gym : public Building {

public:
    Gym(int index, string name, int purchaseCost);
    int getFee();
    void purchase(Player *newOwner);
    ~Gym();
};

#endif