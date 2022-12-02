#include "knight.h"
using namespace std;

Knight::Knight(const string &colour, int row, int col):
    Piece{colour, 'n', row, col} {}

bool Knight::validMove(Move move, vector<vector<Piece*>> board) {
    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it) {
        if ((it->getRow() == move.getEndRow()) && (it->getCol() == move.getEndCol())) {
            return true;
        }
    }
    return false;
}


void Knight::updatePossibleMoves(vector<vector<Piece*>> board) {
    int row;
    int col;
    Position p = {0, 0};

    row = posn.getRow() - 2;
    col = posn.getCol() - 1;
    p = {row, col};

    if (p.validPosn()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            possibleMoves.emplace_back(p);
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            possibleMoves.emplace_back(p);
        }
    }

    row = posn.getRow() - 1;
    col = posn.getCol() - 2;
    p = {row, col};

    if (p.validPosn()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            possibleMoves.emplace_back(p);
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            possibleMoves.emplace_back(p);
        }
    }

    row = posn.getRow() - 2;
    col = posn.getCol() + 1;
    p = {row, col};

    if (p.validPosn()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            possibleMoves.emplace_back(p);
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            possibleMoves.emplace_back(p);
        }
    }

    row = posn.getRow() - 1;
    col = posn.getCol() + 2;
    p = {row, col};

    if (p.validPosn()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            possibleMoves.emplace_back(p);
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            possibleMoves.emplace_back(p);
        }
    }

    row = posn.getRow() + 2;
    col = posn.getCol() - 1;
    p = {row, col};

    if (p.validPosn()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            possibleMoves.emplace_back(p);
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            possibleMoves.emplace_back(p);
        }
    }

    row = posn.getRow() + 1;
    col = posn.getCol() - 2;
    p = {row, col};

    if (p.validPosn()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            possibleMoves.emplace_back(p);
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            possibleMoves.emplace_back(p);
        }
    }

    row = posn.getRow() + 2;
    col = posn.getCol() + 1;
    p = {row, col};

    if (p.validPosn()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            possibleMoves.emplace_back(p);
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            possibleMoves.emplace_back(p);
        }
    }

    row = posn.getRow() + 1;
    col = posn.getCol() + 2;
    p = {row, col};

    if (p.validPosn()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            possibleMoves.emplace_back(p);
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            possibleMoves.emplace_back(p);
        }
    }
}
