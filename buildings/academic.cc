#include "academic.h"
#include "../game.h"
#include "../player.h"

using namespace std;

Academic::Academic(string name, string monopoly_block, int purchase_cost, int improvement_cost, int lv0, int lv1, int lv2, int lv3, int lv4, int lv5, int posn, Game *game)
    :Property(name,posn,"academic",game, purchase_cost)
    , monopoly_block(monopoly_block), improvement_cost(improvement_cost)
{
    level_tuition[0] = lv0;
    level_tuition[1] = lv1;
    level_tuition[2] = lv2;
    level_tuition[3] = lv3;
    level_tuition[4] = lv4;
    level_tuition[5] = lv5;

    owner = NULL;
    mortgaged = false;
    level = 0;
}

Academic::~Academic(){
}

int Academic::getLevel() const{
    return level;
}

void Academic::setLevel(int i) {
    level = i;
    game->propertyUpdated(this);
}

int Academic::getImprovementCost() const{
    return improvement_cost;
}

void Academic::LevelUp(){
    if (level < 5) {
        level++;
        game->propertyUpdated(this);
    }
}

void Academic::LevelDown(){
    if (level > 0) {
        level--;
        game->propertyUpdated(this);
    }
}

bool Academic::upgradable(){
    int c = owner->countMonopoly(monopoly_block); // count the number of properties of the same monopoly
    if (c == 2 && (monopoly_block == "Arts1" || monopoly_block == "Math")) {
        return true;
    } else if (c == 3) {
        return true;
    }
    return false;
}

int Academic::getPayment(){
    if (level == 0) {
        int c = owner->countMonopoly(monopoly_block); // count the number of properties of the same monopoly
        if (c == 2 && (monopoly_block == "Arts1" || monopoly_block == "Math")) {
            return 2 * level_tuition[level];
        } else if (c == 3) {
            return 2 * level_tuition[level];
        }
    }
    return level_tuition[level];

}

string Academic::getMonopolyBlock(){
    return monopoly_block;
}

void Academic::event(){
    if (owner == NULL) {
        game->purchaseNotify(this);
    } else if (mortgaged) {
        return;
    } else {
        double pay = (double) getPayment();
        game->payMoney(pay, "current", owner->getName());
    }
}
