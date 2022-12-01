#include "knight.h"
using namespace std;

Knight::Knight(const string &colour):
    Piece{colour, 'n'}{}

bool Knight::validMove(Move move) {
    return true;
}
