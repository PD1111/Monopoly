#include <iostream>
#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay(int num) {
    playerNum = num;
    player = new char[num];
    board = new char*[56];
    for (int i = 0; i < 56; i++) {
        board[i] = new char[89];
        for (int j = 0; j < 89; j++) {
            board[i][j] = 32; //initialize the board to be a white board
        }
    }
    for (int i = 0; i < 89; i++) {
        board[5][i] = '_';
    }
    for (int i = 0; i < 89; i++) {
        board[50][i] = '_';
    }
    for (int i = 0; i < 89; i++) {
        board[55][i] = '_';
    }
    for (int i = 0; i < 56; i++) {
        board[i][0] = '|';
    }
    for (int i = 0; i < 56; i++) {
        board[i][8] = '|';
    }
    for (int i = 0; i < 56; i++) {
        board[i][88] = '|';
    }
    for (int i = 0; i < 56; i++) {
        board[i][80] = '|';
    }
     for (int i = 0; i < 89; i++) {
        board[0][i] = '_';
    }
    for (int i = 1; i < 6; i ++) {
        for (int j = 0; j < 89; j++) {
            if (j % 8 == 0) board[i][j] = '|';
        }
    }
    for (int i = 51; i < 56; i ++) {
        for (int j = 0; j < 89; j++) {
            if (j % 8 == 0) board[i][j] = '|';
        }
    }
    for (int i = 10; i < 46; i ++) {
        for (int j = 0; j < 89; j++) {
            if (j % 8 != 0 && (j < 8 || j > 80) && i % 5 == 0) board[i][j] = '_';
        }
    }
     for (int i = 24; i < 65; i++) {
        board[24][i] = '_';
    }
     for (int i = 24; i < 65; i++) {
        board[31][i] = '_';
    }
     for (int i = 25; i < 32; i++) {
        board[i][24] = '|';
    }
    for (int i = 25; i < 32; i++) {
        board[i][64] = '|';
    }
    board[26][27] = '#';
    board[26][28] = '#';
    board[26][29] = '#';
    board[27][27] = '#';
    board[27][30] = '#';
    board[28][27] = '#';
    board[28][28] = '#';
    board[28][29] = '#';
    board[28][30] = '#';
    board[29][27] = '#';
    board[29][31] = '#';
    board[30][27] = '#';
    board[30][28] = '#';
    board[30][29] = '#';
    board[30][30] = '#';// first letter of B

    board[26][33] = '#';
    board[26][34] = '#';
    board[26][35] = '#';
    board[27][33] = '#';
    board[27][36] = '#';
    board[28][33] = '#';
    board[28][34] = '#';
    board[28][35] = '#';
    board[28][36] = '#';
    board[29][33] = '#';
    board[29][37] = '#';
    board[30][33] = '#';
    board[30][34] = '#';
    board[30][35] = '#';
    board[30][36] = '#';// second letter of B


    board[26][39] = '#';
    board[26][40] = '#';
    board[26][41] = '#';
    board[26][42] = '#';
    board[26][43] = '#';
    board[27][42] = '#';
    board[28][41] = '#';
    board[29][40] = '#';
    board[30][39] = '#';//display number 7


    board[26][46] = '#';
    board[26][47] = '#';
    board[26][48] = '#';
    board[27][45] = '#';
    board[27][49] = '#';
    board[28][45] = '#';
    board[28][49] = '#';
    board[29][45] = '#';
    board[29][49] = '#';
    board[30][46] = '#';
    board[30][47] = '#';
    board[30][48] = '#';//display number 0

    board[26][52] = '#';
    board[26][53] = '#';
    board[26][54] = '#';
    board[27][51] = '#';
    board[27][55] = '#';
    board[28][51] = '#';
    board[28][55] = '#';
    board[29][51] = '#';
    board[29][55] = '#';
    board[30][52] = '#';
    board[30][53] = '#';
    board[30][54] = '#';//display number 0


    board[26][58] = '#';
    board[26][59] = '#';
    board[26][60] = '#';
    board[27][57] = '#';
    board[27][61] = '#';
    board[28][57] = '#';
    board[28][61] = '#';
    board[29][57] = '#';
    board[29][61] = '#';
    board[30][58] = '#';
    board[30][59] = '#';
    board[30][60] = '#';//display number 0

    board[51][81] = 'C';
    board[51][82] = 'O';
    board[51][83] = 'L';
    board[51][84] = 'L';
    board[51][85] = 'E';
    board[51][86] = 'C';
    board[51][87] = 'T';
    board[52][81] = 'O';
    board[52][82] = 'S';
    board[52][83] = 'A';
    board[52][84] = 'P';//initialize building in position 0

    board[52][73] = '_';
    board[52][74] = '_';
    board[52][75] = '_';
    board[52][76] = '_';
    board[52][77] = '_';
    board[52][78] = '_';
    board[52][79] = '_';
    board[53][73] = 'A';
    board[53][74] = 'L';//initialize building in position 1

    board[51][65] = 'S';
    board[51][66] = 'L';
    board[51][67] = 'C';//initialize building in position 2

    board[52][57] = '_';
    board[52][58] = '_';
    board[52][59] = '_';
    board[52][60] = '_';
    board[52][61] = '_';
    board[52][62] = '_';
    board[52][63] = '_';
    board[53][57] = 'M';
    board[53][58] = 'L';//initialize building in position 3

    board[51][49] = 'T';
    board[51][50] = 'U';
    board[51][51] = 'I';
    board[51][52] = 'T';
    board[51][53] = 'I';
    board[51][54] = 'O';
    board[51][55] = 'N';//initialize building in position 4

    board[51][41] = 'M';
    board[51][42] = 'K';
    board[51][43] = 'V';//initialize building in position 5

    board[52][33] = '_';
    board[52][34] = '_';
    board[52][35] = '_';
    board[52][36] = '_';
    board[52][37] = '_';
    board[52][38] = '_';
    board[52][39] = '_';
    board[53][33] = 'E';
    board[53][34] = 'C';
    board[53][35] = 'H';//initialize building in position 6

    board[51][25] = 'N';
    board[51][26] = 'E';
    board[51][27] = 'E';
    board[51][28] = 'D';
    board[51][29] = 'L';
    board[51][30] = 'E';
    board[51][31] = 'S';
    board[52][25] = 'H';
    board[52][26] = 'A';
    board[52][27] = 'L';
    board[52][28] = 'L';//initialize building in position 7

    board[52][17] = '_';
    board[52][18] = '_';
    board[52][19] = '_';
    board[52][20] = '_';
    board[52][21] = '_';
    board[52][22] = '_';
    board[52][23] = '_';
    board[53][17] = 'P';
    board[53][18] = 'A';
    board[53][19] = 'S';//initialize building in position 8

    board[52][9] = '_';
    board[52][10] = '_';
    board[52][11] = '_';
    board[52][12] = '_';
    board[52][13] = '_';
    board[52][14] = '_';
    board[52][15] = '_';
    board[53][9] = 'H';
    board[53][10] = 'H';//initialize building in position 9

    board[51][1] = 'D';
    board[51][2] = 'C';
    board[51][4] = 'T';
    board[51][5] = 'i';
    board[51][6] = 'm';
    board[51][7] = 's';
    board[52][1] = 'L';
    board[52][2] = 'i';
    board[52][3] = 'n';
    board[52][4] = 'e';//initialize building in position 10

    board[47][1] = '_';
    board[47][2] = '_';
    board[47][3] = '_';
    board[47][4] = '_';
    board[47][5] = '_';
    board[47][6] = '_';
    board[47][7] = '_';
    board[48][1] = 'R';
    board[48][2] = 'C';
    board[48][3] = 'H';//initialize building in position 11

    board[41][1] = 'P';
    board[41][2] = 'A';
    board[41][3] = 'C';//initialize building in position 12

    board[37][1] = '_';
    board[37][2] = '_';
    board[37][3] = '_';
    board[37][4] = '_';
    board[37][5] = '_';
    board[37][6] = '_';
    board[37][7] = '_';
    board[38][1] = 'D';
    board[38][2] = 'W';
    board[38][3] = 'E';//initialize building in position 13

    board[32][1] = '_';
    board[32][2] = '_';
    board[32][3] = '_';
    board[32][4] = '_';
    board[32][5] = '_';
    board[32][6] = '_';
    board[32][7] = '_';
    board[33][1] = 'C';
    board[33][2] = 'P';
    board[33][3] = 'H';//initialize building in position 14

    board[26][1] = 'U';
    board[26][2] = 'W';
    board[26][3] = 'P';//initialize building in position 15

    board[22][1] = '_';
    board[22][2] = '_';
    board[22][3] = '_';
    board[22][4] = '_';
    board[22][5] = '_';
    board[22][6] = '_';
    board[22][7] = '_';
    board[23][1] = 'L';
    board[23][2] = 'H';
    board[23][3] = 'I';//initialize building in position 16

    board[16][1] = 'S';
    board[16][2] = 'L';
    board[16][3] = 'C';//initialize building in position 17

    board[12][1] = '_';
    board[12][2] = '_';
    board[12][3] = '_';
    board[12][4] = '_';
    board[12][5] = '_';
    board[12][6] = '_';
    board[12][7] = '_';
    board[13][1] = 'B';
    board[13][2] = 'M';
    board[13][3] = 'H';//initialize building in position 18

    board[7][1] = '_';
    board[7][2] = '_';
    board[7][3] = '_';
    board[7][4] = '_';
    board[7][5] = '_';
    board[7][6] = '_';
    board[7][7] = '_';
    board[8][1] = 'O';
    board[8][2] = 'P';
    board[8][3] = 'T';//initialize building in position 19

    board[1][1] = 'G';
    board[1][2] = 'o';
    board[1][3] = 'o';
    board[1][4] = 's';
    board[1][5] = 'e';
    board[2][1] = 'N';
    board[2][2] = 'e';
    board[2][3] = 's';
    board[2][4] = 't';
    board[2][5] = 'i';
    board[2][6] = 'n';
    board[2][7] = 'g';//initialize building in position 20

    board[2][9] = '_';
    board[2][10] = '_';
    board[2][11] = '_';
    board[2][12] = '_';
    board[2][13] = '_';
    board[2][14] = '_';
    board[2][15] = '_';
    board[3][9] = 'E';
    board[3][10] = 'V';
    board[3][11] = '1';//initialize building in position 21

    board[1][17] = 'N';
    board[1][18] = 'E';
    board[1][19] = 'E';
    board[1][20] = 'D';
    board[1][21] = 'L';
    board[1][22] = 'E';
    board[1][23] = 'S';
    board[2][17] = 'H';
    board[2][18] = 'A';
    board[2][19] = 'L';
    board[2][20] = 'L';//initialize building in position 22

    board[2][25] = '_';
    board[2][26] = '_';
    board[2][27] = '_';
    board[2][28] = '_';
    board[2][29] = '_';
    board[2][30] = '_';
    board[2][31] = '_';
    board[3][25] = 'E';
    board[3][26] = 'V';
    board[3][27] = '2';//initialize building in position 23

    board[2][33] = '_';
    board[2][34] = '_';
    board[2][35] = '_';
    board[2][36] = '_';
    board[2][37] = '_';
    board[2][38] = '_';
    board[2][39] = '_';
    board[3][33] = 'E';
    board[3][34] = 'V';
    board[3][35] = '3';//initialize building in position 24

    board[1][41] = 'V';
    board[1][42] = '1';//initialize building in position 25

    board[2][49] = '_';
    board[2][50] = '_';
    board[2][51] = '_';
    board[2][52] = '_';
    board[2][53] = '_';
    board[2][54] = '_';
    board[2][55] = '_';
    board[3][49] = 'P';
    board[3][50] = 'H';
    board[3][51] = 'Y';
    board[3][52] = 'S';//initialize building in position 26

    board[2][57] = '_';
    board[2][58] = '_';
    board[2][59] = '_';
    board[2][60] = '_';
    board[2][61] = '_';
    board[2][62] = '_';
    board[2][63] = '_';
    board[3][57] = 'B';
    board[3][58] = '1';//initialize building in position 27

    board[1][65] = 'C';
    board[1][66] = 'I';
    board[1][67] = 'F';//initialize building in position 28

    board[2][73] = '_';
    board[2][74] = '_';
    board[2][75] = '_';
    board[2][76] = '_';
    board[2][77] = '_';
    board[2][78] = '_';
    board[2][79] = '_';
    board[3][73] = 'B';
    board[3][74] = '2';//initialize building in position 29

    board[1][81] = 'G';
    board[1][82] = 'O';
    board[1][84] = 'T';
    board[1][85] = 'O';
    board[2][81] = 'T';
    board[2][82] = 'I';
    board[2][83] = 'M';
    board[2][84] = 'S';//initialize building in position 30

    board[7][81] = '_';
    board[7][82] = '_';
    board[7][83] = '_';
    board[7][84] = '_';
    board[7][85] = '_';
    board[7][86] = '_';
    board[7][87] = '_';
    board[8][81] = 'E';
    board[8][82] = 'I';
    board[8][83] = 'T';//initialize building in position 31

    board[12][81] = '_';
    board[12][82] = '_';
    board[12][83] = '_';
    board[12][84] = '_';
    board[12][85] = '_';
    board[12][86] = '_';
    board[12][87] = '_';
    board[13][81] = 'E';
    board[13][82] = 'S';
    board[13][83] = 'C';//initialize building in position 32

    board[16][81] = 'S';
    board[16][82] = 'L';
    board[16][83] = 'C';//initialize building in position 33

    board[22][81] = '_';
    board[22][82] = '_';
    board[22][83] = '_';
    board[22][84] = '_';
    board[22][85] = '_';
    board[22][86] = '_';
    board[22][87] = '_';
    board[23][81] = 'C';
    board[23][82] = '2';//initialize building in position 34

    board[26][81] = 'R';
    board[26][82] = 'E';
    board[26][83] = 'V';//initialize building in position 35

    board[31][81] = 'N';
    board[31][82] = 'E';
    board[31][83] = 'E';
    board[31][84] = 'D';
    board[31][85] = 'L';
    board[31][86] = 'E';
    board[31][87] = 'S';
    board[32][81] = 'H';
    board[32][82] = 'A';
    board[32][83] = 'L';
    board[32][84] = 'L';//initialize building in position 36

    board[37][81] = '_';
    board[37][82] = '_';
    board[37][83] = '_';
    board[37][84] = '_';
    board[37][85] = '_';
    board[37][86] = '_';
    board[37][87] = '_';
    board[38][81] = 'M';
    board[38][82] = 'C';//initialize building in position 37

    board[41][81] = 'C';
    board[41][82] = 'O';
    board[41][83] = 'O';
    board[41][84] = 'P';
    board[42][81] = 'F';
    board[42][82] = 'E';
    board[42][83] = 'E';//initialize building in position 38


    board[47][81] = '_';
    board[47][82] = '_';
    board[47][83] = '_';
    board[47][84] = '_';
    board[47][85] = '_';
    board[47][86] = '_';
    board[47][87] = '_';
    board[48][81] = 'D';
    board[48][82] = 'C';//initialize building in position 39

}

//24 24-64 31

TextDisplay::~TextDisplay() {
    if (board != NULL) {
        for (int i = 0; i < 56; i++) {
            delete [] board[i];
        }
        delete [] board;
    }
    delete [] player;
    board = NULL;
}

void TextDisplay::posnNotify(char name, int cur, int prev) {
    if (prev == -1) {
            int nrow = playerRow(cur, name);
            int ncol = playerColumn(cur, name);
            board[nrow][ncol] = name;
    } else {
            int nrow = playerRow(cur, name);
            int ncol = playerColumn(cur, name);
            int row = playerRow(prev, name);
            int col = playerColumn(prev, name);
            board[nrow][ncol] = name;
            board[row][col] = 32;
    }
}

void TextDisplay::playerRemove(char name, int position) {
    int row = playerRow(position, name);
    int col = playerColumn(position, name);
    board[row][col] = 32;
}

void TextDisplay::init() {
    for (int i = 0; i < playerNum; i++) {
        posnNotify(player[i], 0);
    }
}

//update the level information about the building
void TextDisplay::buildingNotify(int posn, int level, char player) {
    int row = buildingRow(posn, player);
    int col = buildingColumn(posn, player);
    if (level > 0 && level < 6) {
        board[row][col] = player;
        board[row][col+1] = ':';
        for (int i = 0; i < 5; i++) {
            board[row][col+2+i] = 32;
        }
        for (int i = 0; i < level; i++) {
            board[row][col+2+i] = 'I';
        }
    } else if (level == 0) {
         board[row][col] = player;
         for (int i = 0; i < 6; i++) {
            board[row][col+1+i] = 32;
         }
    } else if(level == 6) {
        for (int i = 0; i < 6; i++) {
            board[row][col+i] = 32;
        }
    } else {
        board[row][col] = player;
         for (int i = 0; i < 6; i++) {
            board[row][col+1+i] = 32;
        }
        board[row][col+1] = ':';
        board[row][col+2] = 'B';
        board[row][col+3] = 'A';
        board[row][col+4] = 'N';
        board[row][col+5] = 'K';
    }
}

void TextDisplay::nonAcademicNotify(int posn, char player, bool isMoartgage) {
    int row = buildingRow(posn, player);
    int col = buildingColumn(posn, player);
    if (player == 32) {
        board[row+1][col] = 32;
        board[row+1][col+1] = 32;
        board[row+1][col+2] = 32;
        board[row+1][col+3] = 32;
        board[row+1][col+4] = 32;
        board[row+1][col+5] = 32;
        board[row+1][col+6] = 32;
        board[row+2][col] = 32;
        board[row+2][col+1] = 32;
        board[row+2][col+2] = 32;
        board[row+2][col+3] = 32;
    } else {
        board[row+1][col] = 'O';
        board[row+1][col+1] = 'w';
        board[row+1][col+2] = 'n';
        board[row+1][col+3] = 'e';
        board[row+1][col+4] = 'r';
        board[row+1][col+5] = ':';
        board[row+1][col+6] = player;
        board[row+2][col] = 32;
        board[row+2][col+1] = 32;
        board[row+2][col+2] = 32;
        board[row+2][col+3] = 32;
        if (isMoartgage) {
            board[row+2][col] = 'B';
            board[row+2][col+1] = 'A';
            board[row+2][col+2] = 'N';
            board[row+2][col+3] = 'K';
        }
    }
}


void TextDisplay::print() {
    for (int i = 0; i < 56; i++) {
        for (int j = 0; j < 89; j++) {
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

int TextDisplay::playerRow(int position, char name) {
    int num = 0;
    for (int i = 0; i < currentNum; i++) {
        if (name == player[i]) {
            num = i;
            break;
        }
    }
    int m = num / 7;
    if (position <= 9) {
        return 54 - m;
    } else if (position <= 19) {
        return 54 - (position - 10) * 5 - m;
    } else if (position <= 29) {
        return 4 - m;
    } else {
        return 4 + (position - 30) * 5 - m;
    }
}

int TextDisplay::playerColumn(int position, char name) {
    int num = 0;
    for (int i = 0; i < currentNum; i++) {
        if (name == player[i]) {
            num = i;
            break;
        }
    }
    int m = num % 7;
    if (position <= 9) {
        return 87 - 8 * position - m;
    } else if (position <= 19) {
        return 7 - m;
    } else if (position <= 29) {
        return 7 + (position - 20) * 8 - m;
    } else {
        return 87 - m;
    }
}

int TextDisplay::buildingRow(int position, char name) {
    if (position <= 9) {
        return 51;
    } else if (position <= 19) {
        return 51 - (position - 10) * 5;
    } else if (position <= 29) {
        return 1;
    } else {
        return 1 + (position - 30) * 5;
    }
}

int TextDisplay::buildingColumn(int position, char name) {
    if (position <= 9) {
        return 81 - position * 8;
    } else if (position <= 19) {
        return 1;
    } else if (position <= 29) {
        return 1 + (position - 20) * 8;
    } else {
        return 81;
    }
}

void TextDisplay::addPlayer(char name) {
    player[currentNum] = name;
    currentNum++;
}


