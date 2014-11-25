#ifndef __a5__residence__
#define __a5__residence__
#include <stdio.h>
#include "building.h"

class Residence : public Building {

public:
    Residence(string name, int purchaseCost, Player *owner);
    int getFee();
    ~Residence();
};

#endif 