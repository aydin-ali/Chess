#include "king.h"
using namespace std;

King::King(const string &colour, int row, int col):
    Piece{colour, 'k', row, col}, hasMoved{false}, initPosn{row, col}{}

bool King::validMove(Move move, vector<vector<Piece*>> board) {
    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it) {
        if ((it->getRow() == move.getEndRow()) && (it->getCol() == move.getEndCol())) {
            return true;
        }
    }
    return false;
}

bool King::moveNotWithinOtherKing(vector<vector<Piece*>> board, Position p) {
    Position temp = p;

    // Checking one up from move
    p = {temp.getRow() - 1, temp.getCol()};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'k') {
                    return false;
                }
            }
        }
    }

    // Checking one down from move
    p = {temp.getRow() + 1, temp.getCol()};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'k') {
                    return false;
                }
            }
        }
    }

    // Checking one left from move
    p = {temp.getRow(), temp.getCol() - 1};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'k') {
                    return false;
                }
            }
        }
    }

    // Checking one right from move
    p = {temp.getRow(), temp.getCol() + 1};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'k') {
                    return false;
                }
            }
        }
    }

    // Checking one up left from move
    p = {temp.getRow() - 1, temp.getCol() - 1};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'k') {
                    return false;
                }
            }
        }
    }

    // Checking one up right from move
    p = {temp.getRow() - 1, temp.getCol() + 1};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'k') {
                    return false;
                }
            }
        }
    }

    // Checking one bottom right from move
    p = {temp.getRow() + 1, temp.getCol() + 1};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'k') {
                    return false;
                }
            }
        }
    }

    // Checking one bottom left from move
    p = {temp.getRow() + 1, temp.getCol() - 1};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'k') {
                    return false;
                }
            }
        }
    }

    return true;

}



void King::updatePossibleMoves(vector<vector<Piece*>> board, Board &b) {
    if (posn.getRow() != initPosn.getRow() || posn.getCol() != initPosn.getCol()) {
        hasMoved = true; 
    }

    Position p = {0, 0};

    possibleMoves.clear();

    // Moving one up
    p = {posn.getRow() - 1, posn.getCol()};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    // Moving one down
    p = {posn.getRow() + 1, posn.getCol()};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    // Moving one left
    p = {posn.getRow(), posn.getCol() - 1};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    // Moving one right
    p = {posn.getRow(), posn.getCol() + 1};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    // Moving one up left
    p = {posn.getRow() - 1, posn.getCol() - 1};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    // Moving one up right
    p = {posn.getRow() - 1, posn.getCol() + 1};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    // Moving one bottom right
    p = {posn.getRow() + 1, posn.getCol() + 1};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

    // Moving one bottom left
    p = {posn.getRow() + 1, posn.getCol() - 1};

    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            if (moveAllowed(b, p) && moveNotWithinOtherKing(board, p)) {
                possibleMoves.emplace_back(p);
            }
        }
    }

}
