#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include <string>

class Knight : public Piece{
public:
    Knight(const std::string &colour, int row, int col);
    bool validMove(Move move, std::vector<std::vector<Piece*>> board) override;
    void updatePossibleMoves(std::vector<std::vector<Piece*>> board, Board &b) override;

};


#endif
