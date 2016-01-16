#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__

#include "property.h"
#include <string>

class Game;


class Academic : public Property
{
    public:
        Academic(std::string name, std::string monopoly_block, int purchase_cost, int improvement_cost, int lv0, int lv1, int lv2, int lv3, int lv4, int lv5, int posn, Game *game);
        virtual ~Academic();

        int getLevel() const;
        void setLevel(int i);
        int getImprovementCost() const;
        bool upgradable();
        void LevelUp();
        void LevelDown();
        int getPayment();
        std::string getMonopolyBlock();
        void event();
    protected:
    private:
        const std::string monopoly_block;
        int level;
        const int improvement_cost;
        int level_tuition[6];
};

#endif // __ACADEMIC_H__
