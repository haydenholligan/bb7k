#include "board.h"
#include <cstdlib>
#include <ctime>

//Tile *board[40];
//Player *players[123];
//Player *rollUp[4];

Board::Board() {
	srand(time(NULL)); // init random number generator
}

int Board::roll() {
	return (rand() % 6 + 1) + (rand() % 6 + 1);
}

void loadGame(string file) {
    
}

void saveGame(string file) {
    
}

Player *nextPlayer();

void giveRollupCup(Player *p) {
    
}

void SLC(Player *p) {
    
}

void NeedlesHall(Player *p) {
    
}

void reDraw() {
    
}

void exec(string command) {
    
}