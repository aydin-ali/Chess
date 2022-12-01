#include "rook.h"
using namespace std;

Rook::Rook(const string &colour):
    Piece{colour, 'r'}{}

bool Rook::validMove(Move move) {
    return true;
}
