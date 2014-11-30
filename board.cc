#include "board.h"
#include "block.h"
#include "building.h"
#include "acBuilding.h"
#include "residence.h"
#include "gym.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include "vector.h"

Board::Board() {
	numPlayers = 0;
	iterator = 0;

	srand(time(0)); // init random number generator

	// here are the monopoly blocks
	Block *Arts1 = new Block;
	Block *Arts2 = new Block;
	Block *Eng = new Block;
	Block *Health = new Block;
	Block *Env = new Block;
	Block *Sci1 = new Block;
	Block *Sci2 = new Block;
	Block *Math = new Block;

	// create buildings
	AcademicBuilding *AL = new AcademicBuilding(1, "AL", 40, 50, Arts1);
	AL->setTuition(2, 10, 30, 90, 160, 250);
	AcademicBuilding *ML = new AcademicBuilding(3, "ML", 60, 50, Arts1);
	ML->setTuition(4, 20, 60, 180, 320, 450);

	AcademicBuilding *ECH = new AcademicBuilding(6, "ECH", 100, 50, Arts2);
	ECH->setTuition(6, 30, 90, 270, 400, 550);
	AcademicBuilding *PAS = new AcademicBuilding(8, "PAS", 100, 50, Arts2);
	PAS->setTuition(6, 30, 90, 270, 400, 550);
	AcademicBuilding *HH = new AcademicBuilding(9, "HH", 120, 50, Arts2);
	HH->setTuition(8, 40, 100, 300, 450, 600);

	AcademicBuilding *RCH = new AcademicBuilding(11, "RCH", 140, 100, Eng);
	RCH->setTuition(10, 50, 150, 450, 625, 750);
	AcademicBuilding *DWE = new AcademicBuilding(13, "DWE", 160, 100, Eng);
	DWE->setTuition(10, 50, 150, 450, 625, 750);
	AcademicBuilding *CPH = new AcademicBuilding(14, "CPH", 180, 100, Eng);
	CPH->setTuition(12, 60, 180, 500, 700, 900);

	AcademicBuilding *LHI = new AcademicBuilding(16, "LHI", 180, 100, Health);
	LHI->setTuition(14, 70, 200, 550, 750, 950);
	AcademicBuilding *BMH = new AcademicBuilding(18, "BMH", 180, 100, Health);
	BMH->setTuition(14, 70, 200, 550, 750, 950);
	AcademicBuilding *OPT = new AcademicBuilding(19, "OPT", 200, 100, Health);
	OPT->setTuition(16, 80, 220, 600, 800, 1000);

	AcademicBuilding *EV1 = new AcademicBuilding(21, "EV1", 220, 150, Env);
	EV1->setTuition(18, 90, 250, 700, 875, 1050);
	AcademicBuilding *EV2 = new AcademicBuilding(23, "EV2", 220, 150, Env);
	EV2->setTuition(18, 90, 250, 700, 875, 1050);
	AcademicBuilding *EV3 = new AcademicBuilding(24, "EV3", 250, 150, Env);
	EV3->setTuition(20, 100, 300, 750, 925, 1100);

	AcademicBuilding *PHYS = new AcademicBuilding(26, "PHYS", 260, 150, Sci1);
	PHYS->setTuition(22, 110, 330, 800, 975, 1150);
	AcademicBuilding *B1 = new AcademicBuilding(27, "B1", 260, 150, Sci1);
	B1->setTuition(22, 110, 330, 800, 975, 1150);
	AcademicBuilding *B2 = new AcademicBuilding(29, "B2", 280, 150, Sci1);
	B2->setTuition(24, 120, 360, 850, 1025, 1200);

	AcademicBuilding *EIT = new AcademicBuilding(31, "EIT", 300, 200, Sci2);
	EIT->setTuition(26, 130, 390, 900, 1100, 1275);
	AcademicBuilding *ESC = new AcademicBuilding(32, "ESC", 300, 200, Sci2);
	ESC->setTuition(26, 130, 390, 900, 1100, 1275);
	AcademicBuilding *C2 = new AcademicBuilding(34, "C2", 320, 200, Sci2);
	C2->setTuition(28, 150, 450, 1000, 1200, 1400);

	AcademicBuilding *MC = new AcademicBuilding(37, "MC", 350, 200, Math);
	MC->setTuition(35, 175, 500, 1100, 1300, 1500);
	AcademicBuilding *DC = new AcademicBuilding(39, "DC", 400, 200, Math);
	DC->setTuition(50, 200, 600, 1400, 1700, 2000);

	board[0] = new Tile(0, "COLLECT OSAP");
	board[1] = AL;
	board[2] = new Tile(2, "SLC");
	board[3] = ML; 
	board[4] = new Tile(4, "TUITION");
	board[5] = new Residence(5, "MKV", 200);
	board[6] = ECH;
	board[7] = new Tile(7, "NEEDLES HALL");
	board[8] = PAS;
	board[9] = HH;
	board[10] = new Tile(10, "DC Tims");
	board[11] = RCH;
	board[12] = new Gym(12, "PAC", 150);
	board[13] = DWE;
	board[14] = CPH;
	board[15] = new Residence(15, "UWP", 200);
	board[16] = LHI;
	board[17] = new Tile(17, "SLC");
	board[18] = BMH;
	board[19] = OPT;
	board[20] = new Tile(20, "Goose Nesting");
	board[21] = EV1;
	board[22] = new Tile(22, "NEEDLES HALL");
	board[23] = EV2;
	board[24] = EV3;
	board[25] = new Residence(25, "V1", 200);
	board[26] = PHYS;
	board[27] = B1;
	board[28] = new Gym(28, "CIF", 150);
	board[29] = B2;
	board[30] = new Tile(30, "GO TO TIMS");
	board[31] = EIT;
	board[32] = ESC;
	board[33] = new Tile(33, "SLC");
	board[34] = C2;
	board[35] = new Residence(35, "REV", 200);
	board[36] = new Tile(36, "NEEDLES HALL");
	board[37] = MC;
	board[38] = new Tile(38, "COOP FEE");
	board[39] = DC;

	propList[0] = { -1, -1 };
	propList[1] = { 73, 51 };
	propList[2] = { -1, -1 };
	propList[3] = { 57, 51 };
	propList[4] = { -1, -1 };
	propList[5] = { -1, -1 };
	propList[6] = { 33, 51 };
	propList[7] = { -1, -1 };
	propList[8] = { 17, 51 };
	propList[9] = { 9, 51 };
	propList[10] = { -1, -1 };
	propList[11] = { 1, 46 };
	propList[12] = { -1, -1 };
	propList[13] = { 1, 36 };
	propList[14] = { 1, 31 };
	propList[15] = { -1, -1 };
	propList[16] = { 1, 21 };
	propList[17] = { -1, -1 };
	propList[18] = { 1, 11 };
	propList[19] = { 1, 6 };
	propList[20] = { -1, -1 };
	propList[21] = { 9, 1 };
	propList[22] = { -1, -1 };
	propList[23] = { 25, 1 };
	propList[24] = { 33, 1 };
	propList[25] = { -1, -1 };
	propList[26] = { 49, 1 };
	propList[27] = { 57, 1 };
	propList[28] = { -1, -1 };
	propList[29] = { 73, 1 };
	propList[30] = { -1, -1 };
	propList[31] = { 81, 6 };
	propList[32] = { 81, 11 };
	propList[33] = { -1, -1 };
	propList[34] = { 81, 21 };
	propList[35] = { -1, -1 };
	propList[36] = { -1, -1 };
	propList[37] = { 81, 36 };
	propList[38] = { -1, -1 };
	propList[39] = { 81, 46 };

	coordList[0] = { 81, 54 };
	coordList[1] = { 73, 54 };
	coordList[2] = { 65, 54 };
	coordList[3] = { 57, 54 };
	coordList[4] = { 49, 54 };
	coordList[5] = { 41, 54 };
	coordList[6] = { 33, 54 };
	coordList[7] = { 25, 54 };
	coordList[8] = { 17, 54 };
	coordList[9] = { 9, 54 };
	coordList[10] = { 1, 54 };
	coordList[11] = { 1, 49 };
	coordList[12] = { 1, 44 };
	coordList[13] = { 1, 39 };
	coordList[14] = { 1, 34 };
	coordList[15] = { 1, 29 };
	coordList[16] = { 1, 24 };
	coordList[17] = { 1, 19 };
	coordList[18] = { 1, 14 };
	coordList[19] = { 1, 9 };
	coordList[20] = { 1, 4 };
	coordList[21] = { 9, 4 };
	coordList[22] = { 17, 4 };
	coordList[23] = { 25, 4 };
	coordList[24] = { 33, 4 };
	coordList[25] = { 41, 4 };
	coordList[26] = { 49, 4 };
	coordList[27] = { 57, 4 };
	coordList[28] = { 65, 4 };
	coordList[29] = { 73, 4 };
	coordList[30] = { 81, 4 };
	coordList[31] = { 81, 9 };
	coordList[32] = { 81, 14 };
	coordList[33] = { 81, 19 };
	coordList[34] = { 81, 24 };
	coordList[35] = { 81, 29 };
	coordList[36] = { 81, 34 };
	coordList[37] = { 81, 44 };
	coordList[38] = { 81, 49 };
	coordList[39] = { 81, 54 };

    for (int i = 0; i < 88; i++) {
        for (int j = 0; j < 55; j++) {
            boardArr[i][j] = ' ';
        }
    }
    
    string tmpArr[56];
    tmpArr[0]  = "-----------------------------------------------------------------------------------------";
    tmpArr[1]  = "|Goose  |       |NEEDLES|       |       |V1     |       |       |CIF    |       |GO TO  |";
    tmpArr[2]  = "|Nesting|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |";
    tmpArr[3]  = "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |";
    tmpArr[4]  = "|       |       |       |       |       |       |       |       |       |       |       |";
    tmpArr[5]  = "|-------|-----------------------------------------------------------------------|-------|";
    tmpArr[6]  = "|       |                                                                       |       |";
    tmpArr[7]  = "|-------|                                                                       |-------|";
    tmpArr[8]  = "|OPT    |                                                                       |EIT    |";
    tmpArr[9]  = "|       |                                                                       |       |";
    tmpArr[10] = "|-------|                                                                       |-------|";
    tmpArr[11] = "|       |                                                                       |       |";
    tmpArr[12] = "|-------|                                                                       |-------|";
    tmpArr[13] = "|BMH    |                                                                       |ESC    |";
    tmpArr[14] = "|       |                                                                       |       |";
    tmpArr[15] = "|-------|                                                                       |-------|";
    tmpArr[16] = "|SLC    |                                                                       |SLC    |";
    tmpArr[17] = "|       |                                                                       |       |";
    tmpArr[18] = "|       |                                                                       |       |";
    tmpArr[19] = "|       |                                                                       |       |";
    tmpArr[20] = "|-------|                                                                       |-------|";
    tmpArr[21] = "|       |                                                                       |       |";
    tmpArr[22] = "|-------|                                                                       |-------|";
    tmpArr[23] = "|LHI    |                                                                       |C2     |";
    tmpArr[24] = "|       |                                                                       |       |";
    tmpArr[25] = "|-------|                                                                       |-------|";
    tmpArr[26] = "|UWP    |                             bb7k                                      |REV    |";
    tmpArr[27] = "|       |                        ty asad bless u                                |       |";
    tmpArr[28] = "|       |                                                                       |       |";
    tmpArr[29] = "|       |                                                                       |       |";
    tmpArr[30] = "|-------|                                                                       |-------|";
    tmpArr[31] = "|       |                                                                       |NEEDLES|";
    tmpArr[32] = "|-------|                                                                       |HALL   |";
    tmpArr[33] = "|CPH    |                                                                       |       |";
    tmpArr[34] = "|       |                                                                       |       |";
    tmpArr[35] = "|-------|                                                                       |-------|";
    tmpArr[36] = "|       |                                                                       |       |";
    tmpArr[37] = "|-------|                                                                       |-------|";
    tmpArr[38] = "|DWE    |                                                                       |MC     |";
    tmpArr[39] = "|       |                                                                       |       |";
    tmpArr[40] = "|-------|                                                                       |-------|";
    tmpArr[41] = "|PAC    |                                                                       |COOP   |";
    tmpArr[42] = "|       |                                                                       |FEE    |";
    tmpArr[43] = "|       |                                                                       |       |";
    tmpArr[44] = "|       |                                                                       |       |";
    tmpArr[45] = "|-------|                                                                       |-------|";
    tmpArr[46] = "|       |                                                                       |       |";
    tmpArr[47] = "|-------|                                                                       |-------|";
    tmpArr[48] = "|RCH    |                                                                       |DC     |";
    tmpArr[49] = "|       |                                                                       |       |";
    tmpArr[50] = "|-------|-----------------------------------------------------------------------|-------|";
    tmpArr[51] = "|DC Tims|       |       |NEEDLES|       |MKV    |TUITION|       |SLC    |       |COLLECT|";
    tmpArr[52] = "|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |";
    tmpArr[53] = "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |";
    tmpArr[54] = "|       |       |       |       |       |       |       |       |       |       |       |";
    tmpArr[55] = "-----------------------------------------------------------------------------------------";
    
    for (int a = 0; a < 56; a++) {
        string s = tmpArr[a];
        for (int i = 0; i < 89; i++) {
            boardArr[i][a] = s[i];
        }
    }

	//idk if we need this
	for (int i = 0; i < 4; i++) {
		rollUp[i] = NULL;
	}
    
}

Player* Board::addPlayer(std::string name, char piece) {
	players[numPlayers] = new Player(name, piece);
    boardArr[(coordList[0].x)+numPlayers][coordList[0].y] = players[numPlayers]->getPiece();
    numPlayers++;
	return players[numPlayers - 1];
}

 void Board::movePlayer(int tile, int oldTile) {
    //just for moving player on text-board
    boardArr[(coordList[tile].x)+iterator][coordList[tile].y] = players[iterator]->getPiece();
    boardArr[(coordList[oldTile].x)+iterator][coordList[oldTile].y] = ' ';
}

void Board::incrIterator() {
    iterator++;
}

void Board::saveGame(string file) {
    
}

Player *Board::nextPlayer() {
	if (iterator == numPlayers) iterator = 0;
	return players[iterator];
}

bool Board::giveRollupCup(Player *p) {
    for (int i = 0; i < 4; i++) {
        if (rollUp[i] == NULL) {
            rollUp[i] = p;
			p->giveRollupCup();
            return true;
        }
    }
    return false;
}

void Board::reDraw() {

    for (int i = 0; i < 56; i++) {
        for (int j = 0; j < 89; j++) {
            cout << boardArr[j][i];
        }
        cout << endl;
    }

}

void Board::exec(string command) {
    
}

Tile* Board::getTile(string name) {
	for (int i = 0; i < 40; i++) {
		if (board[i]->getName() == name) {
			return board[i];
		}
	}
	return NULL;
}

Tile* Board::getTile(int pos) {
	return board[pos];
}

Player* Board::getPlayer(string name) {
	for (int i = 0; i < numPlayers; i++) {
		if (players[i]->getName() == name) {
			return players[i];
		}
	}
	return NULL;
}

bool Board::playerExists(string name) {
	for (int i = 0; i < numPlayers; i++) {
		if (players[i]->getName() == name) return true;
	}
	return false;
}











