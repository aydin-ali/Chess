#ifndef GAME_H
#define GAME_H

#include "subject.h"
#include "board.h"
#include "communicator.h"

class Piece;

class Game : public Subject {

private:
    Board board;
    Communicator communicator;

public:
    //ctor dtor?
    void move();
    void setup(bool normalMode);
    Piece* getState(int row, int col);


};

#endif