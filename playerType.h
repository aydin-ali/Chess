#ifndef PLAYERTYPE_H
#define PLAYERTYPE_H

#include <string>
#include <vector>
#include <memory>

#include "piece.h"

class Board;

class PlayerType {

private:
    std::string colour;


public:

    PlayerType(std::string colour);
    virtual bool playerMove(std::string input, Board &gameBoard);
    virtual ~PlayerType() = 0;
    std::string getColour();

};

#endif







