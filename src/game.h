#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include <vector>
#include "observer/subject.h"
#include "observer/textDisplay.h"
#include "board/board.h"
#include "pieces/piece.h"
#include "playerOptions/playerType.h"

/* class Piece;
 */
class Game : public Subject {
    std::unique_ptr<Board> gameBoard;
    // std::unique_ptr<PlayerType> player1;
    // std::unique_ptr<PlayerType> player2;
    std::vector<std::unique_ptr<PlayerType>> players;

    // PlayerType *player1;
    // PlayerType *player2;
    int gameMode;
    //For Set Up Mode
    std::string whoStarts;
    bool manualSetUp;

    int whiteWins;
    int blackWins;
    int ties;

public:
    //ctor dtor?
    Game();
    void startGameLoop();
    void mainGameLoop();
    void move();
    void setupGame(bool normalMode);
    void readSetupMove(std::string in);
    Piece* getState(int row, int col);
};

#endif
