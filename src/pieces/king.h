#ifndef KING_H
#define KING_H

#include <string>
#include "piece.h"

class King : public Piece {
    bool hasMoved;
    Position initPosn;
public:
    King( const std::string &colour, int row, int col);
    bool validMove(Move move, std::vector<std::vector<Piece*>> board) override;
    bool moveNotWithinOtherKing(std::vector<std::vector<Piece*>> board, Position p);
    void updatePossibleMoves(std::vector<std::vector<Piece*>>, Board &b) override;

};


#endif
