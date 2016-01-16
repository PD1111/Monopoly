#ifndef __DCTIMS_H__
#define __DCTIMS_H__

#include "nonproperty.h"
#include <string>

class Game;

class DCTims : public NonProperty
{
    public:
        DCTims(Game *game, int posn);
        virtual ~DCTims();
        void event();
    protected:
    private:
};

#endif // __DCTIMS_H__
