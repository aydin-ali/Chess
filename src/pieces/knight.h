#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include <string>

class Knight : public Piece{
public:
    Knight(const std::string &colour);
    bool validMove(Move move, vector<vector<Piece*>> board) override;
    void updatePossibleMoves(Move move, vector<vector<Piece*>>) override;

};


#endif
