#include "building.h"
#include "../game.h"

using namespace std;

Building::Building(string name, int posn, string type)
    : name(name), posn(posn), type(type){}

Building::~Building(){
}

string Building::getName() const{
    return name;
}

string Building::getType() const{
    return type;
}

int Building::getPosn() const{
    return posn;
}
