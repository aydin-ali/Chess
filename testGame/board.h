#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "piece.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"
#include "subject.h"
#include "move.h"

class Piece;
// don't need class Piece here because it's in game????

class Board {

private:
    std::vector<std::vector<Piece*>> board;
    std::vector<std::unique_ptr<Piece>> pieceArray;

    int numWhiteKings, numBlackKings;
    bool whiteInCheck, blackInCheck, whiteInCheckmate, blackInCheckmate, boardInStalemate;
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
    bool getWhiteInCheck();
    bool getBlackInCheck();
    bool getWhiteInCheckmate();
    bool getBlackInCheckmate();
    bool getBoardInStalemate();
    void updateBoard();
    bool InCheck(const std::string &colour);
    bool MovesLeft(const std::string &colour);

    bool inPositionToPromote(Move move);
    bool canPromote(Move move, std::string colour, char promoteType);
    void actuallyPromote(Move move, std::string colour, char promoteType);
    bool pawnInIllegalRow();
    bool kingBesideKing();
};

#endif

