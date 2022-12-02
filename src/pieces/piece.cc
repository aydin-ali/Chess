#include "piece.h"
using namespace std;

class Move;

Piece::Piece(const string &colour, const char &type):
    colour{colour}, type{type}, moved{false}{}

Piece::~Piece() {}

bool Piece::validMove(Move move, vector<vector<Piece*>>){
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


