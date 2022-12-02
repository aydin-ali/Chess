#include "pawn.h"
using namespace std;

Pawn::Pawn(const string colour):
    Piece{colour, 'p'}{}

bool Pawn::validMove(Move move, vector<vector<Piece*>> board) {
    //rmb we're passing the board*

    //call a function (pass move and board) that fills a vector w/ possible moves    
    //all the checking should happen here
    updatePossibleMoves(move, board);


    //check if move exists within the possibleMoves vector
    return true;
}

//side note: pawn promotion and poisson stuff

void Pawn::updatePossibleMoves(Move move, vector<vector<Piece*>> board) {
    int rowIncrement;
    if (colour == "white") {
        rowIncrement = -1;
    } else {
        rowIncrement = 1;
    }

    if (!moved) { //if the pawn hasn't moved yet
        //check 1 sq in front
        if (board[move.getStartRow() + rowIncrement][move.getStartCol()] != nullptr) {
            possibleMoves.emplace_back(Position{
                move.getStartRow()+rowIncrement, 
                move.getStartCol()
            });
        }

 
        //if that's a valid move, check 2 squares in front
    } else {
        //check one sq in front
        //check if that spot is being blocked (own colour or opposing colour)
        //if the pawn moving leads to its own king being checked (LATER)
    }
    //check if -> pawn can move diaganolly (one left/right then one up) if there is an opposing colours piece 


}



//side note: to keep track of wins/losses in player, write a visitor?


