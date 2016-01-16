#ifndef __PROPERTY_H__
#define __PROPERTY_H__

#include "building.h"
#include <string>

class Player;
class Game;

class Property : public Building
{
    public:
        virtual ~Property() =0;

        void setOwner(Player *owner);    // call this method when loading file
        void changeOwner(Player *owner); // call this method except when loading file, this will notify game property is updated
        Player *getOwner() const;
        int getPurchaseCost() const;
        void mortgage();
        double getUnmortgageCost() const; // return the amount needed to unmorgage a property
        void unmortgage();
        void setMortgage(); // set the mortgaged to true
        bool isMortgage() const;
        void setPrevMortgaged(bool);
        virtual void event() =0;
    protected:
        Property(std::string name, int posn, std::string type, Game *game, int purchase_cost);
        Player *owner;
        const int purchase_cost;
        bool mortgaged;

        virtual int getPayment() =0;
    private:
        bool prev_mortgaged;
};

#endif // __PROPERTY_H__
