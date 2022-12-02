#include "queen.h"
using namespace std;

Queen::Queen(const string &colour, int row, int col):
    Piece{colour, 'q', row, col}{}

bool Queen::validMove(Move move, vector<vector<Piece*>> board) {
    updatePossibleMoves(board);
    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it) {
        if ((it->getRow() == move.getEndRow()) && (it->getCol() == move.getEndCol())) {
            return true;
        }
    }
    return false;
}

void Queen::updatePossibleMoves(vector<vector<Piece*>> board) {
    int row;
    int col;
    int incr;
    Position p = {0, 0};

    // Moving the Queen left
    row = posn.getRow();
    col = posn.getCol();
    incr = 1;
    p = {row, col - incr};
    
    while (p.positionWithinBounds()) {
        if(board[p.getRow()][p.getCol()] == nullptr){
            possibleMoves.emplace_back(p);
            ++incr;
            p = {row, col - incr};
        } else if(board[p.getRow()][p.getCol()]->getColour() != colour){
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }

    // Moving the Queen right
    row = posn.getRow();
    col = posn.getCol();
    incr = 1;
    p = {row, col + incr};
    
    while (p.positionWithinBounds()) {
        if(board[p.getRow()][p.getCol()] == nullptr){
            possibleMoves.emplace_back(p);
            ++incr;
            p = {row, col + incr};
        } else if(board[p.getRow()][p.getCol()]->getColour() != colour){
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }

    // Moving the Queen up
    row = posn.getRow();
    col = posn.getCol();
    incr = 1;
    p = {row - incr, col};
    
    while (p.positionWithinBounds()) {
        if(board[p.getRow()][p.getCol()] == nullptr){
            possibleMoves.emplace_back(p);
            ++incr;
            p = {row - incr, col};
        } else if(board[p.getRow()][p.getCol()]->getColour() != colour){
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }

    // Moving the Queen down
    row = posn.getRow();
    col = posn.getCol();
    incr = 1;
    p = {row + incr, col};
    
    while (p.positionWithinBounds()) {
        if(board[p.getRow()][p.getCol()] == nullptr){
            possibleMoves.emplace_back(p);
            ++incr;
            p = {row + incr, col};
        } else if(board[p.getRow()][p.getCol()]->getColour() != colour){
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }

    // Moving Queen Diagonally Up Left
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

    // Moving Queen Diagonally Up Right
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

    // Moving Queen Diagonally Down Right
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

    // Moving Queen Diagonally Down Left
    row = posn.getRow();
    col = posn.getCol();
    incr = 1;
    p = {row + incr, col - incr};

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
