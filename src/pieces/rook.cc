#include "rook.h"
using namespace std;

Rook::Rook(const string &colour):
    Piece{colour, 'r'}{}

bool Rook::validMove(Move move, vector<vector<Piece*>> board) {
    return true;
}

void Rook::updatePossibleMoves(Move move, vector<vector<Piece*>>) {
    
}
