#include "board.h"
using namespace std;

Board::Board(){
    board.resize(8, vector<Piece*>(8, nullptr));
}

void Board::setupBoardDefault(){
    // Set up White pieces on the Board
    for(int P = 0; P < 8; ++P){
        pieceArray.emplace_back(make_unique<Pawn>("white"));
        board[P][1] = pieceArray.back().get();
    }
    pieceArray.emplace_back(make_unique<Rook>("white"));
    board[7][0] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Knight>("white"));
    board[6][0] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Bishop>("white"));
    board[5][0] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<King>("white"));
    board[4][0] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Queen>("white"));
    board[3][0] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Bishop>("white"));
    board[2][0] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Knight>("white"));
    board[1][0] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Rook>("white"));
    board[0][0] = pieceArray.back().get();

    // Set up Black pieces on the Board
    for(int p = 0; p < 8; ++p){
        pieceArray.emplace_back(make_unique<Pawn>("black"));
        board[p][6] = pieceArray.back().get();
    }
    pieceArray.emplace_back(make_unique<Rook>("black"));
    board[0][7] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Knight>("black"));
    board[1][7] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Bishop>("black"));
    board[2][7] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<King>("black"));
    board[3][7] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Queen>("black"));
    board[4][7] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Bishop>("black"));
    board[5][7] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Knight>("black"));
    board[6][7] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Rook>("black"));
    board[7][7] = pieceArray.back().get();
}

vector<vector<Piece*>> &Board::getBoardArr() {
    return board;
}
