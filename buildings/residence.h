#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__

#include "property.h"
#include <string>

class Game;

class Residence : public Property
{
    public:
        Residence(std::string name, int posn, Game *game);
        virtual ~Residence();

        int getPayment();
        void event();
    protected:
    private:
};

#endif // __RESIDENCE_H__
