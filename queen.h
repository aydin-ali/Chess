#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include <string>

class Queen : public Piece{
public:
    Queen(const std::string &colour, int row, int col);
    bool validMove(Move move, std::vector<std::vector<Piece*>> board) override;
    void updatePossibleMoves(std::vector<std::vector<Piece*>>, Board &b) override;

};

#endif






