#ifndef __a5__player__
#define __a5__player__

// class forward declarations
class Building;
class AcademicBuilding;

class Player {
    int pos;
    char piece;
    int money;
    int numResidences;
    int numGyms;
    int turnsInTims;
public:
    Player(char piece);
    void pay(int amount);
    void collect(int amount);
    void move(int x);
    void purchase(Building *b);
    void addResidence();
    void addGym();
    void improve(AcademicBuilding *ab);
    int getNumResidences();
    int getNumGyms();
    void mortgage(Building *b);
    void unmortgage(Building *b);
    int getBalance();
    char getPiece();
    void roll();
    void skip();
    void goToTims();
    void tryToLeaveTims();
    void SLC();
    void NeedlesHall();
};
#endif