#include "board.h"
using namespace std;

// Piece** Board::getBoardArr() { 
//     return boardArr;
// } 

Board::Board(){
    board.resize(8, vector<Piece*>(8, nullptr));
}

void Board::setupBoard(){

}

vector<vector<Piece*>> &Board::getBoardArr() {
    return board;
}
