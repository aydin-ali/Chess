#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include <string>

class Rook : public Piece{
    bool hasMoved;
    Position initPosn;
public:
    Rook(const std::string &colour, int row, int col);
    bool validMove(Move move, std::vector<std::vector<Piece*>> board) override;
    void updatePossibleMoves(std::vector<std::vector<Piece*>> board, Board &b) override;
    bool getHasMoved();
};

#endif

