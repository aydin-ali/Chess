#ifndef COMPUTERL3_H
#define COMPUTERL3_H

#include "computer.h"

class ComputerL3 : public Computer {

public:
    ComputerL3(std::string colour);
    void playerMove() override;

};


#endif
