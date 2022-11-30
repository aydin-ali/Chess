#include <string>
#include <sstream>
#include <memory>
#include <iostream> //FOR NOW IN CASE WE DECIDE THE COMMUNICATOR IS STUPID

#include "game.h"
//#include "tools/communicator.h"

#include "playerOptions/human.h"
#include "playerOptions/computerL1.h"


using namespace std;

Game::Game():
    gameBoard{make_unique<Board>()}, whiteFirst{true}{}

void Game::setupGame(bool normalMode) {
    unique_ptr<TextDisplay> textDisplay = make_unique<TextDisplay>();
    attach(textDisplay.get());

    gameBoard->setupBoard();
    vector<vector<Piece*>> &b = gameBoard->getBoardArr();
    if(normalMode){
        notifyObservers(b);
    }
}

void Game::startGameLoop() {
    setupGame(true);

    //Communicator communicator;
    cout << ("Welcome to Chess!") << endl;
    cout << ("Enter a 1 to play Human vs. Human") << endl;
    cout << ("Enter a 2 to play Human vs. Computer") << endl;
    cout << ("Enter a 3 to play Computer vs. Computer") << endl;;

    while (true) {

        try {
            // string gm = communicator.takeInput();
            string gm;
            cin >> gm;
            istringstream iss {gm};
            if (iss >> gameMode) {
                if (gameMode < 1 || gameMode > 3) throw "Enter a number between 1-3";
            } else {
                throw "Enter a number between 1-3";
            }
        } catch (char const* error) {
            cout << error << endl;
        } 

        if (gameMode > 0 && gameMode < 3) {

            if (gameMode == 1) {
                
                player1 = make_unique<Human>();
                player2 = make_unique<Human>();

            } else if (gameMode == 2) {
            } else if (gameMode == 3) {
            } 
            mainGameLoop();
        }

    }

}

void Game::mainGameLoop() {
    //call board ctor
    //setupBoard();
    cout << "player 1 enter a move: " << endl;
    string s;
    string start;
    string end;
    int beginEnd = 0;
    while(cin >> s) {
        //if s is valid
        
        if (beginEnd == 1) {
            end = s;
        } else {
            start = s;
            beginEnd = 0;
        }
        
    }
}

// Check if the moves inputted are within the bounds of the board
bool moveOutOfRange(int startRow, int startCol, int endRow, int endCol){
    if((startRow < 0 || startRow > 7) || (startCol < 0 || startCol > 7) || (endRow < 0 || endRow > 7) || (endCol < 0 || endCol > 7)){
        return true;
    } else {
        return false;
    }
}

// Read move from cin and process it
bool readMove(string in) {
    stringstream i;
    i << in;
    string trash;
    i >> trash;
    string startPos;
    i >> startPos;
    string endPos;
    i >> endPos;
    int startRow = startPos[0] - 97;
    int endRow = endPos[0] - 97;
    int startCol = startPos[1] - 49;
    int endCol = endPos[1] - 49;
    if(moveOutOfRange(startRow, startCol, endRow, endCol)){
        return false;  
    }
    // NEED TO PUT THE END POSITIONS INTO SOMETHING
    return true;
}



// Piece* Game::getState(int row, int col) {

//     //return (board.getBoardArr())[row][col];

// }

void Game::move() { 

}

