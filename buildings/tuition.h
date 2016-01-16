#ifndef __TUITION_H__
#define __TUITION_H__

#include "nonproperty.h"
#include <string>

class Game;

class Tuition : public NonProperty
{
    public:
        Tuition(Game *game, int posn);
        virtual ~Tuition();
        void event();
    protected:
    private:
};

#endif // __TUITION_H__
