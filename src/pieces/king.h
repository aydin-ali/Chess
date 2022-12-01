#ifndef KING_H
#define KING_H

#include <string>
#include "piece.h"

class King : public Piece {
public:
    King( const std::string &colour );
    bool validMove(Move move) override;
};


#endif
