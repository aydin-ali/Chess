#ifndef BISHOP_H
#define BISHOP_H

#include <string>
#include "piece.h"

class Bishop : public Piece {
public:
    Bishop(const std::string &colour, int row, int col);
    bool validMove(Move move, std::vector<std::vector<Piece*>> board) override;
    void updatePossibleMoves(std::vector<std::vector<Piece*>> board, Board &b) override;

};


#endif






