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
  
  Block Arts1(2);
  Block Arts2(3);
  Block Eng(3);
  Block Health(3);
  Block Env(3);
  Block Sci1(3);
  Block Sci2(3);
  Block Math(2);

  AcademicBuilding AL("AL", 40, 50, &Arts1);
  AcademicBuilding ML("ML", 60, 50, &Arts1);
  AcademicBuilding ECH("ECH", 100, 50, &Arts2);
  AcademicBuilding PAS("PAS", 100, 50, &Arts2);
  AcademicBuilding HH("HH", 120, 50, &Arts2);
  AcademicBuilding RCH("RCH", 140, 100, &Eng);
  
}
