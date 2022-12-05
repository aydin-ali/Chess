#include <iostream>
#include <sstream>
#include "../tools/move.h" 
#include "../board/board.h"

#include "human.h"

using namespace std;


Human::Human(std::string colour) : PlayerType{colour} {

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

bool Human::playerMove(string input, Board &gameBoard) {

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
        Move m {startPos, endPos, colour};


        // Check if move is valid            
        if (gameBoard.validMoveOnBoard(m)) { 
            // Check if piece is a pawn
            if(gameBoard.getBoardArr()[m.getStartRow()][m.getStartCol()] != nullptr && gameBoard.getBoardArr()[m.getStartRow()][m.getStartCol()]->getType() == 'p'){
                // Check if pawn is in position to promote 
                if (gameBoard.inPositionToPromote(m)) {
                    // Check all other conditions for pawn to actually promote
                    if(gameBoard.canPromote(m, gameBoard.getBoardArr()[m.getStartRow()][m.getStartCol()]->getColour(), promoteType)){
                        gameBoard.moveOnBoard(m);
                        gameBoard.actuallyPromote(m, gameBoard.getBoardArr()[m.getEndRow()][m.getEndCol()]->getColour(), promoteType);
                        promoteType = ' ';
                    } else {
                        cout << "------Not a valid piece to promote your pawn to!------" << endl;
                        //notifyObservers(gameBoard->getBoardArr());
                        return false;
                    }
                } else {
                    gameBoard.moveOnBoard(m);
                }
            } else {
                gameBoard.moveOnBoard(m);
            }
            // (turn == 0) ? turn = 1 : turn = 0;
            //print the new board
            //notifyObservers(gameBoard->getBoardArr());
            return true;
            
        } else {
            cout << "Invalid move: Invalid position(s)" << endl << endl;
        }

    } else {
        cout << "Invalid move: Invalid input" << endl << endl;
    }

    return false;

}
