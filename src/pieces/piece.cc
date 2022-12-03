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

Position Piece::getPosn() {
    return posn;
}

bool Piece::isMoved(){
    return moved;
}

bool Piece::inPossibleMoves(Position p) {
    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it) {
        if ((*it) == p) return true;
    }
    return false;
}

void Piece::updatePosn(int row, int col) {
    posn = {row, col};
}

