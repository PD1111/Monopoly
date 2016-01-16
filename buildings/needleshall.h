#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__

#include "nonproperty.h"
#include <string>

class Game;

class NeedlesHall : public NonProperty
{
    public:
        NeedlesHall(Game *game, int posn);
        virtual ~NeedlesHall();
        void event();
    protected:
    private:
};

#endif // __NEEDLESHALL_H__
