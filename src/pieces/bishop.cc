#include "bishop.h"
using namespace std;

Bishop::Bishop(const string &colour):
    Piece{colour, 'b'}{}

bool Bishop::validMove(Move move, vector<vector<Piece*>> board) {
    return true;
}

void Bishop::updatePossibleMoves(Move move, vector<vector<Piece*>>) {
    
}

