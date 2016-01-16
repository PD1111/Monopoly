#include "goosenesting.h"
#include "../game.h"

using namespace std;

GooseNesting::GooseNesting(Game *game, int posn)
    :NonProperty("goosenesting", posn, game){}

GooseNesting::~GooseNesting(){
}

void GooseNesting::event(){
    return;
}
