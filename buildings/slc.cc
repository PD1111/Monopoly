#include "slc.h"
#include "../game.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

SLC::SLC(Game *game, int posn)
    :NonProperty("slc", 23, game){}

SLC::~SLC(){
}

void SLC::event(){
    srand(time(NULL));
    if (!game->maxRimCup()){ // if there is still RimCup available
        int prob = rand() % 100 + 1;
        if (prob == 88) {    // 1% probability to receive rim cup
            game->receiveRimCup();
            return;
        }
    }

    int prob = rand() % 24 + 1;
    int steps = 0;
    if (prob >= 1 && prob <= 3) steps = -3;
    if (prob >= 4 && prob <= 7) steps = -2;
    if (prob >= 8 && prob <= 11) steps = -1;
    if (prob >= 12 && prob <= 14) steps = 1;
    if (prob >= 15 && prob <= 18) steps = 2;
    if (prob >= 19 && prob <= 22) steps = 3;
    if (prob == 23) {
        cout << "You are at SLC. You are moving to DC Tims Line..." << endl;
        game->timsNoify();
    }
    else if (prob == 24) {
        cout << "You are at SLC. You are moving to OSAP..." << endl;
        game->osapNotify();
    }
    else {
        cout << "You are at SLC. You will move " << steps << endl;
        game->move(steps);
    }

}
