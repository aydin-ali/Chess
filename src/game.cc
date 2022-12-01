#include <string>
#include <sstream>
#include <memory>
#include <iostream> //FOR NOW IN CASE WE DECIDE THE COMMUNICATOR IS STUPID

#include "game.h"
//#include "tools/communicator.h"

#include "tools/move.h" //can we make this just: class Move;?
#include "playerOptions/human.h"
#include "playerOptions/computerL1.h"


using namespace std;

Game::Game():
    gameBoard{make_unique<Board>()}, whiteFirst{true}, whoStarts{"white"}, manualSetUp{false}{}

void Game::setupGame(bool manualSetup) {
    unique_ptr<TextDisplay> textDisplay = make_unique<TextDisplay>();
    attach(textDisplay.get());

    if(manualSetUp){
        while(true){
            string in;
            getline(cin, in);
            if(in == "done"){ // NEED TO CHECK IF KING's have been placed
                if(gameBoard->getNumWhiteKings() == 1 && gameBoard->getNumBlackKings() == 1) break;
                else{
                    cout << "You have to have ONE White King and ONE Black King placed!" << endl;
                    notifyObservers(gameBoard->getBoardArr());
                    }
            } else {
                readSetupMove(in);
            }
        }
        cout << "Loop broken" << endl;
    } else {
        gameBoard->setupBoardDefault();
        vector<vector<Piece*>> &b = gameBoard->getBoardArr();
        notifyObservers(b);
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
    // NEED TO PUT THE END POSITIONS INTO SOMETHING
    return true;
}

void Game::readSetupMove(string in){
    stringstream i;
    i << in;
    string op;
    i >> op;
    if(op == "+"){
        string type;
        i >> type;
        string pos;
        i >> pos;
        int row = pos[0] - 97;
        int col = pos[1] - 49;
        gameBoard->setupBoardManual(row, col, type[0], op[0]);        
    }
    if(op == "-"){
        string pos;
        i >> pos;
        int row = pos[0] - 97;
        int col = pos[1] - 49;

        gameBoard->setupBoardManual(row, col, gameBoard->getBoardArr()[row][col]->getType(), op[0]);        
    }
    if(op == "="){
        string colour;
        i >> colour;
        if(colour == "white"){
            whoStarts = "white";
        } else if(colour == "black"){
            whoStarts = "black";
        } else {
            //MAKE BEHAVIOUR FOR NON-ACCEPTED BEHAVIOUR
        }
    }

    
    notifyObservers(gameBoard->getBoardArr());
}


void Game::startGameLoop() {

    //Communicator communicator;
    cout << ("Welcome to Chess!") << endl;

    while (!cin.eof()) {

        bool gameModeChosen = false;
        bool setupModeChosen = false;

        while (!gameModeChosen) {
            cout << ("Enter a 1 to play Human vs. Human") << endl;
            cout << ("Enter a 2 to play Human vs. Computer") << endl;
            cout << ("Enter a 3 to play Computer vs. Computer") << endl;;

            try {
                // string gm = communicator.takeInput();
                string gm;
                getline(cin, gm);
                istringstream iss {gm};
                if (iss >> gameMode) {
                    if (gameMode < 1 || gameMode > 3) throw "Enter a number between 1-3";
                    gameModeChosen = true;
                } else {
                    throw "Enter a number between 1-3";
                }
            } catch (char const* error) {
                cout << error << endl;
            } 
        }

        while (!setupModeChosen) {
            cout << ("Enter 'default' to play normally, Enter 'setup' to setup the board manually") << endl;;

            try {
                string manual;
                cin >> manual;
                if (manual == "setup") {
                    manualSetUp = true;
                    setupModeChosen = true;
                } else if(manual == "default"){
                    manualSetUp = false;
                    setupModeChosen = true;
                } else {
                    throw "Please type one of the options listed!";
                }
            } catch (char const* error) {
                cout << error << endl;
            }

        }

        if (gameMode > 0 && gameMode < 3) {

            if (gameMode == 1) {
                
                // player1 = make_unique<Human>('W');
                // player2 = make_unique<Human>('B');
                players.emplace_back(make_unique<Human>("white"));
                players.emplace_back(make_unique<Human>("black"));


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

    unique_ptr<TextDisplay> textDisplay = make_unique<TextDisplay>();
    attach(textDisplay.get());

    setupGame(manualSetUp);

    int turn = 0;
    cin.ignore();
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


            //convert the string to a move object
            Move m {startPos, endPos, players[turn]->getColour()};
            //check if the move is valid (board + piece wise)
            
            if (gameBoard->moveOnBoard(m)) { 
                
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




// Piece* Game::getState(int row, int col) {

//     //return (board.getBoardArr())[row][col];

// }

void Game::move() { 

}

