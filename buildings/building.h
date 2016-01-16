#ifndef __BUILDING_H__
#define __BUILDING_H__

#include <string>

class Game;

class Building
{
    public:
        virtual ~Building() =0;
        std::string getName() const;
        std::string getType() const;
        int getPosn() const;
        virtual void event() =0;
    protected:
        Building(std::string name, int posn, std::string type);
        const std::string name;
        const int posn;
        const std::string type;
        Game *game;
    private:
};

#endif // __BUILDING_H__
