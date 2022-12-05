#ifndef HUMAN_H
#define HUMAN_H

#include "playerType.h"

class Human : public PlayerType {

public:
    Human(std::string colour);
    bool playerMove(std::string input, Board &gameBoard) override;

};

#endif
