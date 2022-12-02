#include "queen.h"
using namespace std;

Queen::Queen(const string &colour, int row, int col):
    Piece{colour, 'q', row, col}{}

bool Queen::validMove(Move move, vector<vector<Piece*>> board) {
    return true;
}

void Queen::updatePossibleMoves(Move move, vector<vector<Piece*>>) {
    
}
