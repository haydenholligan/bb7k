#ifndef __a5__board__
#define __a5__board__
#include <stdio.h>
#include "tile.h"
#include "player.h"
#include "vector.h"
#include <string>
#include <iostream>
using namespace std;

class Board {
    Tile *board[40];
	int numPlayers;
    Player *players[6];
    Player *rollUp[4];
	int iterator;
    Vector propList[40];
    Vector coordList[40];
    char boardArr[89][56];
public:
    Board();
	Tile* getTile(string name);
	Tile* getTile(int pos);
	Player* addPlayer(string name, char piece);
    void movePlayer(int tile, int oldTile);
    void incrIterator();
    void loadGame(string file);
    void saveGame(string file);
    Player *nextPlayer();
    bool giveRollupCup(Player *p);
    void reDraw();
    void exec(string command);
	bool playerExists(string name);
};

#endif 