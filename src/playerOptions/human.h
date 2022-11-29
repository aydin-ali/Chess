#ifndef HUMAN_H
#define HUMAN_H

#include "playerType.h"

class Human : public PlayerType {

public:
    Human();
    void playerMove() override;

};

#endif
