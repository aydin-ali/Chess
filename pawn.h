#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <string>

class Pawn : public Piece {
    bool hasntMoved;
    bool enpassantAble;
public:
    Pawn(const std::string colour, int row, int col);
    bool validMove(Move move, std::vector<std::vector<Piece*>> board) override;
    void updatePossibleMoves(std::vector<std::vector<Piece*>> board, Board &b) override;
    bool canPromote();
    bool getHasntMoved();
    void setEnpassantAble(bool set);
    bool getEnpassantAble();
};


#endif






