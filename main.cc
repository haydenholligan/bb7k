#include <iostream>
#include "board.h"
#include "block.h"
#include "player.h"
#include "tile.h"
#include "building.h"
#include "acBuilding.h"
#include "gym.h"
#include "residence.h"

int main() {
  
  Board board;
  
  // here are the monopoly blocks
  Block Arts1, Arts2, Eng, Health, Env, Sci1, Sci2, Math;

  // create buildings
  AcademicBuilding AL("AL", 40, 50, &Arts1);
  AL.setTuition(2, 10, 30, 90, 160, 250);
  AcademicBuilding ML("ML", 60, 50, &Arts1);
  ML.setTuition(4, 20, 60, 180, 320, 450);

  AcademicBuilding ECH("ECH", 100, 50, &Arts2);
  ECH.setTuition(6, 30, 90, 270, 400, 550);
  AcademicBuilding PAS("PAS", 100, 50, &Arts2);
  PAS.setTuition(6, 30, 90, 270, 400, 550);
  AcademicBuilding HH("HH", 120, 50, &Arts2);
  HH.setTuition(8, 40, 100, 300, 450, 600);

  AcademicBuilding RCH("RCH", 140, 100, &Eng);
  RCH.setTuition(10, 50, 150, 450, 625, 750);
  AcademicBuilding DWE("DWE", 160, 100, &Eng);
  DWE.setTuition(10, 50, 150, 450, 625, 750);
  AcademicBuilding CPH("CPH", 180, 100, &Eng);
  CPH.setTuition(12, 60, 180, 500, 700, 900);

  AcademicBuilding LHI("LHI", 180, 100, &Health);
  LHI.setTuition(14, 70, 200, 550, 750, 950);
  AcademicBuilding BMH("BMH", 180, 100, &Health);
  BMH.setTuition(14, 70, 200, 550, 750, 950);
  AcademicBuilding OPT("OPT", 200, 100, &Health);
  OPT.setTuition(16, 80, 220, 600, 800, 1000);

  AcademicBuilding EV1("EV1", 220, 150, &Env);
  EV1.setTuition(18, 90, 250, 700, 875, 1050);
  AcademicBuilding EV2("EV2", 220, 150, &Env);
  EV2.setTuition(18, 90, 250, 700, 875, 1050);
  AcademicBuilding EV3("EV3", 250, 150, &Env);
  EV3.setTuition(20, 100, 300, 750, 925, 1100);

  AcademicBuilding PHYS("PHYS", 260, 150, &Sci1);
  PHYS.setTuition(22, 110, 330, 800, 975, 1150);
  AcademicBuilding B1("B1", 260, 150, &Sci1);
  B1.setTuition(22, 110, 330, 800, 975, 1150);
  AcademicBuilding B2("B2", 280, 150, &Sci1);
  B2.setTuition(24, 120, 360, 850, 1025, 1200);

  AcademicBuilding EIT("EIT", 300, 200, &Sci2);
  EIT.setTuition(26, 130, 390, 900, 1100, 1275);
  AcademicBuilding ESC("ESC", 300, 200, &Sci2);
  ESC.setTuition(26, 130, 390, 900, 1100, 1275);
  AcademicBuilding C2("C2", 320, 200, &Sci2);
  C2.setTuition(28, 150, 450, 1000, 1200, 1400);

  AcademicBuilding MC("MC", 350, 200, &Math);
  MC.setTuition(35, 175, 500, 1100, 1300, 1500);
  AcademicBuilding DC("DC", 400, 200, &Math);
  DC.setTuition(50, 200, 600, 1400, 1700, 2000);

}
