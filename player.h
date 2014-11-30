#ifndef __a5__player__
#define __a5__player__
#include <string>

// class forward declarations
class Building;
class AcademicBuilding;
class Board;

class Player {
public:
	std::string name;
	char piece;
	int pos;
    double money;
    double netWorth;
    int numResidences;
    int numGyms;
    int turnsInTims;
	bool hasRollupCup;
    Player(std::string name, char piece);
	std::string getName();
	int getPos();
    int move(int x);
	void pay(double amount);
	void collect(double amount);
    void purchase(Building *b);
    void addResidence();
    void addGym();
    void improve(AcademicBuilding *ab, bool buy);
    int getNumResidences();
    int getNumGyms();
    void mortgage(Building *b);
    void unmortgage(Building *b);
    double getBalance();
    char getPiece();
    void roll();
	void giveRollupCup();
    void goToTims();
    bool tryToLeaveTims();
    void payTution(int option);
    void SLC(Board *board);
    void NeedlesHall(Board *board);
};
#endif