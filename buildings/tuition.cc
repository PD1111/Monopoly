#include "tuition.h"
#include "../game.h"

using namespace std;

Tuition::Tuition(Game *game, int posn)
    :NonProperty("tuition", posn, game){}

Tuition::~Tuition(){
}

void Tuition::event(){
    game->tuitionNotify();
}
