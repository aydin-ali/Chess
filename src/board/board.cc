#include "board.h"
using namespace std;

Board::Board(){
    board.resize(8, vector<Piece*>(8, nullptr));
    numWhiteKings = 0;
    numBlackKings = 0;
}

void Board::setupBoardDefault(){
    numWhiteKings = 1;
    numBlackKings = 1;
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

void Board::setupBoardManual(int row, int col, char type, char op){
    if(op == '+'){
        if(board[row][col] != nullptr) pieceArray.pop_back(); // DO I NEED THIS??
        if(type == 'K'){
            pieceArray.emplace_back(make_unique<King>("white"));
            board[row][col] = pieceArray.back().get();
            ++numWhiteKings;
        } else if(type == 'Q'){
            pieceArray.emplace_back(make_unique<Queen>("white"));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'B'){
            pieceArray.emplace_back(make_unique<Bishop>("white"));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'N'){
            pieceArray.emplace_back(make_unique<Knight>("white"));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'R'){
            pieceArray.emplace_back(make_unique<Rook>("white"));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'P'){
            pieceArray.emplace_back(make_unique<Pawn>("white"));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'k'){
            pieceArray.emplace_back(make_unique<King>("black"));
            board[row][col] = pieceArray.back().get();
            ++numBlackKings;
        } else if(type == 'q'){
            pieceArray.emplace_back(make_unique<Queen>("black"));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'b'){
            pieceArray.emplace_back(make_unique<Bishop>("black"));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'n'){
            pieceArray.emplace_back(make_unique<Knight>("black"));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'r'){
            pieceArray.emplace_back(make_unique<Rook>("black"));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'p'){
            pieceArray.emplace_back(make_unique<Pawn>("black"));
            board[row][col] = pieceArray.back().get();
        }
    } else if(op == '-'){
        if(type == 'k') {
            if(board[row][col]->getColour() == "white")--numWhiteKings;
            else{--numBlackKings;}
        };
        board[row][col] = nullptr;
    } else if(op == '='){
        
    }

}

int Board::getNumWhiteKings(){
    return numWhiteKings;
}

int Board::getNumBlackKings(){
    return numBlackKings;
}

vector<vector<Piece*>> &Board::getBoardArr() {
    return board;
}
