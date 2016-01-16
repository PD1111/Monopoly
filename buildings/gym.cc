#include "gym.h"
#include "../game.h"
#include "../player.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

Gym::Gym(string name, int posn, Game *game)
    :Property(name,posn,"gym",game, 150){
    owner = NULL;
    mortgaged = false;
}

Gym::~Gym(){
}

int Gym::getPayment(){
    cout << "You moved to " << getOwner()->getName() << "'s gym." << endl;
    string response;
    while (1) {
        cout << "Please roll" << endl;
        cin >> response;
        if (response == "roll") break;
    }
    int dice1, dice2;
    if (game->getTesting()) {
        string nline;
        getline(cin, nline);
        if (nline != "") {
            istringstream iss(nline);
            iss>>dice1>>dice2;
            cout<<"You have rolled dice1 : "<<dice1<<" dice2 :"<<dice2<<endl;
        } else {
            srand(time(NULL));
            dice1 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;
            cout<<"You have rolled dice1 : "<<dice1<<" dice2 :"<<dice2<<endl;
        }
    } else {
        srand(time(NULL));
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        cout<<"You have rolled dice1 : "<<dice1<<" dice2 :"<<dice2<<endl;
    }


    int dice = dice1 + dice2;
    int c = owner->countMonopoly("gym"); // count
    if (c == 1) return 4 * dice;
    return 10 * dice;
}

void Gym::event(){
    if (owner == game->getCurrentPlayer()) return;
    if (owner == NULL) {
        game->purchaseNotify(this);
    } else if (mortgaged) {
        return;
    } else {
        double pay = (double) getPayment();
        game->payMoney(pay, "current", owner->getName());
    }
}
