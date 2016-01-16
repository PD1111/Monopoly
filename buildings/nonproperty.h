#ifndef __NONPROPERTY_H__
#define __NONPROPERTY_H__

#include "building.h"
#include <string>

class Game;

class NonProperty : public Building
{
    public:
        virtual ~NonProperty() =0;
        virtual void event() =0;
    protected:
        NonProperty(std::string name, int posn, Game *game);
    private:
};

#endif // __NONPROPERTY_H__
