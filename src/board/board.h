#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <map>
#include <vector>
#include <memory>

class Piece;
// don't need class Piece here because it's in game????

class Board {

private:

    Piece* boardArr[8][8];

    std::map<std::string, Piece*> boardMap;

public:
    void setupBoard();
    void moveOnBoard();
    //Piece[][] getBoardArr();

};

#endif

