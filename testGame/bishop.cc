#include "bishop.h"
using namespace std;

Bishop::Bishop(const string &colour, int row, int col):
    Piece{colour, 'b', row, col} {}

bool Bishop::validMove(Move move, vector<vector<Piece*>> board) {
    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it) {
        if ((it->getRow() == move.getEndRow()) && (it->getCol() == move.getEndCol())) {
            return true;
        }
    }
    return false;
}

void Bishop::updatePossibleMoves(vector<vector<Piece*>> board, Board &b) {
    int incr;
    Position p{0 ,0};

    possibleMoves.clear();


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






