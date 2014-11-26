#ifndef __a5__residence__
#define __a5__residence__
#include <stdio.h>
#include "building.h"

class Residence : public Building {

public:
    Residence(string name, int purchaseCost);
    int getFee();
    void purchase(Player *newOwner);
    ~Residence();
};

#endif 