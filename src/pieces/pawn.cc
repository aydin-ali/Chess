#include "pawn.h"
using namespace std;

Pawn::Pawn(const string colour):
    Piece{colour, 'p'}{}

bool Pawn::validMove(Move move) {
    return true;
}
