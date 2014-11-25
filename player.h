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

    public:
    void move(int x);
    void moveTo(int newPos);
    void purchase(Building *b);
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
    void pay(int amount);
    void collect(int amount);
    void geeseAttack();
    void leaveTims();
    void useRollupCup();
};
#endif