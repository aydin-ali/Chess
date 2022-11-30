#ifndef HUMAN_H
#define HUMAN_H

#include "playerType.h"

class Human : public PlayerType {

public:
    Human(char colour);
    void playerMove() override;

};

#endif
