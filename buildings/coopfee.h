#ifndef __COOPFEE_H__
#define __COOPFEE_H__

#include "nonproperty.h"
#include <string>

class Game;

class CoopFee : public NonProperty
{
    public:
        CoopFee(Game *game, int posn);
        virtual ~CoopFee();
        void event();
    protected:
    private:
};

#endif // __COOPFEE_H__
