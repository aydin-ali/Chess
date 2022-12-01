#ifndef BISHOP_H
#define BISHOP_H

#include <string>
#include "piece.h"

class Bishop : public Piece {
public:
    Bishop(const std::string &colour);
    bool validMove(Move move) override;
};


#endif
