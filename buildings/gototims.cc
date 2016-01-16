#include "gototims.h"
#include "../game.h"

using namespace std;

GoToTims::GoToTims(Game *game, int posn)
    :NonProperty("gototims", posn, game){}

GoToTims::~GoToTims(){
}

void GoToTims::event(){
    game->timsNoify(); // move to tims
}
