#include "osap.h"
#include "../game.h"

using namespace std;

OSAP::OSAP(Game *game, int posn)
    :NonProperty("OSAP", posn, game){}

OSAP::~OSAP(){
}

void OSAP::event(){
    game->addMoney(200);
}
