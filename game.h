#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include <vector>
#include "subject.h"
#include "textDisplay.h"
#include "graphicDisplay.h"
#include "board.h"
#include "piece.h"
#include "playerType.h"

/* class Piece;
 */
class Game : public Subject {
    std::unique_ptr<Board> gameBoard;
    // std::unique_ptr<PlayerType> player1;
    // std::unique_ptr<PlayerType> player2;
    std::vector<std::unique_ptr<PlayerType>> players;

    //For Set Up Mode
    std::string whoStarts;
    bool manualSetUp;

    float whiteScore;
    float blackScore;

public:
    //ctor dtor?
    Game();
    void startGameLoop();
    bool mainGameLoop();
    void move();
    bool setupGame(bool normalMode);
    void readSetupMove(std::string in);
    Piece* getState(int row, int col);
};

#endif






