#include "dctims.h"
#include "../game.h"

using namespace std;

DCTims::DCTims(Game *game, int posn)
    :NonProperty("dctims", posn, game){}

DCTims::~DCTims(){
}

void DCTims::event(){
    game->tims();
}
