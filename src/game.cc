#include <string>
#include <sstream>

#include <iostream> //FOR NOW IN CASE WE DECIDE THE COMMUNICATOR IS STUPID


#include "game.h"
#include "tools/communicator.h"

using namespace std;




void Game::startGameLoop() {

    Communicator communicator;
    communicator.outputMessage("Welcome to Chess!");
    communicator.outputMessage("Enter a 1 to play Human vs. Human");
    communicator.outputMessage("Enter a 2 to play Human vs. Computer");
    communicator.outputMessage("Enter a 3 to play Computer vs. Computer");

    while (true) {
        int gameMode;
        try {
            string gm = communicator.takeInput();
            istringstream iss {gm};
            if (iss >> gameMode) {
                if (gameMode < 1 || gameMode > 3) throw "Enter a number between 1-3";
            } else {
                throw "Enter a number between 1-3";
            }
        } catch (char const* error) {
            communicator.outputMessage(error);
        } 

        if (gameMode > 0 && gameMode < 3) {

            //create players here

            if (gameMode == 1) {

                //output board here
                communicator.outputMessage("Player 1, Enter move:");
                try {
                    string start = communicator.takeInput();
                    string end = communicator.takeInput();

                    
                } catch (char const* error) {
                    communicator.outputMessage(error);
                } 


            } else if (gameMode == 2) {
                communicator.outputMessage("2");
            } else if (gameMode == 3) {
                communicator.outputMessage("3");
            } 
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