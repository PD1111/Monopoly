#ifndef __SLC_H__
#define __SLC_H__

#include "nonproperty.h"
#include <string>

class Game;

class SLC : public NonProperty
{
    public:
        SLC(Game *game, int posn);
        virtual ~SLC();
        void event();
    protected:
    private:
};

#endif // __SLC_H__
