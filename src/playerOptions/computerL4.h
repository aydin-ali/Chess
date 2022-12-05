#ifndef COMPUTERL4_H
#define COMPUTERL4_H

#include "computer.h"

class ComputerL4 : public Computer {

public:
    ComputerL4(std::string colour);
    bool playerMove(std::string input, Board &gameBoard) override;

};


#endif
