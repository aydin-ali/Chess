#ifndef COMPUTERL2_H
#define COMPUTERL2_H

#include "computer.h"

class ComputerL2 : public Computer {

public:
    ComputerL2(std::string colour);
    bool playerMove(std::string input, Board &gameBoard) override;
};


#endif






