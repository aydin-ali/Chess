#include "piece.h"
using namespace std;

Piece::Piece(const string &colour, const char &type):
    colour{colour}, type{type}, moved{false}{}

Piece::~Piece() {}

string Piece::getColour(){
    return colour;
}

char Piece::getType(){
    return type;
}

bool Piece::isMoved(){
    return moved;
}

