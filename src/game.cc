#include <string>

#include "game.h"
#include "tools/communicator.h"

using namespace std;




void Game::startGameLoop() {

    Communicator communicator;
    while (true) {
        communicator.outputMessage("Welcome to Chess!");
        communicator.outputMessage("Enter a 1 to play Human vs. Human");
        communicator.outputMessage("Enter a 2 to play Human vs. Computer");
        communicator.outputMessage("Enter a 3 to play Computer vs. Computer");

        //try catch
        int gameMode = communicator.takeIntInput();

        if (gameMode == 1) {

        } else if (gameMode == 2) {

        } else if (gameMode == 3) {

        }



    }

}

// Piece* Game::getState(int row, int col) {

//     //return (board.getBoardArr())[row][col];

// }

void Game::move() { 

}

void Game::setup(bool normalMode) {

}