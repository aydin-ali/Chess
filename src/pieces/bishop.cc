#include "bishop.h"
using namespace std;

Bishop::Bishop(const string &colour):
    Piece{colour, 'b'}{}

bool Bishop::validMove(Move move) {
    return true;
}
