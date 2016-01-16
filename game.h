#ifndef __GAME_H__
#define __GAME_H__

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class Building;
class Property;
class Academic;
class Player;
class Controller;

class Game
{
    public:
        Game(int num_of_player, Controller *c); // will call init()
        ~Game();

        // set up a game (either new or from a saved file)
        void init(); // initialize the board
        void addPlayer(std::string name, char symbol); // for a new game
        void setCurrentPlayer(std::string name);      // for loading from text, it should be the first line of the players
        void setPlayer(std::string name, char symbol, int rimcup, double money, int posn); // for loading from a text file (call from controller)
        void setPlayer(std::string name, char symbol, int rimcup, double money, int posn, int tims);
        void setPlayer(std::string name, char symbol, int rimcup, double money, int posn, int tims, int timscounter); // when posn = 10
        void setProperty(std::string building, std::string owner, int improvement);        // for loading from a text file (call from controller)

        // notify controller to update display
        void propertyUpdated(Property *prop); // call this method if there is any update on a property buiding (update display)
        void playerMoved(int prev, int cur, char sym);           // current player update (update position display)
        void playerRemoved(std::string player);      // call this method if a player is removed from the game (update display)

        // methods to be called from controller
        int getNumPlayerLeft() const; // call this method from controller to check if there is a winner
        void buyImprovement(std::string building);
        void sellImprovement(std::string player, std::string building);
        void mortgage(std::string player, std::string building);
        void unmortgage(std::string player, std::string building);
        void trade(std::string trader, std::string receiver, double give, std::string receive); // string is the name of a building
        void trade(std::string trader, std::string receiver, std::string give, double receive);
        void trade(std::string trader, std::string receiver, std::string give, std::string receive);
        void assets(std::string player);              // display assets of a player
        bool currentPlayerStatus(); // returns true if the current player can move (i.e not in timsline)
        void move(int steps);       // steps can be negative, update the player's position
        void switchPlayer();        // switch the current player
        void saveGame(std::string filename);
        void printWinner();         // ONLY call this method only if there is a winner

        // events called from buildings
        Player *getCurrentPlayer() const;
        bool getTesting();
        void purchaseNotify(Property *prop);
        void tuitionNotify();
        void timsNoify();           // call this method if the player needs to be sent to tims
        void osapNotify();
        void payMoney(double amount, std::string payer, std::string receiver); // postive amount, use "current" for current player
                                                                                // "bank" indicates the receiver is bank
        void addMoney(double amount); // add money amount (postive) to current player
        void tims();                // event(process) for tims (it will check if a player was sent to tims)
        bool maxRimCup();           // return true if rimcup reaches its capacity
        void receiveRimCup();       // the current player receives a rim cup, and decrease the rimcup remaining

    protected:
    private:
        int num_player_left;  // number of the players left
        Building *board[40];
        std::map<std::string, Player *> players;
        std::map<std::string, Player *>::iterator current_iterator;
        Controller *c;
        const int MAXRIM;
        int avaible_rim;

        Building *lookUpBuilding(std::string name) const;  // input: the name of a property, return: a building ptr that matches the name
        void transferMortgage(Property *prop, std::string player); // player cannot be "current"
        bool checkMonopolyImprovement(Property *prop);      // used for trade, returns true if the monopoly block doesn't have improvement
        void auction(Property *prop, std::string player);
        void notEnoughMoney(double amount, Player *pl, Player *ower = NULL); // amount is the amount of money that needs to pay,
                                                                        // ower is NULL if it is a bank
        void bankrupt(Player *pl, Player *ower = NULL);
};

#endif // __GAME_H__
