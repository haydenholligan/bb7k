#ifndef __a5__board__
#define __a5__board__
#include <stdio.h>
#include "tile.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;

class Board {
    Tile *board[40];
	int numPlayers;
    Player *players[6];
    Player *rollUp[4];
	int iterator;
public:
    Board();
	Tile* getTile(string name);
	void addPlayer(char piece);
    static int roll();
    void loadGame(string file);
    void saveGame(string file);
    Player *nextPlayer();
    bool giveRollupCup(Player *p);
    void reDraw();
    void exec(string command);
};

#endif 