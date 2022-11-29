#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include <vector>
#include "observer/subject.h"
#include "board/board.h"
#include "tools/communicator.h"

class Piece;

class Game : public Subject {
    std::unique_ptr<Board> gameBoard;
    Communicator communicator;
    bool whiteFirst;

public:
    //ctor dtor?
    Game();
    void startGameLoop();
    void move();
    void setup(bool normalMode);
    Piece* getState(int row, int col);

};

#endif