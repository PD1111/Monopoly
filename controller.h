#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__
#include <string>

class Game;
class TextDisplay;

class Controller {
    TextDisplay *td;
    Game *game;
    std::string input;
    void init(int num);
    bool testing;
    int rollNum;
    bool rollDouble;

  public:
    bool getTesting();
    void nonAcademicNotify(int posn, char player, bool isMoartgage);
    void setTesting();//starts the testing mode
    void load(std::string input);//loading input from an existing file
    void setInput(std::string name); //set the input field if there is input coming from a file
    Controller(); //initializes member fields
    ~Controller();
    void play();//game loop body
    void buildingNotify(int position, int level, char name); //to notify the building change to text display
    void playerMoveNotify(int prev, int cur, char name);//to notify the player position change to text display
    void playerRemoveNotify(int position, char name);//to notify the player removed to text display
};


#endif // __CONTROLLER_H__
