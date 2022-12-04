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

#include "../tools/move.h"

class Piece;
// don't need class Piece here because it's in game????

class Board {

private:
    std::vector<std::vector<Piece*>> board;
    std::vector<std::unique_ptr<Piece>> pieceArray;

    int numWhiteKings, numBlackKings;
    bool whiteInCheck, blackInCheck;
    //std::map<std::string, Piece*> pieceMap;

public:
    Board();
    void setupBoardDefault();
    void setupBoardManual(int row, int col, char piece, char op);
    bool validMoveOnBoard(Move move);
    void moveOnBoard(Move move);
    std::vector<std::vector<Piece*>> &getBoardArr();
    int getNumWhiteKings();
    int getNumBlackKings();
    void updateBoard();
    bool checkForCheck(const std::string &colour);

    bool inPositionToPromote(Move move);
    bool canPromote(Move move, std::string colour, char promoteType);
    void actuallyPromote(Move move, std::string colour, char promoteType);
    bool pawnInIllegalRow();
};

#endif