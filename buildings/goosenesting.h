#ifndef __GOOSENESTING_H__
#define __GOOSENESTING_H__

#include "nonproperty.h"
#include <string>

class Game;

class GooseNesting : public NonProperty
{
    public:
        GooseNesting(Game *game, int posn);
        virtual ~GooseNesting();
        void event();
    protected:
    private:
};

#endif // __GOOSENESTING_H__
