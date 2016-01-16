#include "property.h"
#include "../player.h"
#include "../game.h"

using namespace std;

Property::Property(string name, int posn, string type, Game *game, int purchase_cost)
    : Building(name, posn, type)
    , purchase_cost(purchase_cost)
{
    this->game = game;
    prev_mortgaged = false;
}

Property::~Property(){
}

void Property::setOwner(Player *owner){
    owner->addProperty(this);
    this->owner = owner;
    game->propertyUpdated(this);
}

void Property::changeOwner(Player *owner){
    if (getOwner()) getOwner()->removeProperty(getName());
    this->owner = owner;
    if (owner != NULL) owner->addProperty(this);
    game->propertyUpdated(this);
}

Player *Property::getOwner() const{
    return owner;
}

int Property::getPurchaseCost() const{
    return purchase_cost;
}

void Property::mortgage(){
    if (mortgaged) return;
    mortgaged = true;
    owner->addMoney(0.5 * (double)purchase_cost);
    game->propertyUpdated(this);
}

double Property::getUnmortgageCost() const{
    if (!mortgaged) return 0;
    double cost = 1.1 * 0.5 * (double)purchase_cost;
    if (prev_mortgaged) cost = 1.1 * purchase_cost;
    return cost;
}

void Property::unmortgage(){
    if (!mortgaged) return;
    mortgaged = false;
    prev_mortgaged = false;
    game->propertyUpdated(this);
}

void Property::setMortgage(){
    mortgaged = true;
    game->propertyUpdated(this);
}

void Property::setPrevMortgaged(bool b){
    prev_mortgaged = b;
}

bool Property::isMortgage() const{
    return mortgaged;
}

