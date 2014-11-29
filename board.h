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
    Player *players[123];
    Player *rollUp[4];
public:
    Board();
    static int roll();
    void loadGame(string file);
    void saveGame(string file);
    Player *nextPlayer();
    static bool giveRollupCup(Player *p);
    
    void reDraw();
    void exec(string command);
};

#endif 