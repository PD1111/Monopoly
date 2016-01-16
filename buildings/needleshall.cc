#include "needleshall.h"
#include "../game.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

NeedlesHall::NeedlesHall(Game *game, int posn)
    :NonProperty("needleshall", posn, game){}

NeedlesHall::~NeedlesHall(){
}

void NeedlesHall::event(){
    srand(time(NULL));
    if (!game->maxRimCup()){ // if there is still RimCup available
        int prob = rand() % 100 + 1;
        if (prob == 88) {    // 1% probability to receive rim cup
            game->receiveRimCup();
            return;
        }
    }

    int prob = rand() % 18 + 1;
    double change = 0;
    if (prob == 1) change = -200;
    if (prob >= 2 && prob <= 3) change = -100;
    if (prob >= 4 && prob <= 6) change = -50;
    if (prob >= 7 && prob <= 12) change = 25;
    if (prob >= 13 && prob <= 15) change = 50;
    if (prob >= 16 && prob <= 17) change = 100;
    if (prob == 18) change = 200;

    if (change > 0) game->addMoney(change);
    if (change < 0) game->payMoney(-1 * change, "current", "bank");
}
