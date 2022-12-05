#include "pawn.h"
#include "../board/board.h"
#include <iostream>
using namespace std;

Pawn::Pawn(const string colour, int row, int col):
    Piece{colour, 'p', row, col}, hasntMoved{true}, enpassantAble{false}{}


bool Pawn::validMove(Move move, vector<vector<Piece*>> board) {

    //call a function that fills a vector w/ possible moves    
    //all the checking should happen here

    //check if the given move is within the possibleMoves vector
    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it) {
        if ((it->getRow() == move.getEndRow()) && (it->getCol() == move.getEndCol())) {
            return true;
        }
    }
    return false;
}

//side note: pawn promotion and poisson stuff

void Pawn::updatePossibleMoves(vector<vector<Piece*>> board, Board &b) {

    int rowIncrement;
    if (colour == "white") {
        rowIncrement = -1;
        if (posn.getRow() != 6) {
            moved = true; // For double jump
            hasntMoved = false; // For enpassant 
        }
    } else {
        rowIncrement = 1;
        if (posn.getRow() != 1) {
            moved = true; // For double jump
            hasntMoved = false; // For enpassant 
        }
    }

    int row, col;
    Position p = {0, 0};

    possibleMoves.clear();
    
    p = {posn.getRow() + rowIncrement, posn.getCol()};

    //if the pawn hasn't moved yet
    if (p.positionWithinBounds()) {
        if (!moved) { 
            //check 1 square in front
            if (board[p.getRow()][p.getCol()] == nullptr) {
                if (moveAllowed(b, p)) {
                    possibleMoves.emplace_back(p);
                    //if that's a valid move, check 2 squares in front --------
                    p = {posn.getRow() + (rowIncrement * 2), posn.getCol()};
                    if (p.positionWithinBounds()) { //recheck if the new position is valid because we changed it
                        if (board[p.getRow()][p.getCol()] == nullptr) {
                            if (moveAllowed(b, p)) {
                                possibleMoves.emplace_back(p);
                            }
                        }
                    }
                }
                    //---------------------------------------------------------
            }
        } else {
            //check only one square in front
            if (board[p.getRow()][p.getCol()] == nullptr) {
                if (moveAllowed(b, p)) {
                    possibleMoves.emplace_back(p);
                }
            }
            // If pawn is white
            if(colour == "white"){
                // Check if there is nothing to left and then skip
                if (board[posn.getRow()][posn.getCol() - 1] == nullptr){

                }
                // Check if there is enemy pawn to left
                else if (board[posn.getRow()][posn.getCol() - 1]->getType() == 'p' && board[posn.getRow()][posn.getCol() - 1]->getColour() != colour){
                    Pawn *pwn = static_cast<Pawn*>(board[posn.getRow()][posn.getCol() - 1]);
                    if(pwn->getEnpassantAble()){ // if the opposing piece meets all enpassant conditions
                        p = {posn.getRow() - 1, posn.getCol() - 1};
                        possibleMoves.emplace_back(p);
                    }
                } 
                // Check if there is nothing to right and then skip
                if (board[posn.getRow()][posn.getCol() + 1] == nullptr){

                }
                // Check if there is enemy pawn to right
                else if(board[posn.getRow()][posn.getCol() + 1]->getType() == 'p' && board[posn.getRow()][posn.getCol() + 1]->getColour() != colour){
                    Pawn *pwn = static_cast<Pawn*>(board[posn.getRow()][posn.getCol() + 1]);
                    if(pwn->getEnpassantAble()){ // if the opposing piece meets all enpassant conditions
                        p = {posn.getRow() - 1, posn.getCol() + 1};
                        possibleMoves.emplace_back(p);
                    }
                }
            }
            // If pawn is black 
            else {
                // Check if there is nothing to left and then skip
                if (board[posn.getRow()][posn.getCol() - 1] == nullptr){

                }
                // Check if there is enemy pawn to left
                else if (board[posn.getRow()][posn.getCol() - 1]->getType() == 'p' && board[posn.getRow()][posn.getCol() - 1]->getColour() != colour){
                    Pawn *pwn = static_cast<Pawn*>(board[posn.getRow()][posn.getCol() - 1]);
                    if(pwn->getEnpassantAble()){ // if the opposing piece meets all enpassant conditions
                        p = {posn.getRow() + 1, posn.getCol() - 1};
                        possibleMoves.emplace_back(p);
                    }
                    possibleMoves.emplace_back(p);
                } 
                // Check if there is nothing to right and then skip
                if (board[posn.getRow()][posn.getCol() + 1] == nullptr){

                }
                // Check if there is enemy pawn to right
                else if(board[posn.getRow()][posn.getCol() + 1]->getType() == 'p' && board[posn.getRow()][posn.getCol() + 1]->getColour() != colour){
                    Pawn *pwn = static_cast<Pawn*>(board[posn.getRow()][posn.getCol() + 1]);
                    if(pwn->getEnpassantAble()){ // if the opposing piece meets all enpassant conditions
                        p = {posn.getRow() + 1, posn.getCol() + 1};
                        possibleMoves.emplace_back(p);
                    }
                }
            }
        }      
    }

    //check if pawn can move diaganolly (if there is an opposing colours piece at that position)
    //diagonal right
    p = {posn.getRow() + rowIncrement, posn.getCol() + 1};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr && board[p.getRow()][p.getCol()]->getColour() != colour){
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }
    //diagonal left
    p = {posn.getRow() + rowIncrement, posn.getCol() - 1};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr && board[p.getRow()][p.getCol()]->getColour() != colour){
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }
}

bool Pawn::getHasntMoved(){
    return hasntMoved;
}

void Pawn::setEnpassantAble(bool set){
    enpassantAble = set;
}

bool Pawn::getEnpassantAble(){
    return enpassantAble;
}
//if the pawn moving leads to its own king being checked (LATER)

//side note: to keep track of wins/losses in player, write a visitor?