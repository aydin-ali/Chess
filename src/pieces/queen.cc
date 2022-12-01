#include "queen.h"
using namespace std;

Queen::Queen(const string &colour):
    Piece{colour, 'q'}{}

bool Queen::validMove(Move move) {
    return true;
}
