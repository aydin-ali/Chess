#include "piece.h"
using namespace std;

class Move;

Piece::Piece(const string &colour, const char &type, int row, int col):
    colour{colour}, type{type}, posn{row, col}, moved{false} {}

Piece::~Piece() {}

bool Piece::validMove(Move move, vector<vector<Piece*>> board){
    return true;
}

string Piece::getColour(){
    return colour;
}

char Piece::getType(){
    return type;
}

bool Piece::isMoved(){
    return moved;
}

void Piece::updatePosn(int row, int col) {
    posn = {row, col};
}

