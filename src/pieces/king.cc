#include "king.h"
using namespace std;

King::King(const string &colour):
    Piece{colour, 'k'}{}

bool King::validMove(Move move, vector<vector<Piece*>> board) {
    return true;
}


void King::updatePossibleMoves(Move move, vector<vector<Piece*>>) {
    
}
