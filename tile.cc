#include "tile.h"
using namespace std;

Tile::Tile(int index, string name) : index(index), name(name) {}

string Tile::getName() {
	return name;
}

