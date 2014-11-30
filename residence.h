#ifndef __a5__residence__
#define __a5__residence__
#include <stdio.h>
#include "building.h"

class Residence : public Building {

public:
    Residence(int index, string name, int purchaseCost);
    double getFee();
    void purchase(Player *newOwner);
    ~Residence();
};

#endif 