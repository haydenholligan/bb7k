#ifndef __a5__tile__
#define __a5__tile__
#include <string>
using namespace std;

class Tile {
protected:
	int index;
	string name;
public:
	Tile(int index, string name);
	string getName();
	int getIndex();
};

#endif