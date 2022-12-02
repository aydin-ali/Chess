#include "queen.h"
using namespace std;

Queen::Queen(const string &colour):
    Piece{colour, 'q'}{}

bool Queen::validMove(Move move, vector<vector<Piece*>> board) {
    return true;
}

void Queen::updatePossibleMoves(Move move, vector<vector<Piece*>>) {
    
}
