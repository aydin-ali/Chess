#include "bishop.h"
using namespace std;

Bishop::Bishop(const string &colour, int row, int col):
    Piece{colour, 'b', row, col}{}

bool Bishop::validMove(Move move, vector<vector<Piece*>> board) {
    return true;
}

void Bishop::updatePossibleMoves(Move move, vector<vector<Piece*>>) {
    
}

