#include "king.h"
using namespace std;

King::King(const string &colour, int row, int col):
    Piece{colour, 'k', row, col}, hasMoved{false}, initPosn{row, col}{}

bool King::validMove(Move move, vector<vector<Piece*>> board) {
    return true;
}


void King::updatePossibleMoves(vector<vector<Piece*>>) {
    if (posn.getRow() != initPosn.getRow() || posn.getCol() != initPosn.getCol()) {
        hasMoved = true; 
    }
    possibleMoves.clear();
}
