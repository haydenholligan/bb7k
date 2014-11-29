#ifndef __a5__player__
#define __a5__player__

// class forward declarations
class Building;
class AcademicBuilding;
class Board;

class Player {
    int pos;
    char piece;
    int money;
    int netWorth;
    int numResidences;
    int numGyms;
    int turnsInTims;
	bool hasRollupCup;
    //int numBuildings;
    //Building *buildings[29];
public:
    Player(char piece);
	int getPos();
    void move(int x);
    void purchase(Building *b);
    void addResidence();
    void addGym();
    void improve(AcademicBuilding *ab);
	void unimprove(AcademicBuilding *ab);
    int getNumResidences();
    int getNumGyms();
    void mortgage(Building *b);
    void unmortgage(Building *b);
    int getBalance();
    char getPiece();
    void roll();
    void skip();
	void giveRollupCup();
    void goToTims();
    void tryToLeaveTims();
    void payTution();
    void SLC(Board *board);
    void NeedlesHall(Board *board);
};
#endif