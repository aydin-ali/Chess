#include "rook.h"
using namespace std;

Rook::Rook(const string &colour, int row, int col):
    Piece{colour, 'r', row, col}{}

bool Rook::validMove(Move move, vector<vector<Piece*>> board) {
    return true;
}

void Rook::updatePossibleMoves(Move move, vector<vector<Piece*>> board) {
    int row;
    int col;
    Position p = {0, 0};

    row = posn.getRow();
    col = posn.getCol();
    // Moving the Rook left
    while(p.validPosn()){
        --col;
        p = {row, col};
        if(board[row][col] == nullptr){
            possibleMoves.emplace_back(p);
        } else if(board[row][col]->getColour() != colour){
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }

    row = posn.getRow();
    col = posn.getCol();
    // Moving the Rook right
    while(p.validPosn()){
        ++col;
        p = {row, col};
        if(board[row][col] == nullptr){
            possibleMoves.emplace_back(p);
        } else if(board[row][col]->getColour() != colour){
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }

    row = posn.getRow();
    col = posn.getCol();
    // Moving the Rook up
    while(p.validPosn()){
        ++row;
        p = {row, col};
        if(board[row][col] == nullptr){
            possibleMoves.emplace_back(p);
        } else if(board[row][col]->getColour() != colour){
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }

    row = posn.getRow();
    col = posn.getCol();
    // Moving the Rook down
    while(p.validPosn()){
        --row;
        p = {row, col};
        if(board[row][col] == nullptr){
            possibleMoves.emplace_back(p);
        } else if(board[row][col]->getColour() != colour){
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }
}
