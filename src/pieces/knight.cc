#include "knight.h"
using namespace std;

Knight::Knight(const string &colour):
    Piece{colour, 'n'}{}

bool Knight::validMove(Move move, vector<vector<Piece*>> board) {
    return true;
}


void Knight::updatePossibleMoves(Move move, vector<vector<Piece*>>) {
    
}
