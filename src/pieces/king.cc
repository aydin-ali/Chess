#include "king.h"
#include "rook.h"
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

    // Check if can castle
    if(!hasMoved){
        if((colour == "white") && (moveAllowed(b, posn))) {
            // Check castle right
            if ((board[7][5] == nullptr) && (board[7][6] == nullptr)) {
                if (moveAllowed(b, {7, 5}) && moveAllowed(b, {7, 6})) {
                    if (board[7][7] != nullptr) {
                        if (board[7][7]->getType() == 'r') {
                            Rook *tmpRook = static_cast<Rook*>(board[7][7]);
                            if (!tmpRook->getHasMoved()) {
                                p = {7, 6};
                                possibleMoves.emplace_back(p);
                            }
                        }
                    }
                }
            }
            // Check castle left 
            if ((board[7][3] == nullptr) && (board[7][2] == nullptr) && (board[7][1] == nullptr)) {
                if (moveAllowed(b, {7, 3}) && moveAllowed(b, {7, 2})) {
                    if (board[7][0] != nullptr) {
                        if (board[7][0]->getType() == 'r') {
                            Rook *tmpRook = static_cast<Rook*>(board[7][0]);
                            if (!tmpRook->getHasMoved()) {
                                p = {7, 2};
                                possibleMoves.emplace_back(p);
                            }
                        }
                    }
                }
            }
        } else if (moveAllowed(b, posn)) {
            // Check castle right 
            if ((board[0][5] == nullptr) && (board[0][6] == nullptr)) {
                if (moveAllowed(b, {0, 5}) && moveAllowed(b, {0, 6})) {
                    if (board[0][7] != nullptr) {
                        if (board[0][7]->getType() == 'r') {
                            Rook *tmpRook = static_cast<Rook*>(board[0][7]);
                            if (!tmpRook->getHasMoved()) {
                                p = {0, 6};
                                possibleMoves.emplace_back(p);
                            }
                        }
                    }
                }
            }
            // Check castle left 
            if ((board[0][3] == nullptr) && (board[0][2] == nullptr) && (board[0][1] == nullptr)) {
                if (moveAllowed(b, {0, 3}) && moveAllowed(b, {0, 2})) {
                    if (board[0][0] != nullptr) {
                        if (board[0][0]->getType() == 'r') {
                            Rook *tmpRook = static_cast<Rook*>(board[0][0]);
                            if (!tmpRook->getHasMoved()) {
                                p = {0, 2};
                                possibleMoves.emplace_back(p);
                            }
                        }
                    }
                }
            }
        }
    }
}
