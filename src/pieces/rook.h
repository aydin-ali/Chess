#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include <string>

class Rook : public Piece{
public:
    Rook(const std::string &colour);
    bool validMove(Move move, std::vector<std::vector<Piece*>> board) override;
    void updatePossibleMoves(Move move, std::vector<std::vector<Piece*>>) override;

};

#endif

