#include "rook.h"
using namespace std;

Rook::Rook(const string &colour, int row, int col):
    Piece{colour, 'r', row, col}{}

bool Rook::validMove(Move move, vector<vector<Piece*>> board) {
    return true;
}

void Rook::updatePossibleMoves(Move move, vector<vector<Piece*>>) {
    
}
