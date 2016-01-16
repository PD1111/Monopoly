#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__


class TextDisplay {
    char ** board;
    char * player;
    int playerNum;
    int currentNum;
    int playerRow(int position, char name);
    int playerColumn(int position, char name);
    int buildingRow(int position, char name);
    int buildingColumn(int position, char name);

public:
    void addPlayer(char name);
    void posnNotify(char name, int cur, int prev = -1);
    void playerRemove(char name, int position);
    void buildingNotify(int posn, int level, char player);
    void nonAcademicNotify(int posn, char player, bool isMortgage);
    void print();
    void init();
    TextDisplay(int num);
    ~TextDisplay();
};

#endif // __TEXTDISPLAY_H__
