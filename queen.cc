#include "queen.h"
using namespace std;

Queen::Queen(const string &colour, int row, int col):
    Piece{colour, 'q', row, col}{}

bool Queen::validMove(Move move, vector<vector<Piece*>> board) {
    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it) {
        if ((it->getRow() == move.getEndRow()) && (it->getCol() == move.getEndCol())) {
            return true;
        }
    }
    return false;
}

void Queen::updatePossibleMoves(vector<vector<Piece*>> board, Board &b) {
    int incr;
    Position p = {0, 0};

    possibleMoves.clear();

    // Moving left
    incr = 1;
    p = {posn.getRow(), posn.getCol() - incr};
    
    while(p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
                ++incr;
                p = {posn.getRow(), posn.getCol() - incr};
            } else {
                break;
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
            break;
        } else {
            break;
        }
    }

    // Moving right
    incr = 1;
    p = {posn.getRow(), posn.getCol() + incr};
    
    while(p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
                ++incr;
                p = {posn.getRow(), posn.getCol() + incr};
            } else {
                break;
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
            break;
        } else {
            break;
        }
    }

    // Moving up
    incr = 1;
    p = {posn.getRow() - incr, posn.getCol()};
    
    while(p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
                ++incr;
                p = {posn.getRow() - incr, posn.getCol()};
            } else {
                break;
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
            break;
        } else {
            break;
        }
    }

    // Moving down
    incr = 1;
    p = {posn.getRow() + incr, posn.getCol()};
    
    while(p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
                ++incr;
                p = {posn.getRow() + incr, posn.getCol()};
            } else {
                break;
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
            break;
        } else {
            break;
        }
    }

    // Moving to the top left
    incr = 1;
    p = {posn.getRow() - incr, posn.getCol() - incr};

    while(p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
                ++incr;
                p = {posn.getRow() - incr, posn.getCol() - incr};
            } else {
                break;
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
            break;
        } else {
            break;
        }
    }

    // Moving to the top right
    incr = 1;
    p = {posn.getRow() - incr, posn.getCol() + incr};

    while(p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
                ++incr;
                p = {posn.getRow() - incr, posn.getCol() + incr};
            } else {
                break;
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
            break;
        } else {
            break;
        }
    }

    // Moving to the top bottom right
    incr = 1;
    p = {posn.getRow() + incr, posn.getCol() + incr};

    while(p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
                ++incr;
                p = {posn.getRow() + incr, posn.getCol() + incr};
            } else {
                break;
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
            break;
        } else {
            break;
        }
    }

    // Moving to the bottom left
    incr = 1;
    p = {posn.getRow() + incr, posn.getCol() - incr};

    while(p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
                ++incr;
                p = {posn.getRow() + incr, posn.getCol() - incr};
            } else {
                break;
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p)) {
                possibleMoves.emplace_back(p);
            }
            break;
        } else {
            break;
        }
    }
}







