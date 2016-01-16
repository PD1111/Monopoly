#include "residence.h"
#include "../game.h"
#include "../player.h"

using namespace std;

Residence::Residence(string name, int posn, Game *game)
    :Property(name,posn,"residence",game, 200){
    owner = NULL;
    mortgaged = false;
}

Residence::~Residence(){
}

int Residence::getPayment(){
    int c = owner->countMonopoly("residence"); // count
    if (c == 1) return 25;
    if (c == 2) return 50;
    if (c == 3) return 100;
    return 200;
}

void Residence::event(){
    if (owner == NULL) {
        game->purchaseNotify(this);
    } else if (mortgaged) {
        return;
    } else {
        double pay = (double) getPayment();
        game->payMoney(pay, "current", owner->getName());
    }
}
