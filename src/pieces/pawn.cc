#include "pawn.h"
using namespace std;

Pawn::Pawn(const string colour):
    Piece{colour, 'p'}{}

bool Pawn::validMove(Move move, vector<vector<Piece*>> board) {
    //rmb we're passing the board*

    //call a function (pass move and board) that fills a vector w/ possible moves    
    //all the checking should happen here

    if (!moved) { //if the pawn hasn't moved yet
        //pawn can move forward twice
    } else {
        //pawn can only move forward one spot
        //check if that spot is being blocked (own colour or opposing colour)
        //pawn can move diaganolly (one left/right then one up) if there is an opposing colours piece 
        //if the pawn moving leads to its own king being checked (LATER)
    }




    //check if move exists within the possibleMoves vector
    return true;
}

void Pawn::updatePossibleMoves(Move move, vector<vector<Piece*>>) {
    
}


//side note: to keep track of wins/losses in player, write a visitor?


