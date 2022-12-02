#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <string>

class Pawn : public Piece {
public:
    Pawn(const std::string colour);
    bool validMove(Move move, vector<vector<Piece*>> board) override;
    void updatePossibleMoves(Move move, vector<vector<Piece*>>) override;
    //void checkForCheck() override;
};


#endif

