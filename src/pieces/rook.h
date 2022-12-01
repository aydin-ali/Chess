#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include <string>

class Rook : public Piece{
public:
    Rook(const std::string &colour);
    bool validMove(Move move) override;

};

#endif

