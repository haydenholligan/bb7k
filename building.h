#ifndef __a5__building__
#define __a5__building__
#include <stdio.h>
#include <string>
#include <iostream>
#include "tile.h"
using namespace std;

class Player; // forward declaration

class Building : public Tile {
protected:
    int purchaseCost;
    bool mortgaged;
    Player *owner;
public:
	Building(int index, string name, int purchaseCost);
    Player *getOwner();
    int getPurchaseCost();
    int mortgage();
    void unmortgage();
    virtual int getFee() = 0;
    virtual void purchase(Player *newOwner);
};

#endif