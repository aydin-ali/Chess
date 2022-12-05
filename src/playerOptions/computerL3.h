#ifndef COMPUTERL3_H
#define COMPUTERL3_H

#include "computer.h"

class ComputerL3 : public Computer {

public:
    ComputerL3(std::string colour);
    bool playerMove(std::string input, Board &gameBoard) override;

};


#endif
