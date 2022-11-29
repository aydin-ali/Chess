#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "../pieces/piece.h"
#include "../pieces/bishop.h"
#include "../pieces/king.h"
#include "../pieces/knight.h"
#include "../pieces/pawn.h"
#include "../pieces/queen.h"
#include "../pieces/rook.h"
#include "../observer/subject.h"

class Piece;
// don't need class Piece here because it's in game????

class Board {

private:
    std::vector<std::vector<Piece*>> board;
    std::vector<std::unique_ptr<Piece>> pieceArray;
    std::map<std::string, Piece*> pieceMap;

public:
    Board();
    void setupBoard();
    void moveOnBoard();
    std::vector<std::vector<Piece*>> &getBoardArr();
};

#endif

