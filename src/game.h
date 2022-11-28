#ifndef GAME_H
#define GAME_H

#include <string>

#include "observer/subject.h"
#include "board/board.h"
#include "tools/communicator.h"

class Piece;

class Game : public Subject {


private:

    Board board;
    Communicator communicator;
    


public:
    //ctor dtor?
    void startGameLoop();
    void move();
    void setup(bool normalMode);
    Piece* getState(int row, int col);

};

#endif