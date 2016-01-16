#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>
#include <map>
#include <iostream>

class Game;
class Property;
class Academic;
class Gym;
class Residence;

class Player
{
    public:
        Player(std::string name, char symbol, Game *game);
        virtual ~Player();

        std::string getName() const;
        char getSymbol() const;
        double getMoney() const;
        int getPosn() const;
        void setPosn(int i);
        void setMoney(double amount); // set directly (for load)
        void addMoney(double amount); // add the amount(positive) to the current money
        bool payMoney(double amount); // subtract the amount(positive) from the money
        void move(int steps);         // change posn by steps (also accept neg. steps)
        void addProperty(Property *prop);
        void removeProperty(std::string name); // return true if the play owns the property
        int countMonopoly(std::string type);
        void printAssets();
        double getTotalWorth();       // return the net worth of player
        bool useRimCup();
        void addRimCup();
        void setRimCup(int num);
        int getRimCup() const;
        void setMoveable(bool b);
        bool canMove() const;
        void setTimsCounter(int i);
        int getTimsCounter() const;
    protected:
    private:
        const std::string name;
        const char symbol;
        double money;
        int posn;
        std::map<std::string, Property *> owned; // key is name of the property, value is Property *
        std::map<std::string, int> counter;      // key is one of monopoly block(if it is academic)/gym/residence, value is counter for each type
        Game *game;
        int rimcup;
        bool moveable;
        int timscounter; // counter for the number of turns a player in tims (0 - 2)
};

#endif // __PLAYER_H__
