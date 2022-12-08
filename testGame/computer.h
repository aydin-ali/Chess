#ifndef COMPUTER_H
#define COMPUTER_H

#include "playerType.h"

class Computer : public PlayerType{

public:
    Computer(std::string colour);
    virtual bool playerMove(std::string input, Board &gameBoard);

};

#endif






