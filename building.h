#ifndef __a5__building__
#define __a5__building__
#include <stdio.h>
#include <string>
#include <iostream>
#include "player.h"
#include "tile.h"
#include "block.h"

using namespace std;

class Building : public Tile {
    string name;
    int purchaseCost;
    Player *owner = NULL;
public:
    Building(string name, int purchaseCost, Player *owner);
    Player *getOwner();
    int getPurchaseCost();
    virtual int getFee() = 0;
    ~Building();
};

#endif