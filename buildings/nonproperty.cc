#include "nonproperty.h"

using namespace std;

NonProperty::NonProperty(string name, int posn, Game *game)
    : Building(name, posn, "nonproperty"){
    this->game = game;
}

NonProperty::~NonProperty(){
}
