#include "pawn.h"
using namespace std;

Pawn::Pawn(const string colour, int row, int col):
    Piece{colour, 'p', row, col}{}


bool Pawn::validMove(Move move, vector<vector<Piece*>> board) {

    //call a function that fills a vector w/ possible moves    
    //all the checking should happen here
    updatePossibleMoves(board);

    //check if the given move is within the possibleMoves vector
    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it) {
        if ((it->getRow() == move.getEndRow()) && (it->getCol() == move.getEndCol())) {
            return true;
        }
    }
    return false;
}

/* bool Pawn::canPromote(){
    if(colour == "white"){
        if(posn.getRow() == 0) return true; 
        else return false;
    } else {
        if(posn.getRow() == 7) return true; 
        else return false;
    }
} */

//side note: pawn promotion and poisson stuff

void Pawn::updatePossibleMoves(vector<vector<Piece*>> board) {

    int rowIncrement;
    if (colour == "white") {
        rowIncrement = -1;
    } else {
        rowIncrement = 1;
    }

    int row, col;
    Position p = {0, 0};
    
    row = posn.getRow() + rowIncrement;
    col = posn.getCol();
    p = {row, col};

    //if the pawn hasn't moved yet
    if (p.positionWithinBounds()) {
        if (!moved) { 
            //check 1 square in front
            if (board[p.getRow()][p.getCol()] == nullptr) {
                possibleMoves.emplace_back(p);
                
                //if that's a valid move, check 2 squares in front --------
                row = posn.getRow() + (rowIncrement * 2);
                col = posn.getCol();
                p = {row, col};
                if (p.positionWithinBounds()) { //recheck if the new position is valid because we changed it
                    if (board[p.getRow()][p.getCol()] == nullptr) {
                        possibleMoves.emplace_back(p);
                    }
                }
                //---------------------------------------------------------
            }
        } else {
            //check only one square in front
            if (board[p.getRow()][p.getCol()] == nullptr) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    //check if pawn can move diaganolly (if there is an opposing colours piece at that position)
    //diagonal right
    row = posn.getRow() + rowIncrement;
    col = posn.getCol() + 1;
    p = {row, col};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr && board[p.getRow()][p.getCol()]->getColour() != colour){
            possibleMoves.emplace_back(p);
        }
    }
    //diagonal left
    row = posn.getRow() + rowIncrement;
    col = posn.getCol() - 1;
    p = {row, col};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr && board[p.getRow()][p.getCol()]->getColour() != colour){
            possibleMoves.emplace_back(p);
        }
    }

}

//if the pawn moving leads to its own king being checked (LATER)


//side note: to keep track of wins/losses in player, write a visitor?


