#include "king.h"
using namespace std;

King::King(const string &colour):
    Piece{colour, 'k'}{}

bool King::validMove(Move move) {
    return true;
}
