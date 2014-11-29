#include "board.h"
#include "block.h"
#include "building.h"
#include "acBuilding.h"
#include "residence.h"
#include "gym.h"
#include <cstdlib>
#include <ctime>

Board::Board() {
	srand(time(NULL)); // init random number generator

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
	AcademicBuilding *AL = new AcademicBuilding("AL", 40, 50, Arts1);
	AL->setTuition(2, 10, 30, 90, 160, 250);
	AcademicBuilding *ML = new AcademicBuilding("ML", 60, 50, Arts1);
	ML->setTuition(4, 20, 60, 180, 320, 450);

	AcademicBuilding *ECH = new AcademicBuilding("ECH", 100, 50, Arts2);
	ECH->setTuition(6, 30, 90, 270, 400, 550);
	AcademicBuilding *PAS = new AcademicBuilding("PAS", 100, 50, Arts2);
	PAS->setTuition(6, 30, 90, 270, 400, 550);
	AcademicBuilding *HH = new AcademicBuilding("HH", 120, 50, Arts2);
	HH->setTuition(8, 40, 100, 300, 450, 600);

	AcademicBuilding *RCH = new AcademicBuilding("RCH", 140, 100, Eng);
	RCH->setTuition(10, 50, 150, 450, 625, 750);
	AcademicBuilding *DWE = new AcademicBuilding("DWE", 160, 100, Eng);
	DWE->setTuition(10, 50, 150, 450, 625, 750);
	AcademicBuilding *CPH = new AcademicBuilding("CPH", 180, 100, Eng);
	CPH->setTuition(12, 60, 180, 500, 700, 900);

	AcademicBuilding *LHI = new AcademicBuilding("LHI", 180, 100, Health);
	LHI->setTuition(14, 70, 200, 550, 750, 950);
	AcademicBuilding *BMH = new AcademicBuilding("BMH", 180, 100, Health);
	BMH->setTuition(14, 70, 200, 550, 750, 950);
	AcademicBuilding *OPT = new AcademicBuilding("OPT", 200, 100, Health);
	OPT->setTuition(16, 80, 220, 600, 800, 1000);

	AcademicBuilding *EV1 = new AcademicBuilding("EV1", 220, 150, Env);
	EV1->setTuition(18, 90, 250, 700, 875, 1050);
	AcademicBuilding *EV2 = new AcademicBuilding("EV2", 220, 150, Env);
	EV2->setTuition(18, 90, 250, 700, 875, 1050);
	AcademicBuilding *EV3 = new AcademicBuilding("EV3", 250, 150, Env);
	EV3->setTuition(20, 100, 300, 750, 925, 1100);

	AcademicBuilding *PHYS = new AcademicBuilding("PHYS", 260, 150, Sci1);
	PHYS->setTuition(22, 110, 330, 800, 975, 1150);
	AcademicBuilding *B1 = new AcademicBuilding("B1", 260, 150, Sci1);
	B1->setTuition(22, 110, 330, 800, 975, 1150);
	AcademicBuilding *B2 = new AcademicBuilding("B2", 280, 150, Sci1);
	B2->setTuition(24, 120, 360, 850, 1025, 1200);

	AcademicBuilding *EIT = new AcademicBuilding("EIT", 300, 200, Sci2);
	EIT->setTuition(26, 130, 390, 900, 1100, 1275);
	AcademicBuilding *ESC = new AcademicBuilding("ESC", 300, 200, Sci2);
	ESC->setTuition(26, 130, 390, 900, 1100, 1275);
	AcademicBuilding *C2 = new AcademicBuilding("C2", 320, 200, Sci2);
	C2->setTuition(28, 150, 450, 1000, 1200, 1400);

	AcademicBuilding *MC = new AcademicBuilding("MC", 350, 200, Math);
	MC->setTuition(35, 175, 500, 1100, 1300, 1500);
	AcademicBuilding *DC = new AcademicBuilding("DC", 400, 200, Math);
	DC->setTuition(50, 200, 600, 1400, 1700, 2000);

	board[0] = new Tile(0, "COLLECT OSAP");
	board[1] = AL;
	board[2] = new Tile(2, "SLC");
	board[3] = ML; 
	board[4] = new Tile(4, "TUITION");
	board[5] = new Residence("MKV", 200);
	board[6] = ECH;
	board[7] = new Tile(7, "NEEDLES HALL");
	board[8] = PAS;
	board[9] = HH;
	board[10] = new Tile(10, "DC Tims");
	board[11] = RCH;
	board[12] = new Gym("PAC", 150);
	board[13] = DWE;
	board[14] = CPH;
	board[15] = new Residence("UWP", 200);
	board[16] = LHI;
	board[17] = new Tile(17, "SLC");
	board[18] = BMH;
	board[19] = OPT;
	board[20] = new Tile(20, "Goose Nesting");
	board[21] = EV1;
	board[22] = new Tile(22, "NEEDLES HALL");
	board[23] = EV2;
	board[24] = EV3;
	board[25] = new Residence("V1", 200);
	board[26] = PHYS;
	board[27] = B1;
	board[28] = new Gym("CIF", 150);
	board[29] = B2;
	board[30] = new Tile(30, "GO TO TIMS");
	board[31] = EIT;
	board[32] = ESC;
	board[33] = new Tile(33, "SLC");
	board[34] = C2;
	board[35] = new Residence("REV", 200);
	board[36] = new Tile(36, "NEEDLES HALL");
	board[37] = MC;
	board[38] = new Tile(38, "COOP FEE");
	board[39] = DC;

	// fuck yea



}



int Board::roll() {
	return (rand() % 6 + 1) + (rand() % 6 + 1);
}

void Board::loadGame(string file) {
    
}

void Board::saveGame(string file) {
    
}

Player *Board::nextPlayer() {

}

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