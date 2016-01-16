#ifndef __GYM_H__
#define __GYM_H__

#include "property.h"
#include <string>

class Game;

class Gym : public Property
{
    public:
        Gym(std::string name, int posn, Game *game);
        virtual ~Gym();

        int getPayment();
        void event();
    protected:
    private:
};

#endif // __GYM_H__
