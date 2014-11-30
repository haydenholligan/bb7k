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
    double purchaseCost;
    bool mortgaged;
    Player *owner;
public:
	Building(int index, string name, double purchaseCost);
    Player *getOwner();
    double getPurchaseCost();
    double mortgage();
    void unmortgage();
	bool isMortgaged();
    virtual double getFee() = 0;
    virtual void purchase(Player *newOwner);
};

#endif