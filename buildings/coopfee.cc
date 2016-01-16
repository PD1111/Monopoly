#include "coopfee.h"
#include "../game.h"

using namespace std;

CoopFee::CoopFee(Game *game, int posn)
    :NonProperty("coopfee", posn, game){}

CoopFee::~CoopFee(){
}

void CoopFee::event(){
    game->payMoney((double) 150, "current", "bank");
}
