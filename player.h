#ifndef __a5__player__
#define __a5__player__

// class forward declarations
class Building;
class AcademicBuilding;

class Player {
    int pos;
    char piece;
    int money;
    int netWorth;
    int numResidences;
    int numGyms;
    int turnsInTims;
    //int numBuildings;
    //Building *buildings[29];
public:
    Player(char piece);
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
    void payTution();
    void SLC();
    void NeedlesHall();
};
#endif