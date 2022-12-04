#include <string>
#include <sstream>
#include <memory>
#include <iostream>
#include <algorithm>

#include "game.h"

#include "tools/move.h" //can we make this just: class Move;?
#include "playerOptions/human.h"
#include "playerOptions/computerL1.h"


using namespace std;

// Game Constructor
Game::Game():
    gameBoard{make_unique<Board>()}, whoStarts{"white"}, manualSetUp{false}{}



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
                if(gameBoard->getNumWhiteKings() == 1 && gameBoard->getNumBlackKings() == 1) break;
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
    return true;
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
        }


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

        }

        if (gameModeChosen && setupModeChosen) {

            if (whitePlayer == "human") {
                players.emplace_back(make_unique<Human>("white"));
            } else if (whitePlayer.substr(0,8) == "computer") {
                if (whiteLevel == 1) {

                } else if (whiteLevel == 2) {

                } else if (whiteLevel == 3) {

                } else if (whiteLevel == 4) {

                }
            }

            if (blackPlayer == "human") {
                players.emplace_back(make_unique<Human>("black"));
            } else if (blackPlayer.substr(0,8) == "computer") {
                if (blackLevel == 1) {

                } else if (blackLevel == 2) {

                } else if (blackLevel == 3) {

                } else if (blackLevel == 4) {
                    
                }
            }

            //this starts a single instance of a game
            mainGameLoop();
            //output all the end of game stats
            cout << "White wins: " << endl;
            cout << "Black wins: " << endl;
            cout << "------------------------------" << endl;
            cout << endl;
            //break;
        }
    }
}


void Game::mainGameLoop() {

    unique_ptr<TextDisplay> textDisplay = make_unique<TextDisplay>();
    attach(textDisplay.get());

    // unique_ptr<GraphicDisplay> graphicDisplay = make_unique<GraphicDisplay>(8, 8);
    // attach(graphicDisplay.get());


    setupGame(manualSetUp);

    if(whoStarts == "black"){
        reverse(players.begin(), players.end());
    }

    int turn = 0;

    while(!cin.eof()) {
        cout << players[turn]->getColour() << " enter a move: ";
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

        //check if the move entered is valid (input wise)
        if (readMove(input)) {

            //TEMPORARY
            stringstream i;
            i << input;
            string trash;
            i >> trash;
            string startPos;
            i >> startPos;
            string endPos;
            i >> endPos;
            char promoteType;
            i >> promoteType;


            //convert the string to a move object
            Move m {startPos, endPos, players[turn]->getColour()};

            // Check if move is valid            
            if (gameBoard->validMoveOnBoard(m)) { 
                // Check if piece is a pawn
                if(gameBoard->getBoardArr()[m.getStartRow()][m.getStartCol()] != nullptr && gameBoard->getBoardArr()[m.getStartRow()][m.getStartCol()]->getType() == 'p'){
                    // Check if pawn is in position to promote 
                    if (gameBoard->inPositionToPromote(m)) {
                        // Check all other conditions for pawn to actually promote
                        if(gameBoard->canPromote(m, gameBoard->getBoardArr()[m.getStartRow()][m.getStartCol()]->getColour(), promoteType)){
                            gameBoard->moveOnBoard(m);
                            gameBoard->actuallyPromote(m, gameBoard->getBoardArr()[m.getEndRow()][m.getEndCol()]->getColour(), promoteType);
                            promoteType = ' ';
                        } else {
                            cout << "------Not a valid piece to promote your pawn to!------" << endl;
                            notifyObservers(gameBoard->getBoardArr());
                            continue;
                        }
                    } else {
                        gameBoard->moveOnBoard(m);
                    }
                } else {
                    gameBoard->moveOnBoard(m);
                }
                (turn == 0) ? turn = 1 : turn = 0;
                //print the new board
                notifyObservers(gameBoard->getBoardArr());
                
            } else {
                cout << "Invalid move: Invalid position(s)" << endl << endl;
            }

        } else {
            cout << "Invalid move: Invalid input" << endl << endl;
        }
    }
}
