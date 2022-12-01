#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <string>

class Pawn : public Piece {
public:
    Pawn(const std::string colour);
    bool validMove(Move move) override;
    //void checkForCheck() override;
};


#endif

