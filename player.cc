#include "player.h"
#include "./buildings/property.h"
#include "./buildings/academic.h"
#include "./buildings/gym.h"
#include "./buildings/residence.h"
#include "game.h"
#include <iomanip>

using namespace std;

Player::Player(string name, char symbol, Game *game) : name(name), symbol(symbol), game(game)
{
    money = 1500;
    posn = 0;
    rimcup = 0;
    moveable = true;
    timscounter = -1;
}

Player::~Player(){
}

string Player::getName() const{
    return name;
}

char Player::getSymbol() const{
    return symbol;
}

double Player::getMoney() const{
    return money;
}

int Player::getPosn() const{
    return posn;
}

void Player::setPosn(int i){
    int prev = posn;
    posn = i;
    game->playerMoved(prev, posn, getSymbol());
}

void Player::setMoney(double amount){
    money = amount;
}

void Player::addMoney(double amount){
    if (amount < 0) return;
    money += amount;
    cout << name << ": $" << amount << " added" << endl;
}

bool Player::payMoney(double amount){
    if (amount < 0) return false;
    if (money - amount < 0) return false;
    money -= amount;
    cout << name << ": $" << amount << " paid" << endl;
    return true;
}

void Player::move(int steps){
    int prev = posn;
    if (posn + steps < 0) posn = posn + steps + 40;
    else posn = (posn + steps) % 40;
    cout << getSymbol() << " moved to " << posn << endl;
    game->playerMoved(prev, posn, getSymbol());
}

void Player::addProperty(Property *prop){
    Academic *aca = dynamic_cast<Academic *>(prop);
    Gym *gym = dynamic_cast<Gym *>(prop);
    Residence *res = dynamic_cast<Residence *>(prop);
    if (aca) counter[aca->getMonopolyBlock()]++;
    if (gym) counter["gym"]++;
    if (res) counter["res"]++;
    owned[prop->getName()] = prop;
}

void Player::removeProperty(string name){
    Property *prop = owned[name];

    Academic *aca = dynamic_cast<Academic *>(prop);
    Gym *gym = dynamic_cast<Gym *>(prop);
    Residence *res = dynamic_cast<Residence *>(prop);
    if (aca) counter[aca->getMonopolyBlock()]--;
    if (gym) counter["gym"]--;
    if (res) counter["res"]--;
    owned.erase(name);
}

int Player::countMonopoly(string type){
    return counter[type];
}

void Player::printAssets(){
    cout << setw(13) << left << "Properties" << "Level" << endl;
    for (map<std::string, Property *>::iterator i = owned.begin(); i != owned.end(); i++) {
        string name = (*i).first;
        Property *prop = (*i).second;
        int level = 0;
        Academic *aca = dynamic_cast<Academic *>(prop);
        if (aca) level = aca->getLevel();
        cout << setw(13) << left << prop->getName() << level << endl;
    }
}

double Player::getTotalWorth(){
    double worth = money;
    for (map<std::string, Property *>::iterator i = owned.begin(); i != owned.end(); i++) {
        Property *prop = (*i).second;
        worth += prop->getPurchaseCost();
        Academic *aca = dynamic_cast<Academic *> (prop);
        if (aca) {
            worth += (double)(aca->getLevel() * aca->getImprovementCost());
        }
    }
    return worth;
}

bool Player::useRimCup(){
    if (rimcup == 0) return false;
    rimcup--;
    return true;
}

void Player::addRimCup(){
    rimcup++;
}

void Player::setRimCup(int num){
    rimcup = num;
}

int Player::getRimCup() const{
    return rimcup;
}

void Player::setMoveable(bool b){
    moveable = b;
}

bool Player::canMove() const{
    return moveable;
}

void Player::setTimsCounter(int i){
    timscounter = i;
}

int Player::getTimsCounter() const{
    return timscounter;
}
