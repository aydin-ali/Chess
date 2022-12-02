#ifndef KING_H
#define KING_H

#include <string>
#include "piece.h"

class King : public Piece {
public:
    King( const std::string &colour );
    bool validMove(Move move, vector<vector<Piece*>> board) override;
    void updatePossibleMoves(Move move, vector<vector<Piece*>>) override;

};


#endif
