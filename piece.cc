#include "piece.h"
#include "board.h"
using namespace std;

class Move;

Piece::Piece(const string &colour, const char &type, int row, int col):
    colour{colour}, type{type}, posn{row, col}, moved{false} {}

Piece::~Piece() {}

bool Piece::validMove(Move move, vector<vector<Piece*>> board){
    return true;
}

vector<Position> Piece::getPossibleMoves() {
    return possibleMoves;
}

string Piece::getColour(){
    return colour;
}

char Piece::getType(){
    return type;
}

Position Piece::getPosn() {
    return posn;
}

bool Piece::isMoved(){
    return moved;
}

bool Piece::moveAllowed(Board &b, Position p) {
    bool ans;
    Piece *tempPiece = nullptr;
    Position tempPosn = posn;

    swap(tempPiece, b.getBoardArr()[posn.getRow()][posn.getCol()]);
    swap(tempPiece, b.getBoardArr()[p.getRow()][p.getCol()]);
    
    posn = p;
    ans = !b.InCheck(colour);
    posn = tempPosn;

    swap(tempPiece, b.getBoardArr()[p.getRow()][p.getCol()]);
    swap(tempPiece, b.getBoardArr()[posn.getRow()][posn.getCol()]);
    
    return ans;
}

bool Piece::checkingMove(Board &b, Position p) {
    bool ans;
    Piece *tempPiece = nullptr;
    Position tempPosn = posn;

    swap(tempPiece, b.getBoardArr()[posn.getRow()][posn.getCol()]);
    swap(tempPiece, b.getBoardArr()[p.getRow()][p.getCol()]);
    
    posn = p;
    if (colour == "white") {
         ans = b.InCheck("black");
    } else {
        ans = b.InCheck("white");
    }
   
    posn = tempPosn;

    swap(tempPiece, b.getBoardArr()[p.getRow()][p.getCol()]);
    swap(tempPiece, b.getBoardArr()[posn.getRow()][posn.getCol()]);
    
    return ans;
}

bool Piece::inPossibleMoves(Position p) {
    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it) {
        if ((*it) == p) return true;
    }
    return false;
}

int Piece::numPossibleMoves() {
    return possibleMoves.size();
}

void Piece::updatePosn(int row, int col) {
    posn = {row, col};
}





