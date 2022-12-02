#include "bishop.h"
using namespace std;

Bishop::Bishop(const string &colour, int row, int col):
    Piece{colour, 'b', row, col} {}

bool Bishop::validMove(Move move, vector<vector<Piece*>> board) {
    return true;
}

void Bishop::updatePossibleMoves(vector<vector<Piece*>> board) {
    int row;
    int col;
    int incr;
    Position p{0 ,0};

    row = posn.getRow();
    col = posn.getCol();
    incr = 1;
    p = {row - incr, col - incr};

    while(p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            possibleMoves.emplace_back(p);
            ++incr;
            p = {row - incr, col - incr};
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }

    row = posn.getRow();
    col = posn.getCol();
    incr = 1;
    p = {row - incr, col - incr};

    while(p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            possibleMoves.emplace_back(p);
            ++incr;
            p = {row - incr, col - incr};
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }

    row = posn.getRow();
    col = posn.getCol();
    incr = 1;
    p = {row - incr, col + incr};

    while(p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            possibleMoves.emplace_back(p);
            ++incr;
            p = {row - incr, col + incr};
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }

    row = posn.getRow();
    col = posn.getCol();
    incr = 1;
    p = {row + incr, col + incr};

    while(p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            possibleMoves.emplace_back(p);
            ++incr;
            p = {row + incr, col + incr};
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }

    row = posn.getRow();
    col = posn.getCol();
    incr = 1;
    p = {row + incr, col + incr};

    while(p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] == nullptr) {
            possibleMoves.emplace_back(p);
            ++incr;
            p = {row + incr, col + incr};
        } else if (board[p.getRow()][p.getCol()]->getColour() != colour) {
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }
    
}

