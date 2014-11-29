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

void Board::giveRollupCup(Player *p) {
    if (rollUp[0] == NULL) {
        rollUp[0] = p;
    }
}

void Board::SLC(Player *p) {
    
}

void Board::NeedlesHall(Player *p) {
    
}

void Board::reDraw() {
    
}

void Board::exec(string command) {
    
}