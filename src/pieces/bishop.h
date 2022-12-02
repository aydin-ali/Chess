#ifndef BISHOP_H
#define BISHOP_H

#include <string>
#include "piece.h"

class Bishop : public Piece {
public:
    Bishop(const std::string &colour);
    bool validMove(Move move, vector<vector<Piece*>> board) override;
    void updatePossibleMoves(Move move, vector<vector<Piece*>>) override;

};


#endif
