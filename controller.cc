#include "controller.h"
#include "game.h"
#include "textdisplay.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

Controller::Controller(){
    game = NULL;
    td = NULL;
    input = "";
    testing = false;
    rollNum = 0;
    rollDouble = true;
}

void Controller::init(int num) {
    for (int i = 0; i < num; i++) {
        string name;
        char symbol;
        cout<<"Player"<<i+1<<"'s turn to choose name : "<<endl;
        cin>>name>>symbol;
        td->addPlayer(symbol);
        game->addPlayer(name, symbol);
    }
    game->init();
    td->init();
}

void Controller::load(string input) {
    ifstream file(input.c_str());
    int numPlayers;
    file>>numPlayers;
    td = new TextDisplay(numPlayers);
    game = new Game(numPlayers, this);
    string line;
    getline(file, line);
     for (int i = 0; i < numPlayers; i++) {
            getline(file, line);
            istringstream iss(line);
            string name;
            char symbol;
            int timsCups;
            double money;
            int position;
            iss>>name>>symbol>>timsCups>>money>>position;
            if (position == 10) {
                int tims;
                iss>>tims;
                if (tims == 1) {
                    int timscounter;
                    iss>>timscounter;
                    td->addPlayer(symbol);
                    game->setPlayer(name, symbol, timsCups, money, position, tims, timscounter);
                } else {
                    td->addPlayer(symbol);
                    game->setPlayer(name, symbol, timsCups, money, position);
                }
            } else {
                td->addPlayer(symbol);
                game->setPlayer(name, symbol, timsCups, money, position);
            }
            if (i == 0) {
                game->init();
                game->setCurrentPlayer(name);
                cout << name <<"'s turn" << endl;
            }

    }

    while (getline(file, line)) {
        istringstream iss(line);
        string building;
        string owner;
        int improvement;
        iss>>building>>owner>>improvement;
        game->setProperty(building, owner, improvement);
    }
}


void Controller::play() {
    if (input != "") {
        load(input);
    } else {
        int num = 0;
        cout << "Please enter the number of player : "<<endl;
        cin>>num;
        td = new TextDisplay(num);
        game = new Game(num, this);
        init(num);
    }
    td->print();
    string cmd;
    while (cin>>cmd) {
        if (cmd == "save") {
            string file;
            cin>>file;
            game->saveGame(file);
        } else if (cmd == "roll") {
            if (rollDouble) {
                if (testing && game->currentPlayerStatus()) {
                    string nline;
                    getline(cin, nline);
                    if (nline != "") {
                        istringstream iss(nline);
                        int dice1, dice2;
                        iss>>dice1>>dice2;
                        cout<<"You have rolled dice1 : "<<dice1<<" dice2 :"<<dice2<<endl;
                        if (dice1 == dice2 && rollNum == 2) {
                            cout<<"You have rolled 3 sets of doubles, so you will be sent to DC Tims Line"<<endl;
                            rollDouble = false;
                            game->timsNoify();
                        } else if (dice1 == dice2 && rollNum < 2) {
                            cout<<"You have rolled a set of doubles, please roll again later"<<endl;
                            rollNum++;
                        } else {
                            rollDouble = false;
                            game->move(dice1 + dice2);
                        }
                    } else {
                        srand(time(NULL));
                        int dice1, dice2;
                        dice1 = rand() % 6 + 1;
                        dice2 = rand() % 6 + 1;
                        cout<<"You have rolled dice1 : "<<dice1<<" dice2 :"<<dice2<<endl;
                        if (dice1 == dice2 && rollNum == 2) {
                            cout<<"You have rolled 3 sets of doubles, so you will be sent to DC Tims Line"<<endl;
                            rollDouble = false;
                            game->timsNoify();
                        } else if (dice1 == dice2 && rollNum < 2) {
                            cout<<"You have rolled a set of doubles, please roll again later"<<endl;
                            rollNum++;
                        } else {
                            rollDouble = false;
                            game->move(dice1 + dice2);
                        }
                    }
                } else if (game->currentPlayerStatus()) {
                        srand(time(NULL));
                        int dice1, dice2;
                        dice1 = rand() % 6 + 1;
                        dice2 = rand() % 6 + 1;
                        cout<<"You have rolled dice1 : "<<dice1<<" dice2 :"<<dice2<<endl;
                        if (dice1 == dice2 && rollNum == 2) {
                            cout<<"You have rolled 3 sets of doubles, so you will be sent to DC Tims Line"<<endl;
                            rollDouble = false;
                            game->timsNoify();
                        } else if (dice1 == dice2 && rollNum < 2) {
                            cout<<"You have rolled a set of doubles, please roll again later"<<endl;
                            rollNum++;
                        } else {
                            rollDouble = false;
                            game->move(dice1 + dice2);
                        }
                } else {
                    rollDouble = false;
                    game->tims(); //when the player is sent to DC Tims Line rather than lands on it
                }
                td->print();
            } else {
                cout<<"You have rolled once, please use next to end your turn!"<<endl;
            }
        } else if (cmd == "next") {
            if (rollDouble) {
                cout<<"You have not rolled yet, please roll first before switching turn!" << endl;
            } else if (game->getNumPlayerLeft() == 1) {
                game->printWinner();
                break;
            } else {
                rollNum = 0;
                rollDouble = true;
                game->switchPlayer();
                td->print();
            }
        } else if (cmd == "trade") {
            string name;
            string trade1;
            string trade2;
            cin>>name>>trade1>>trade2;
            istringstream iss1(trade1);
            istringstream iss2(trade2);
            double num;
            if (iss1>>num) {
                game->trade("current", name, num, trade2);
            } else if (iss2>>num) {
                game->trade("current", name, trade1, num);
            } else {
                game->trade("current", name, trade1, trade2);
            }
            td->print();
        } else if (cmd == "improve") {
            string name, action;
            cin>>name>>action;
            if (action == "buy") {
                game->buyImprovement(name);
            } else {
                game->sellImprovement("current",name);
            }
            td->print();
        } else if (cmd == "mortgage") {
            string name;
            cin>>name;
            game->mortgage("current",name);
            td->print();
        } else if (cmd == "unmortgage") {
            string name;
            cin>>name;
            game->unmortgage("current",name);
            td->print();
        } else if (cmd == "assets") {
            game->assets("current");
        } else if (cmd == "quit") {
            break;
        }
    }
}

Controller::~Controller(){
    delete game;
    delete td;
}

void Controller::nonAcademicNotify(int posn, char player, bool isMortgage) {
    td->nonAcademicNotify(posn, player, isMortgage);
}

void Controller::buildingNotify(int position, int level, char name) {
    td->buildingNotify(position, level, name);
}

void Controller::playerMoveNotify(int prev, int cur, char name) {
    td->posnNotify(name, cur, prev);
}

void Controller::playerRemoveNotify(int position, char name) {
    td->playerRemove(name, position);
}

void Controller::setInput(string name) {
    input = name;
}

void Controller::setTesting() {
    testing = true;
}

bool Controller::getTesting() {
    return testing;
}
