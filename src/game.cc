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

    //Communicator communicator;
    cout << ("Welcome to Chess!") << endl;

    while (!cin.eof()) {
    cout << ("Enter a 1 to play Human vs. Human") << endl;
    cout << ("Enter a 2 to play Human vs. Computer") << endl;
    cout << ("Enter a 3 to play Computer vs. Computer") << endl;;

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
                
                // player1 = make_unique<Human>('W');
                // player2 = make_unique<Human>('B');
                players.emplace_back(make_unique<Human>('W'));
                players.emplace_back(make_unique<Human>('B'));


            } else if (gameMode == 2) {
            } else if (gameMode == 3) {
            } 
            //this starts a single instance of a game
            mainGameLoop();
            //output all the end of game stats
            //break;
        }

    }

}

void Game::mainGameLoop() {

    setupGame(true);

    int turn = 0;
    cin.ignore();
    while(!cin.eof()) {


        cout << players[turn]->getColour() << " enter a move: " << endl;
        //if s is valid
        string input;
        getline(cin, input);
        stringstream ss {input};
        string cmd;
        ss >> cmd;

        if (cmd == "resign") {
            //update win counters
            cout << endl;
            return;
        }




        if (turn == 0) {
            turn = 1;
        } else if (turn == 1) {
            turn = 0;
        }

    }

    

}

// Piece* Game::getState(int row, int col) {

//     //return (board.getBoardArr())[row][col];

// }

void Game::move() { 

}

