#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece{

private:

public:
    Pawn(const char colour);
    bool validMove() override;
    void checkForCheck() override;

};


#endif

