#ifndef HUMAN_H
#define HUMAN_H

#include "playerType.h"

class Human : public PlayerType {

public:
    Human(std::string colour);
    void playerMove() override;

};

#endif
