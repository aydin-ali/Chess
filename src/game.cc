#include <string>
#include <sstream>
#include <memory>
#include <iostream>
#include <algorithm>

#include "game.h"

#include "tools/move.h"
#include "playerOptions/human.h"
#include "playerOptions/computerL1.h"
#include "playerOptions/computerL2.h"
#include "playerOptions/computerL3.h"
#include "playerOptions/computerL4.h"


using namespace std;

// Game Constructor
Game::Game():
    gameBoard{make_unique<Board>()}, whoStarts{"white"}, manualSetUp{false}, whiteScore{0}, blackScore{0} {}

void Game::setupGame(bool manualSetup) {

    gameBoard = make_unique<Board>(); //I THINK WE CAN REMOVE the gameboard initialization from the ctor

    //manual setup mode
    if (manualSetUp) {
        while(true){
            string in;
            getline(cin, in);
            stringstream s{in};
            char equal;
            s >> equal;
            string clr;
            s >> clr;
            if(in == "done"){ // NEED TO CHECK IF KING's have been placed
                if(gameBoard->getNumWhiteKings() == 1 && gameBoard->getNumBlackKings() == 1){
                    if(gameBoard->pawnInIllegalRow()){
                        cout << "------You cannot have pawns placed in the first or last rows!------" << endl;
                        notifyObservers(gameBoard->getBoardArr());
                    } else if(gameBoard->InCheck("white") || gameBoard->InCheck("black") || gameBoard->kingBesideKing()){
                        cout << "------You cannot start the game with a king in check!------" << endl;
                    } else {
                        break;
                    }
                }
                else {
                    cout << "------You have to have ONE White King and ONE Black King placed!------" << endl;
                    notifyObservers(gameBoard->getBoardArr());
                }
            } else {
                readSetupMove(in);
            }
        }
        cout << "------You Have Begun a Custom Setup Game!------" << endl;
    } else { //default mode

        gameBoard->setupBoardDefault();

        cin.ignore(); //IDK WHY
        // notifyObservers(gameBoard->getBoardArr());
    }

    notifyObservers(gameBoard->getBoardArr());

    gameBoard->updateBoard();

}

// Read a setup operation 
void Game::readSetupMove(string in){
    vector<char> allowedPieces = {'k', 'K', 'q', 'Q', 'b', 'B', 'n', 'N', 'r', 'R', 'p', 'P'};
    stringstream i;
    i << in;
    string op;
    i >> op;
    if(op == "+"){
        string type;
        i >> type;
        string pos;
        i >> pos;
        int row = 7 - pos[1] + 49;
        int col = pos[0] - 97;
        auto it = find(allowedPieces.begin(), allowedPieces.end(), type[0]);
        if(it == allowedPieces.end()){
            cout << "------That is not a valid piece type to place!------" << endl;
            notifyObservers(gameBoard->getBoardArr());
            return;
        }
        if(row < 0 || row > 7 || col < 0 || col > 7){
            cout << "------That is not a valid position to place a piece!------" << endl;
            notifyObservers(gameBoard->getBoardArr());
            return;
        }
        gameBoard->setupBoardManual(row, col, type[0], op[0]);
        cout << "------Piece successfully added!------" << endl;        
    } else if(op == "-"){
        string pos;
        i >> pos;
        int row = 7 - pos[1] + 49;
        int col = pos[0] - 97;
        if(row < 0 || row > 7 || col < 0 || col > 7){
            cout << "------You did not enter a valid coordinate on the board!------" << endl;
            notifyObservers(gameBoard->getBoardArr());
            return;
        }
        if(gameBoard->getBoardArr()[row][col] == nullptr){
            cout << "------There is no piece there to remove!------" << endl;
            notifyObservers(gameBoard->getBoardArr());
            return;
        }
        gameBoard->setupBoardManual(row, col, gameBoard->getBoardArr()[row][col]->getType(), op[0]);   
        cout << "------Piece successfully removed!------" << endl;     
    } else if(op == "="){
        string colour;
        i >> colour;
        if(colour == "white"){
            whoStarts = "white";
        } else if(colour == "black"){
            whoStarts = "black";
        } else {
            cout << "------You did not enter a valid player colour!------" << endl;
            notifyObservers(gameBoard->getBoardArr());
            return;
        }
        cout << "------Starting player colour successfully changed!------" << endl;
    } else if(op != ""){
        cout << "------That is not a valid setup operator!------" << endl;
    }
    notifyObservers(gameBoard->getBoardArr());
}

// Loop to begin each specific game instance
void Game::startGameLoop() {

    cout << ("Welcome to Chess!") << endl;

    while (!cin.eof()) {

        bool gameModeChosen = false;
        bool setupModeChosen = false;
        string game;
        string whitePlayer;
        string blackPlayer;
        int whiteLevel;
        int blackLevel;

        cout << ("NEW GAME:") << endl;

        // Player selects the match up style of the game instance 
        while (!gameModeChosen) {
            cout << ("Start a game as follows: 'game white-player black-player'") << endl;
            cout << ("'white-player' and 'black-player' can be entered as either 'human' or 'computer[1-4]'") << endl;;

            try {
                string inputLine;
                getline(cin, inputLine);
                stringstream ss {inputLine};
                ss >> game;
                ss >> whitePlayer;
                ss >> blackPlayer;

                if (game == "game") {
                    
                    //first param: white player
                    if (whitePlayer.substr(0,8) == "computer") {
                        try { 
                            whiteLevel = stoi(whitePlayer.substr(8));
                            if (whiteLevel < 1 || whiteLevel > 4) {
                                throw "Enter a valid computer level"; 
                            }
                        } catch (const invalid_argument& other) {
                            throw "Enter a valid computer level";
                        }
                    } else if (whitePlayer != "human") {
                        throw "Enter a valid player type";
                    }

                    //second param: black player
                    if (blackPlayer == "human") {
                        gameModeChosen = true;
                    } else if (blackPlayer.substr(0,8) == "computer") {
                        try { 
                            blackLevel = stoi(blackPlayer.substr(8));
                            if (blackLevel < 1 || blackLevel > 4) {
                                throw "Enter a valid computer level"; 
                            }
                            gameModeChosen = true;
                        } catch (const invalid_argument& other) {
                            throw "Enter a number between 1-3";
                        }
                    } else {
                        throw "Enter a valid player type";
                    }

                }

            } catch (char const* error) {
                cout << endl << "------ Error: " << error << "  ------" << endl << endl;
            } 
        } //end of first while loop


        // Player selects either a default game or to set up their own game
        while (!setupModeChosen) {
            cout << endl << ("Enter 'default' to play normally, Enter 'setup' to setup the board manually") << endl;;

            try {
                string manual;
                cin >> manual;
                if (manual == "setup") {
                    manualSetUp = true;
                    setupModeChosen = true;
                    cout << "------You Have Entered Setup Mode!------" << endl;
                } else if(manual == "default"){
                    manualSetUp = false;
                    setupModeChosen = true;
                    cout << "------You Have Begun A Default Chess Game!------" << endl;
                } else {
                    throw "------Please type one of the options listed!------";
                }
            } catch (char const* error) {
                cout << error << endl;
            }

        } //end of second while loop

        if (gameModeChosen && setupModeChosen) {

            // ------------------- Set player types -------------------
            if (whitePlayer == "human") {
                players.emplace_back(make_unique<Human>("white"));
            } else if (whitePlayer.substr(0,8) == "computer") {
                if (whiteLevel == 1) {
                    // players.emplace_back(make_unique<ComputerL1>("white"));
                } else if (whiteLevel == 2) {
                    // players.emplace_back(make_unique<ComputerL2>("white"));
                } else if (whiteLevel == 3) {
                    // players.emplace_back(make_unique<ComputerL3>("white"));
                } else if (whiteLevel == 4) {
                    // players.emplace_back(make_unique<ComputerL4>("white"));
                }
            }

            if (blackPlayer == "human") {
                players.emplace_back(make_unique<Human>("black"));
            } else if (blackPlayer.substr(0,8) == "computer") {
                if (blackLevel == 1) {
                    // players.emplace_back(make_unique<ComputerL1>("black"));
                } else if (blackLevel == 2) {
                    // players.emplace_back(make_unique<ComputerL2>("black"));
                } else if (blackLevel == 3) {
                    // players.emplace_back(make_unique<ComputerL3>("black"));
                } else if (blackLevel == 4) {
                    // players.emplace_back(make_unique<ComputerL4>("black"));
                }
            }
            // --------------------------------------------------

            //this starts a single instance of a game
            mainGameLoop();

            //after the end of a game:
            players.clear();

            //output all the end of game stats
            cout << "\n------------------------------" << endl;
            cout << "Current Score:" << endl;
            cout << "White: " << whiteScore << endl;
            cout << "Black: " << blackScore << endl;
            cout << "------------------------------" << endl;
            cout << endl;
            //break;
        }
    }
    //output all the end of game stats
    cout << "\n------------------------------" << endl;
    cout << "Final Score:" << endl;
    cout << "White: " << whiteScore << endl;
    cout << "Black: " << blackScore << endl;
    cout << "------------------------------" << endl;
    cout << endl;
}


void Game::mainGameLoop() {

    unique_ptr<TextDisplay> textDisplay = make_unique<TextDisplay>(); //WHY IS THIS MAKING MULTIPLE? double check on someone else
    attach(textDisplay.get());

     unique_ptr<GraphicDisplay> graphicDisplay = make_unique<GraphicDisplay>(8, 8);
     attach(graphicDisplay.get());

    setupGame(manualSetUp);

    if (whoStarts == "black"){
        reverse(players.begin(), players.end());
    }

    int turn = 0;

    //this loop runs the actual game
    while(!cin.eof()) {
        cout << players[turn]->getColour() << " enter a move: ";
        //if s is valid
        string input;
        getline(cin, input);
        stringstream ss {input};
        string cmd;
        ss >> cmd;

        if (cmd == "resign") {
            if (turn == 0) {
                if (players[0]->getColour() == "white") {
                    ++blackScore;
                } else {
                    ++whiteScore;
                }
            } else {
                if (players[1]->getColour() == "white") {
                    ++blackScore;
                } else {
                    ++whiteScore;
                }
            }
            break;
        }

        if (players[turn]->playerMove(input, *gameBoard)) {
            (turn == 0) ? turn = 1 : turn = 0;
        }
        notifyObservers(gameBoard->getBoardArr()); //display the board (after every move command)
        gameBoard->updateBoard(); // updates the boards (after every move command)

        if (gameBoard->getWhiteInCheckmate()) {
            ++blackScore;
            cout << "White is in checkmate!" << endl;
            break;
        } else if (gameBoard->getBlackInCheckmate()) {
            ++whiteScore;
            cout << "Black is in checkmate!" << endl;
            break;
        } else if (gameBoard->getWhiteInCheck()) {
            cout << "White is in check!" << endl;
        } else if (gameBoard->getBlackInCheck()) {
            cout << "Black is in check!" << endl;
        } if (gameBoard->getBoardInStalemate()) {
            whiteScore += 0.5;
            blackScore += 0.5;
            cout << "The board is in stalemate!" << endl;
            break;
        }


    }

    detach(textDisplay.get());
}
