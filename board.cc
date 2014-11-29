#include "board.h"
#include <cstdlib>
#include <ctime>

//Tile *board[40];
//Player *players[123];
//Player *rollUp[4];

Board::Board() : rollUp(), players() {
	srand(time(NULL)); // init random number generator
    
}

int Board::roll() {
	return (rand() % 6 + 1) + (rand() % 6 + 1);
}

void Board::loadGame(string file) {
    
}

void Board::saveGame(string file) {
    
}

Player *Board::nextPlayer();

bool Board::giveRollupCup(Player *p) {
    for (int i = 0; i < 4; i++) {
        if (rollUp[i] == NULL) {
            rollUp[i] = p;
            return true;
        }
    }
    return false;
}

void Board::reDraw() {
    
}

void Board::exec(string command) {
    
}