#ifndef __GOTOTIMS_H__
#define __GOTOTIMS_H__

#include "nonproperty.h"
#include <string>

class Game;

class GoToTims : public NonProperty
{
    public:
        GoToTims(Game *game, int posn);
        virtual ~GoToTims();
        void event();
    protected:
    private:
};

#endif // __GOTOTIMS_H__
