#ifndef COMPUTERL1_H
#define COMPUTERL1_H

#include "computer.h"

class ComputerL1 : public Computer {

public:
    ComputerL1(std::string colour);
    bool playerMove(std::string input, Board &gameBoard) override;

};


#endif

