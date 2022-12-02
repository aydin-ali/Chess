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
        pieceArray.emplace_back(make_unique<Pawn>("white", P, 1));
        board[6][P] = pieceArray.back().get();
    }
    pieceArray.emplace_back(make_unique<Rook>("white", 7, 7));
    board[7][7] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Knight>("white", 7, 6));
    board[7][6] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Bishop>("white", 7, 5));
    board[7][5] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<King>("white", 7, 4));
    board[7][4] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Queen>("white", 7, 3));
    board[7][3] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Bishop>("white", 7, 2));
    board[7][2] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Knight>("white", 7, 1));
    board[7][1] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Rook>("white", 7, 0));
    board[7][0] = pieceArray.back().get();

    // Set up Black pieces on the Board
    for(int p = 0; p < 8; ++p){
        pieceArray.emplace_back(make_unique<Pawn>("black", p, 6));
        board[1][p] = pieceArray.back().get();
    }
    pieceArray.emplace_back(make_unique<Rook>("black", 0, 0));
    board[0][0] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Knight>("black", 0, 1));
    board[0][1] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Bishop>("black", 0, 2));
    board[0][2] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<King>("black", 0, 3));
    board[0][3] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Queen>("black", 0, 4));
    board[0][4] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Bishop>("black", 0, 5));
    board[0][5] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Knight>("black", 0, 6));
    board[0][6] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Rook>("black", 0, 7));
    board[0][7] = pieceArray.back().get();
}

void Board::setupBoardManual(int row, int col, char type, char op){
    if(op == '+'){
        if(board[row][col] != nullptr){
            for(auto it = pieceArray.begin(); it != pieceArray.end(); ++it){
                if(board[row][col] == it->get()){
                    pieceArray.erase(it);
                }
                break;
            }
        }
        if(type == 'K'){
            pieceArray.emplace_back(make_unique<King>("white", row , col));
            board[row][col] = pieceArray.back().get();
            ++numWhiteKings;
        } else if(type == 'Q'){
            pieceArray.emplace_back(make_unique<Queen>("white", row , col));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'B'){
            pieceArray.emplace_back(make_unique<Bishop>("white", row , col));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'N'){
            pieceArray.emplace_back(make_unique<Knight>("white", row , col));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'R'){
            pieceArray.emplace_back(make_unique<Rook>("white", row , col));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'P'){
            pieceArray.emplace_back(make_unique<Pawn>("white", row , col));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'k'){
            pieceArray.emplace_back(make_unique<King>("black", row , col));
            board[row][col] = pieceArray.back().get();
            ++numBlackKings;
        } else if(type == 'q'){
            pieceArray.emplace_back(make_unique<Queen>("black", row , col));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'b'){
            pieceArray.emplace_back(make_unique<Bishop>("black", row , col));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'n'){
            pieceArray.emplace_back(make_unique<Knight>("black", row , col));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'r'){
            pieceArray.emplace_back(make_unique<Rook>("black", row , col));
            board[row][col] = pieceArray.back().get();
        } else if(type == 'p'){
            pieceArray.emplace_back(make_unique<Pawn>("black", row , col));
            board[row][col] = pieceArray.back().get();
        }
    } else if(op == '-'){
        if(type == 'k') {
            if(board[row][col]->getColour() == "white")--numWhiteKings;
            else{--numBlackKings;}
        };
        for(auto it = pieceArray.begin(); it != pieceArray.end(); ++it){
            if(board[row][col] == it->get()){
                pieceArray.erase(it);
            }
            board[row][col] = nullptr;
            break;
        }
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

bool Board::moveOnBoard(Move move){

    //invalid cases:
    
    //start spot is the same as the end spot, ex: move b3 b3
    if (move.getStartRow() == move.getEndRow() && move.getStartCol() == move.getEndCol()) return false;
    //starting spot is empty
    if (board[move.getStartRow()][move.getStartCol()] == nullptr) return false;
    //starting spot has the other player's piece at that spot
    if (board[move.getStartRow()][move.getStartCol()]->getColour() != move.getColour()) return false;


    //calls the individual pieces validMove() function to check if the move is allowed for that given piece
    if (!(board[move.getStartRow()][move.getStartCol()]->validMove(move, board))) return false;

    //loop... for checks...




    //actually move the piece
    board[move.getEndRow()][move.getEndCol()] = board[move.getStartRow()][move.getStartCol()];//this has to be move ctor if it's taking a piece
    board[move.getStartRow()][move.getStartCol()] = nullptr;
    
    //two cases:
    if (board[move.getEndRow()][move.getEndCol()] == nullptr) {     //if moving into an empty spot:
        //nothing left to do
    } else {     //if taking the piece:
        //delete the piece from the piece array
    }


    //castling + pawn promotion (later)

    return true;

}


