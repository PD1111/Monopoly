#ifndef __OSAP_H__
#define __OSAP_H__

#include "nonproperty.h"
#include <string>

class Game;

class OSAP : public NonProperty
{
    public:
        OSAP(Game *game, int posn);
        virtual ~OSAP();
        void event();
    protected:
    private:
};

#endif // __OSAP_H__
