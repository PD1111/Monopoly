#include "game.h"
#include "controller.h"
#include "player.h"
#include "./buildings/academic.h"
#include "./buildings/building.h"
#include "./buildings/coopfee.h"
#include "./buildings/dctims.h"
#include "./buildings/goosenesting.h"
#include "./buildings/gototims.h"
#include "./buildings/gym.h"
#include "./buildings/needleshall.h"
#include "./buildings/nonproperty.h"
#include "./buildings/osap.h"
#include "./buildings/property.h"
#include "./buildings/residence.h"
#include "./buildings/slc.h"
#include "./buildings/tuition.h"
#include <ctime>
#include <cstdlib>

using namespace std;

Game::Game(int num_of_player, Controller *c)
    : num_player_left(num_of_player), c(c), MAXRIM(4)
{
    avaible_rim = MAXRIM;
}

Game::~Game()
{
    for (int i = 0; i < 40; i++) {
        delete board[i];
    }

    for (map<string, Player *>::iterator i = players.begin(); i != players.end(); i++) {
        delete (*i).second;
    }
}

void Game::init(){
    current_iterator = players.begin();
    board[0] = new OSAP(this, 0);
    board[1] = new Academic("AL", "Arts1", 40, 50, 2, 10, 30, 90, 160, 250, 1, this);
    board[2] = new SLC(this, 2);
    board[3] = new Academic("ML", "Arts1", 60, 50, 4, 20, 60, 180, 320, 450, 3, this);
    board[4] = new Tuition(this, 4);
    board[5] = new Residence("MKV", 5, this);
    board[6] = new Academic("ECH", "Arts2", 100, 50, 6, 30, 90, 270,  400, 550, 6, this);
    board[7] = new NeedlesHall(this, 7);
    board[8] = new Academic("PAS", "Arts2", 100, 50, 6, 30, 90, 270, 400, 550, 8, this);
    board[9] = new Academic("HH", "Arts2", 120, 50, 8, 40, 100, 300, 450, 600, 9, this);
    board[10] = new DCTims(this, 10);
    board[11] = new Academic("RCH", "Eng", 140, 100, 10, 50, 150, 450, 625, 750, 11, this);
    board[12] = new Gym("PAC", 12, this);
    board[13] = new Academic("DWE", "Eng", 140, 100, 10, 50, 150, 450, 625, 750, 13, this);
    board[14] = new Academic("CPH", "Eng", 160, 100, 12, 60, 180, 500, 700, 900, 14, this);
    board[15] = new Residence("UWP", 15, this);
    board[16] = new Academic("LHI", "Health", 180,100, 14, 70, 200, 550, 750, 950, 16, this);
    board[17] = new SLC(this,17);
    board[18] = new Academic("BMH", "Health", 180, 100, 14, 70, 200, 550, 750, 950, 18, this);
    board[19] = new Academic("OPT", "Health", 200, 100, 16, 80, 220, 600, 800, 1000, 19, this);
    board[20] = new GooseNesting(this, 20);
    board[21] = new Academic("EV1", "Env", 220, 150, 18, 90, 250, 700, 875, 1050, 21, this);
    board[22] = new NeedlesHall(this, 22);
    board[23] = new Academic("EV2", "Env", 220, 150, 18, 90, 250, 700, 875, 1050, 23, this);
    board[24] = new Academic("EV3", "Env", 240, 150, 20, 100, 300, 750, 925, 1100, 24, this);
    board[25] = new Residence("V1", 25, this);
    board[26] = new Academic("PHYS", "Sci1", 260, 150, 22, 110, 330, 800, 975, 1150, 26, this);
    board[27] = new Academic("B1", "Sci1", 260, 150, 22, 110, 330, 800, 975, 1150, 27, this);
    board[28] = new Gym("CIF", 28, this);
    board[29] = new Academic("B2", "Sci1", 280, 150, 24, 120, 360, 850, 1025, 1200, 29, this);
    board[30] = new GoToTims(this, 30);
    board[31] = new Academic("EIT", "Sci2", 300, 200, 26, 130, 390, 900, 1100, 1275, 31, this);
    board[32] = new Academic("ESC", "Sci2", 300, 200, 26, 130, 390, 900, 1100, 1275, 32, this);
    board[33] = new SLC(this, 33);
    board[34] = new Academic("C2", "Sci2", 320, 200, 28, 150, 450, 1000, 1200, 1400, 34, this);
    board[35] = new Residence("REV", 35, this);
    board[36] = new NeedlesHall(this, 36);
    board[37] = new Academic("MC", "Math", 350, 200, 35, 175, 500, 1100, 1300, 1500, 37, this);
    board[38] = new CoopFee(this,38);
    board[39] = new Academic("DC", "Math", 400, 200, 50, 200, 600, 1400, 1700, 2000, 39, this);
}

void Game::addPlayer(string name, char symbol){
    Player *pl = new Player(name, symbol, this);
    players[name] = pl;
}

void Game::setCurrentPlayer(string name){
    current_iterator = players.find(name);
}

void Game::setPlayer(string name, char symbol, int rimcup, double money, int posn){
    Player *pl = new Player(name, symbol, this);
    players[name] = pl;
    avaible_rim -= rimcup;
    pl->setRimCup(rimcup);
    pl->setMoney(money);
    pl->setPosn(posn);
}

void Game::setPlayer(string name, char symbol, int rimcup, double money, int posn, int tims){
    Player *pl = new Player(name, symbol, this);
    players[name] = pl;
    avaible_rim -= rimcup;
    pl->setRimCup(rimcup);
    pl->setMoney(money);
    pl->setPosn(posn);
}

void Game::setPlayer(string name, char symbol, int rimcup, double money, int posn, int tims, int timscounter){
    Player *pl = new Player(name, symbol, this);
    players[name] = pl;
    avaible_rim -= rimcup;
    pl->setRimCup(rimcup);
    pl->setMoney(money);
    pl->setPosn(posn);

    if (tims == 1) {
        pl->setMoveable(false);
        pl->setTimsCounter(timscounter);
    }
}

Building *Game::lookUpBuilding(string name) const{
    for (int i = 0; i < 40; i++) {
        if (board[i]->getName() == name) return board[i];
    }
    return NULL;
}

void Game::setProperty(string building, string owner, int improvement){
    Building *b = lookUpBuilding(building);
    Property *prop = dynamic_cast<Property *>(b);
    if (prop) {
        if (!players.count(owner)) return;
        if (players.count(owner)) prop->setOwner(players[owner]);
        if (improvement == -1) {
            prop->setMortgage();
        } else {
            Academic *aca = dynamic_cast<Academic *>(prop);
            if (aca) aca->setLevel(improvement);
        }
    }
}

void Game::propertyUpdated(Property *prop){
    if (prop->isMortgage()) {
        if (prop->getType() == "academic") {
            if (prop->getOwner() == NULL) {
                c->buildingNotify(prop->getPosn(), 6, 32);
            } else {
                c->buildingNotify(prop->getPosn(), -1, prop->getOwner()->getSymbol());
            }
        } else {
            if (prop->getOwner() == NULL) {
                c->nonAcademicNotify(prop->getPosn(), 32, true);
            } else {
                c->nonAcademicNotify(prop->getPosn(), prop->getOwner()->getSymbol(), true);
            }
        }
    } else if (prop->getType() == "academic") {
        Academic *a = dynamic_cast<Academic*>(prop);
        if (prop->getOwner() == NULL) {
            c->buildingNotify(prop->getPosn(), 6, 32);
        } else {
            c->buildingNotify(prop->getPosn(), a->getLevel(), prop->getOwner()->getSymbol());
        }
    } else {
        if (prop->getOwner() == NULL) {
            c->nonAcademicNotify(prop->getPosn(), 32, false);
        } else {
            c->nonAcademicNotify(prop->getPosn(), prop->getOwner()->getSymbol(), false);
        }
    }
}

void Game::playerMoved(int prev, int cur, char sym){
    c->playerMoveNotify(prev, cur, sym);
}

void Game::playerRemoved(string player){
    c->playerRemoveNotify(players[player]->getPosn(), players[player]->getSymbol());
}

int Game::getNumPlayerLeft() const{
    return num_player_left;
}

Player *Game::getCurrentPlayer() const{
    return (*current_iterator).second;
}

bool Game::getTesting() {
    return c->getTesting();
}

void Game::payMoney(double amount, string payer, string receiver){
    Player *pl = NULL;
    if (payer == "current") {
        pl = getCurrentPlayer();
        payer = pl->getName();
    } else {
        pl = players[payer];
    }

    if (payer == receiver) return;

    while (1) {
        if (players[payer] == NULL) break; // means if the current player is bankrupt
        if (pl->payMoney(amount)) { // if pay money succeeds
            if (receiver != "bank") {
                Player *re = players[receiver];
                if (re) re->addMoney(amount);
            }
            break;
        } else {
            if (receiver == "bank") notEnoughMoney(amount, pl);
            else notEnoughMoney(amount, pl, players[receiver]);
        }
    }
}

void Game::buyImprovement(string building){
    Building *b = lookUpBuilding(building);
    Academic *aca = dynamic_cast<Academic *>(b);
    if (!aca) cout << "Wrong building. Cannot upgrade!" << endl;
    if (aca) {
        if (aca->getOwner() != getCurrentPlayer()) {
            cout << "You don't own " << aca->getName() << endl;
        } else if (aca->upgradable()) {
            if (aca->getLevel() == 5) {
                cout << building << " is already level 5. Cannot upgrade!" << endl;
            }
            double cost = aca->getImprovementCost();

            payMoney(cost, "current", "bank");
            if (getCurrentPlayer() != NULL) { // if not bankrupt
                aca->LevelUp();
            }


        } else {
            cout << "You haven't owned all the properties in the monopoly " + aca->getMonopolyBlock() << endl;
        }
    }
}

void Game::sellImprovement(string player, string building){
    Player *pl = NULL;
    if (player == "current") {
        pl = getCurrentPlayer();
    } else {
        pl = players[player];
    }

    Building *b = lookUpBuilding(building);
    Academic *aca = dynamic_cast<Academic *>(b);
    if (!aca) cout << "Wrong building. Cannot sell improvement!" << endl;
    if (aca) {
        if (aca->getOwner() != pl) {
            cout << "You don't own " << aca->getName() << endl;
        } else if (aca->getLevel() >= 1) {
            pl->addMoney(0.5 * aca->getImprovementCost());
            aca->LevelDown();
        } else {
            cout << "The level of " << aca->getName() << " is 0. Cannot sell improvement!" << endl;
        }
    }
}

bool Game::checkMonopolyImprovement(Property *prop) {
    Academic *aca = dynamic_cast<Academic *>(prop);
    if (aca) {
        if (aca->getLevel() != 0) {
            return false;
        } else {
            for (int i = 0; i < 40; i++) {
                Academic *a = dynamic_cast<Academic *>(board[i]);
                if (a && a->getMonopolyBlock() == aca->getMonopolyBlock() && a->getLevel() != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Game::mortgage(string player, string building){
    Player *pl = NULL;
    if (player == "current") {
        pl = getCurrentPlayer();
    } else {
        pl = players[player];
    }

    Building *b = lookUpBuilding(building);
    Property *prop = dynamic_cast<Property *>(b);
    if (!prop) cout << "Wrong building. Cannot mortgage!" << endl;
    if (prop) {
        if (prop->getOwner() != pl) {
            cout << "You don't own " << prop->getName() << endl;
        } else if (prop->isMortgage()) {
            cout << "Already mortgaged" << endl;
        } else if (checkMonopolyImprovement(prop)){
            prop->mortgage();
        } else {
            cout << "The monopoly block has improvement. Mortgage failed." << endl;
        }
    }
}

void Game::unmortgage(string player, string building){
    Player *pl = NULL;
    if (player == "current") {
        pl = getCurrentPlayer();
        player = pl->getName();
    } else {
        pl = players[player];
    }

    Building *b = lookUpBuilding(building);
    Property *prop = dynamic_cast<Property *>(b);
    if (!prop) cout << "Wrong building. Cannot unmortgage!" << endl;
    if (prop) {
        if (prop->getOwner() != pl) {
            cout << "You don't own " << prop->getName() << endl;
        } else if (!prop->isMortgage()) {
            cout << "Already unmortgaged" << endl;
        } else {
            double cost = prop->getUnmortgageCost();

            payMoney(cost, player, "bank");
            if (players[player] != NULL) {
                prop->unmortgage();
            }
        }
    }
}

void Game::transferMortgage(Property *prop, string player){
    double cost = 0.1 * prop->getPurchaseCost();
    cout << "Since " << prop->getName() << " is mortgaged, you have to pay $" << cost << " immediately." << endl;
    payMoney(cost, player, "bank");
    if (players[player]) { // if not bankrupt
        string response;
        while (1) {
            cout << "Do you want to unmortgage it right now for no further interest? y/n" << endl;
            cin >> response;
            if (response == "y" || response == "n") break;
        }
        if (response == "y") {
            payMoney(prop->getPurchaseCost(), player, "bank");
            if (players[player]) prop->unmortgage();
        } else {
            prop->setPrevMortgaged(true);
        }
    }
}

void Game::trade(string trader, string receiver, double give, string receive){
    Player *tr = NULL; // trader
    if (trader == "current") {
        tr = getCurrentPlayer();
        trader = tr->getName();
    } else {
        tr = players[trader];
    }

    Player *re = players[receiver]; // receiver

    Building *b = lookUpBuilding(receive);
    Property *prop = dynamic_cast<Property *>(b);
    if (!prop) cout << "Wrong building. Cannot trade!" << endl;
    if (prop) {
        if (prop->getOwner() != re) {
            cout << re->getName() << " doesn't own " << prop->getName() << endl;
        } else if (tr->getMoney() < give){
            cout << "You don't have enough money for trade. Trade rejected" << endl;
        } else {
            if (!checkMonopolyImprovement(prop)) {
                cout << prop->getName() << " or its monopoly block has improvements. Cannot trade!" << endl;
                return;
            }
            string response;
            while (1) {
                cout << re->getName() << ", do you want to trade? y/n" << endl;
                cin >> response;
                if (response == "y" || response == "n") break;
            }
            if (response == "y") {
                payMoney(give, trader, receiver);
                prop->changeOwner(tr);
                if (prop->isMortgage()) {
                    transferMortgage(prop, trader);
                }
                cout << "Trade succeeds." << endl;
            } else {
                cout << "Trade rejected." << endl;
            }

        }
    }
}

void Game::trade(string trader, string receiver, string give, double receive){
    Player *tr = NULL; // trader
    if (trader == "current") {
        tr = getCurrentPlayer();
        trader = tr->getName();
    } else {
        tr = players[trader];
    }

    Player *re = players[receiver]; // receiver

    Building *b = lookUpBuilding(give);
    Property *prop = dynamic_cast<Property *>(b);
    if (!prop) cout << "Wrong building. Cannot trade!" << endl;
    if (prop) {
        if (prop->getOwner() != tr) {
            cout << "You don't own " << prop->getName() << endl;
        } else {
            if (!checkMonopolyImprovement(prop)) {
                cout << prop->getName() << " or its monopoly block has improvements. Cannot trade!" << endl;
                return;
            }
            if (re->getMoney() < receive) {
                cout << re->getName() <<" doesn't have enough money for trade. Trade rejected" << endl;
                return;
            }
            string response;
            while (1) {
                cout << re->getName() << ", do you want to trade? y/n" << endl;
                cin >> response;
                if (response == "y" || response == "n") break;
            }
            if (response == "y") {
                prop->changeOwner(re);
                if (prop->isMortgage()) {
                    transferMortgage(prop, receiver);
                }
                if (players[receiver] != NULL) {
                    payMoney(receive, receiver, trader);
                    if (players[receiver] != NULL) cout << "Trade succeeds." << endl;
                }

            } else {
                cout << "Trade rejected." << endl;
            }
        }
    }
}

void Game::trade(string trader, string receiver, string give, string receive){
    Player *tr = NULL; // trader
    if (trader == "current") {
        tr = getCurrentPlayer();
        trader = tr->getName();
    } else {
        tr = players[trader];
    }

    Player *re = players[receiver]; // receiver

    Building *g = lookUpBuilding(give);
    Property *propg = dynamic_cast<Property *>(g);
    Building *r = lookUpBuilding(receive);
    Property *propr = dynamic_cast<Property *>(r);

    if (!propg || !propr) cout << "Wrong building. Cannot trade!" << endl;
    if (propg && propr) {
        if (propg->getOwner() != tr) {
            cout << "You don't own " << propg->getName() << endl;
        } else if (propr->getOwner() != re) {
            cout << re->getName() << " doesn't own " << propr->getName() << endl;
        } else {
            if (!checkMonopolyImprovement(propg)) {
                cout << propg->getName() << " or its monopoly block has improvements. Cannot trade!" << endl;
                return;
            }

            if (!checkMonopolyImprovement(propr)) {
                cout << propr->getName() << " or its monopoly block has improvements. Cannot trade!" << endl;
                return;
            }

            string response;
            while (1) {
                cout << re->getName() << ", do you want to trade? y/n" << endl;
                cin >> response;
                if (response == "y" || response == "n") break;
            }
            if (response == "y") {
                propg->changeOwner(re);
                if (propg->isMortgage()) {
                    transferMortgage(propg, receiver);
                }

                propr->changeOwner(tr);
                if (propr->isMortgage()) {
                    transferMortgage(propr, trader);
                }

                if (players[receiver] != NULL && players[trader] != NULL) {
                    cout << "Trade succeeds." << endl;
                }

            } else {
                cout << "Trade rejected." << endl;
            }
        }
    }
}

void Game::assets(string player){
    Player *pl = NULL;
    if (player == "current") {
        pl = getCurrentPlayer();
        player = pl->getName();
    } else {
        pl = players[player];
    }

    cout << pl->getName() << " has " << endl;
    cout << "Money: $" << pl->getMoney() << endl;
    pl->printAssets();
}

bool Game::currentPlayerStatus(){
    return getCurrentPlayer()->canMove();
}

void Game::move(int steps){
    int prev = getCurrentPlayer()->getPosn();
    getCurrentPlayer()->move(steps);
    int cur = getCurrentPlayer()->getPosn();
    if (steps > 0 && cur - prev < 0 && cur != 10 && cur != 0) {
        cout << "Pass OSAP. $200 added." << endl;
        getCurrentPlayer()->addMoney(200);
    }
    if (steps < 0 && cur - prev > 0 && cur != 10 && cur != 0) {
        cout << "Pass OSAP. $200 added." << endl;
        getCurrentPlayer()->addMoney(200);
    }
    board[cur]->event();
}

void Game::switchPlayer(){
    do {
        current_iterator++;
        if (current_iterator == players.end()) current_iterator = players.begin();
    } while (getCurrentPlayer() == NULL);
    cout << getCurrentPlayer()->getName() << "'s turn" << endl;
}

void Game::saveGame(string filename){
    ofstream file;
    file.open(filename.c_str());
    map<string, Player *>::iterator tmp = current_iterator;
    map<string, Player *>::iterator it;
    file << getNumPlayerLeft() << endl;
    for (; tmp != players.end(); tmp++) { //save player information starts from the current player
        if (tmp->second == NULL) continue;
        Player *p = tmp->second;
        file<<p->getName()<<" "<<p->getSymbol()<<" "<<p->getRimCup()<<" "<<p->getMoney()<<" "<<p->getPosn();
        if (p->getPosn() == 10) {
            if (p->canMove()) {
                file<<" "<<0<<endl;
            } else {
                file<<" "<<1<<" "<<p->getTimsCounter()<<endl;
            }
        } else {
            file<<endl;
        }
    }
    for (it = players.begin(); it != current_iterator; it++) {
        if (it->second == NULL) continue;
        Player *p = it->second;
        file<<p->getName()<<" "<<p->getSymbol()<<" "<<p->getRimCup()<<" "<<p->getMoney()<<" "<<p->getPosn();
        if (p->getPosn() == 10) {
            if (p->canMove()) {
                file<<" "<<0<<endl;
            } else {
                file<<" "<<1<<" "<<p->getTimsCounter()<<endl;
            }
        } else {
            file<<endl;
        }
    }
    for (int i =0; i< 40; i++) {
        if (board[i]->getType()  == "academic") {
            Academic *a = dynamic_cast<Academic*>(board[i]);
            if (a->getOwner() != NULL && !a->isMortgage()) {
                file<<a->getName()<<" "<<a->getOwner()->getName()<<" "<<a->getLevel()<<endl;
            } else if  (a->getOwner() != NULL && a->isMortgage()) {
                file<<a->getName()<<" "<<a->getOwner()->getName()<<" "<<-1<<endl;
            } else {
                file<<a->getName()<<" "<<"BANK"<<" "<<0<<endl;
            }
        } else if (board[i]->getType()  == "gym" || board[i]->getType()  == "residence") {
            Property *a = dynamic_cast<Property*>(board[i]);
            if (a->getOwner() != NULL && !a->isMortgage()) {
                file<<a->getName()<<" "<<a->getOwner()->getName()<<" "<<0<<endl;
            } else if  (a->getOwner() != NULL && a->isMortgage()) {
                file<<a->getName()<<" "<<a->getOwner()->getName()<<" "<<-1<<endl;
            } else {
                file<<a->getName()<<" "<<"BANK"<<" "<<0<<endl;
            }
        }
    }
    file.close();
}

void Game::printWinner(){
    switchPlayer();
    cout << "Winner is " << getCurrentPlayer()->getName() << endl;
}

void Game::purchaseNotify(Property *prop){
    string response;
    while (1) {
        cout << "Do you want to purchase " << prop->getName() << " that will cost $" << prop->getPurchaseCost() << "? y/n" << endl;
        cin >> response;
        if (response == "y" || response == "n") break;
    }

    if (response == "y") {
        payMoney((double)(prop->getPurchaseCost()), "current", "bank");
        prop->changeOwner(getCurrentPlayer());
    } else {
        auction(prop, getCurrentPlayer()->getName());
    }
}

void Game::tuitionNotify(){
    double worth = getCurrentPlayer()->getTotalWorth();
    double cost = 0.1 * worth;
    string response;
    while (1) {
        cout << "Payment options:" << endl;
        cout << "1. pay $300" << endl;
        cout << "2. pay 10% of your total worth, $" << cost << endl;
        cout << "Which one? Please enter 1 or 2" << endl;
        cin >> response;
        if (response == "1" || response == "2") break;
    }
    if (response == "1") {
        payMoney(300, "current", "bank");
    } else {
        payMoney(cost, "current", "bank");
    }
}

void Game::timsNoify(){
    cout << "Moving to DC Tims Line..." << endl;
    getCurrentPlayer()->setMoveable(false);
    int posn = getCurrentPlayer()->getPosn();
    int steps = 10 - posn;
    move(steps);
}

void Game::osapNotify(){
    cout << "Moving to OSAP..." << endl;
    int posn = getCurrentPlayer()->getPosn();
    int steps = 40 - posn;
    move(steps);
}

void Game::addMoney(double amount){
    getCurrentPlayer()->addMoney(amount);
}

void Game::tims(){
    if (getCurrentPlayer()->canMove()) return;
    if (getCurrentPlayer()->getTimsCounter() == -1) {
        int i = getCurrentPlayer()->getTimsCounter() + 1;
        getCurrentPlayer()->setTimsCounter(i);
        return;
    }
    int dice1, dice2;
    if (c->getTesting()) {
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
     if (dice1 == dice2) {
        cout << "You rolled doubles. You are now leaving Tims Line..." << endl;
        getCurrentPlayer()->setMoveable(true);
        getCurrentPlayer()->setTimsCounter(-1);
        move(dice1+dice2);
     } else if (current_iterator->second->getTimsCounter() == 2){
         cout<<"You have visited DC Tims Line 3 times and you did not roll a set of doubles, you must leave"<<endl;
         cout<<"Please choose from the following options: 1(pay money) 2(use rim up cup). ps. You have " << getCurrentPlayer()->getRimCup() << " Rim Cup available."<<endl;
         int choice;
         cin>>choice;
         if (choice == 2) {
            if (current_iterator->second->useRimCup()) {
                avaible_rim++;
                cout << "Game: Rim Cup available " << avaible_rim << endl;
                getCurrentPlayer()->setMoveable(true);
                getCurrentPlayer()->setTimsCounter(-1);
                move(dice1+dice2);
            } else {
                cout<<"You currently do not have a Rim Cup, so you must pay money"<<endl;
                payMoney(50, current_iterator->second->getName(), "bank");
                if (current_iterator->second != NULL) {
                    getCurrentPlayer()->setMoveable(true);
                    getCurrentPlayer()->setTimsCounter(-1);
                    move(dice1+dice2);
                }
            }
         } else {
             payMoney(50, current_iterator->second->getName(), "bank");
             if (current_iterator->second != NULL) {
                getCurrentPlayer()->setMoveable(true);
                getCurrentPlayer()->setTimsCounter(-1);
                move(dice1+dice2);
            }
         }
     } else {
         cout<<"You have visited DC Tims Line less than 3 times and you did not roll a set of doubles."<<endl;
         cout<<"Would like to leave? y/n"<<endl;
         char answer;
         cin>>answer;
         if (answer == 'y') {
            cout<<"Please choose from the following options: 1(pay money) 2(use rim up cup). ps. You have " << getCurrentPlayer()->getRimCup() << " Rim Cup available."<<endl;
             int choice;
             cin>>choice;
             if (choice == 2) {
                if (current_iterator->second->useRimCup()) {
                    avaible_rim++;
                    cout << "Game: Rim Cup available " << avaible_rim << endl;
                    getCurrentPlayer()->setMoveable(true);
                    getCurrentPlayer()->setTimsCounter(-1);
                    move(dice1+dice2);
                } else {
                    cout<<"You currently do not have a Rim Cup, would you like to pay money? y/n"<<endl;
                    char answer2;
                    cin>>answer2;
                    if (answer2 == 'y') payMoney(50, current_iterator->second->getName(), "bank");
                    if (current_iterator->second != NULL) {
                        getCurrentPlayer()->setMoveable(true);
                        getCurrentPlayer()->setTimsCounter(-1);
                        move(dice1+dice2);
                    }
                }
             } else {
                 payMoney(50, current_iterator->second->getName(), "bank");
                 if (current_iterator->second != NULL) {
                    getCurrentPlayer()->setMoveable(true);
                    getCurrentPlayer()->setTimsCounter(-1);
                    move(dice1+dice2);
                }
             }
         }
     }
     if (getCurrentPlayer() == NULL || getCurrentPlayer()->canMove()) return;
     int i = getCurrentPlayer()->getTimsCounter() + 1;
     getCurrentPlayer()->setTimsCounter(i);
}

bool Game::maxRimCup(){
    return 0 == avaible_rim;
}

void Game::receiveRimCup(){
    getCurrentPlayer()->addRimCup();
    cout << "You got a Rim Cup" << endl;
    avaible_rim--;
}

void Game::auction(Property *prop, string player){
    int active = getNumPlayerLeft() - 1; // number of players enrolling in the auction
    const double VALUE = prop->getPurchaseCost();
    double max_bid = VALUE; // the initial bid is set to the price of the property
    string winner = "";                  // the name of the player who placed the highest bid
    map<string, bool> bid_list;          // true means the player is still in the aution

    // initializing the bid_list
    for (map<string, Player *>::iterator i = players.begin(); i != players.end(); i++) {
        string name = (*i).first;
        Player *pl = (*i).second;
        if (pl && name != player) {
            bid_list[name] = true;
        }

    }

    // bid loop
    while (1) {
        if (active == 1 && max_bid > VALUE) break;
        if (active == 0) break;
        for (map<string, bool>::iterator i = bid_list.begin(); i != bid_list.end(); i++) {
            if (active == 1 && max_bid > VALUE) break;
            if ((*i).second == false) continue;
            string response;
            while (1) {
                cout << (*i).first << ", do you want to bid " << prop->getName() << "? y/n" << endl;
                cin >> response;
                if (response == "y" || response == "n") break;
            }
            if (response == "y") {
                double bid = 0;
                while (1) {
                    cout << "Please place a bid higher than " << max_bid << endl;
                    cin >> bid;
                    if (bid > max_bid) {
                        max_bid = bid;
                        winner = (*i).first;
                        break;
                    }
                }
            } else {
                (*i).second = false;
                active--;
            }
        } // end of for
    }

    if (active == 1) {
        cout << winner << " wins" << endl;
        payMoney(max_bid, winner, "bank");
        if (players[winner]) prop->changeOwner(players[winner]);
    }
    cout << "Auction ends" << endl;
}

void Game::notEnoughMoney(double amount, Player *pl, Player *ower){
    if (players[pl->getName()] == NULL) return;
    cout << pl->getName() << ", you don't have enough money to pay $" << amount << endl;
    assets(pl->getName());
    string response;
    while (1) {
        cout << "Please choose the following options:" << endl;
        cout << "   trade <name> <give> <receive>" << endl;
        cout << "   mortgage <property>" << endl;
        cout << "   improve <property> sell" << endl;
        cout << "   bankrupt" << endl;
        cin >> response;
        if (response == "trade" || response == "mortgage" || response == "improve" || response == "bankrupt") break;
    }

    if (response == "trade") {
        string name;
        string trade1;
        string trade2;
        cin>>name>>trade1>>trade2;
        istringstream iss1(trade1);
        istringstream iss2(trade2);
        double num;
        if (iss1>>num) {
            trade(pl->getName(), name, num, trade2);
        } else if (iss2>>num) {
            trade(pl->getName(), name, trade1, num);
        } else {
            trade(pl->getName(), name, trade1, trade2);
        }
    } else if (response == "mortgage") {
        string property;
        cin >> property;
        mortgage(pl->getName(), property);
    } else if (response == "improve") {
        string property;
        string buyorsell;
        cin >> property >> buyorsell;
        if (buyorsell == "sell") {
            sellImprovement(pl->getName(), property);
        } else if (buyorsell == "buy"){
            cout << "You can't buy improvements at this moment." << endl;
        }
    } else {
        bankrupt(pl, ower);
    }
}

void Game::bankrupt(Player *pl, Player *ower){
    cout << pl->getName() << " bankrupt" << endl;
    playerRemoved(pl->getName());
    avaible_rim += pl->getRimCup();
    players[pl->getName()] = NULL;
    if (ower) {
        ower->addMoney(pl->getMoney());
        string name = ower->getName();
        // change owners and transfer mortgage
        for (int i = 0; i < 40; i++) {
            Property *prop = dynamic_cast<Property *> (board[i]);
            if (prop) {
                if (prop->getOwner() == pl) {
                    if (players[name] != NULL){
                        prop->changeOwner(ower);
                        if (prop->isMortgage()) transferMortgage(prop, ower->getName());
                    } else { // if ower gets bankrupt
                        prop->unmortgage();
                        prop->changeOwner(NULL);
                        auction(prop, pl->getName());
                    }

                }
            }
        }

    } else { // if the ower is bank
        for (int i = 0; i < 40; i++) {
            Property *prop = dynamic_cast<Property *> (board[i]);
            if (prop) {
                if (prop->getOwner() == pl) {
                    prop->unmortgage();
                    prop->changeOwner(NULL);
                    auction(prop, pl->getName());
                }
            }
        }

    }
    num_player_left--;
    delete pl;
}
