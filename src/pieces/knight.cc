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

void Knight::updatePossibleMoves(vector<vector<Piece*>> board, Board &b) {
    int row;
    int col;
    Position p = {0, 0};

    possibleMoves.clear();

    p = {posn.getRow() - 2, posn.getCol() - 1};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    p = {posn.getRow() - 1, posn.getCol() - 2};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    p = {posn.getRow() - 2, posn.getCol() + 1};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    p = {posn.getRow() - 1, posn.getCol() + 2};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    p = {posn.getRow() + 2, posn.getCol() - 1};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    p = {posn.getRow() + 1, posn.getCol() - 2};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    p = {posn.getRow() + 2, posn.getCol() + 1};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    p = {posn.getRow() + 1, posn.getCol() + 2};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }
}
