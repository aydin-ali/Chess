#include "board.h"
#include <iostream>
using namespace std;

// Board Constructor
Board::Board(){
    board.resize(8, vector<Piece*>(8, nullptr));
    numWhiteKings = 0;
    numBlackKings = 0;
    whiteInCheck = false;
    blackInCheck = false;
    whiteInCheckmate = false;
    blackInCheckmate = false;
    boardInStalemate = false;
}

// Set up the board with a game of classical chess (starting positions)
void Board::setupBoardDefault(){
    numWhiteKings = 1;
    numBlackKings = 1;
    // Set up White pieces on the Board
    for(int P = 0; P < 8; ++P){ 
        pieceArray.emplace_back(make_unique<Pawn>("white", 6, P));
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
        pieceArray.emplace_back(make_unique<Pawn>("black", 1, p));
        board[1][p] = pieceArray.back().get();
    }
    pieceArray.emplace_back(make_unique<Rook>("black", 0, 0));
    board[0][0] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Knight>("black", 0, 1));
    board[0][1] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Bishop>("black", 0, 2));
    board[0][2] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Queen>("black", 0, 3));
    board[0][3] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<King>("black", 0, 4));
    board[0][4] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Bishop>("black", 0, 5));
    board[0][5] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Knight>("black", 0, 6));
    board[0][6] = pieceArray.back().get();
    pieceArray.emplace_back(make_unique<Rook>("black", 0, 7));
    board[0][7] = pieceArray.back().get();
}

// Set up pieces on board one by one through user inputted values
void Board::setupBoardManual(int row, int col, char type, char op){
    // Add a piece to the board
    if(op == '+'){
        if(board[row][col] != nullptr){
            // Lower king counters to check number of kings on board later
            if (board[row][col]->getType() == 'k') {
                if (board[row][col]->getColour() == "white") {
                    --numWhiteKings;
                } else {
                    --numBlackKings;
                }
            }
            for(auto it = pieceArray.begin(); it != pieceArray.end(); ++it){
                if(board[row][col] == it->get()){
                    pieceArray.erase(it);
                }
                break;
            }
        }
        // Add piece based on what was inputted
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
    } 
    // Remove piece in setup mode
    else if(op == '-'){
        // 
        if(board[row][col]->getType() == 'k') {
            if(board[row][col]->getColour() == "white")--numWhiteKings;
            else{--numBlackKings;}
        };
        for(auto it = pieceArray.begin(); it != pieceArray.end(); ++it){
            if(board[row][col] == it->get()){
                pieceArray.erase(it);
                board[row][col] = nullptr;
                break;
            }
        }
    }
    // updateBoard();
}

bool Board::pawnInIllegalRow(){
    for(int col = 0; col < 8; ++col){
        if(board[0][col] == nullptr){} 
        else if(board[0][col]->getType() == 'p'){
            return true;
        }
        if(board[7][col] == nullptr){} 
        else if(board[7][col]->getType() == 'p'){
            return true;
        }
    }
    return false;
}

bool Board::kingBesideKing(){
    for(size_t p = 0; p < pieceArray.size(); ++p){
        if(pieceArray[p]->getType() == 'k'){
            if(pieceArray[p]->getColour() == "white"){
                // left 
                if(pieceArray[p]->getPosn().getCol() != 0 && board[pieceArray[p]->getPosn().getRow()][pieceArray[p]->getPosn().getCol() - 1] != nullptr && board[pieceArray[p]->getPosn().getRow()][pieceArray[p]->getPosn().getCol() - 1]->getType() == 'k' && board[pieceArray[p]->getPosn().getRow()][pieceArray[p]->getPosn().getCol() - 1]->getColour() == "black"){
                    return true;
                }
                // right
                if(pieceArray[p]->getPosn().getCol() != 7 && board[pieceArray[p]->getPosn().getRow()][pieceArray[p]->getPosn().getCol() + 1] != nullptr && board[pieceArray[p]->getPosn().getRow()][pieceArray[p]->getPosn().getCol() + 1]->getType() == 'k' && board[pieceArray[p]->getPosn().getRow()][pieceArray[p]->getPosn().getCol() + 1]->getColour() == "black"){
                    return true;
                }
                // up
                if(pieceArray[p]->getPosn().getRow() != 0 && board[pieceArray[p]->getPosn().getRow() - 1][pieceArray[p]->getPosn().getCol()] != nullptr && board[pieceArray[p]->getPosn().getRow() - 1][pieceArray[p]->getPosn().getCol()]->getType() == 'k' && board[pieceArray[p]->getPosn().getRow() - 1][pieceArray[p]->getPosn().getCol()]->getColour() == "black"){
                    return true;
                }
                // down
                if(pieceArray[p]->getPosn().getRow() != 7 && board[pieceArray[p]->getPosn().getRow() + 1][pieceArray[p]->getPosn().getCol()] != nullptr && board[pieceArray[p]->getPosn().getRow() + 1][pieceArray[p]->getPosn().getCol()]->getType() == 'k' && board[pieceArray[p]->getPosn().getRow() + 1][pieceArray[p]->getPosn().getCol()]->getColour() == "black"){
                    return true;
                }
                // down left
                if(pieceArray[p]->getPosn().getCol() != 0 && pieceArray[p]->getPosn().getRow() != 7 && board[pieceArray[p]->getPosn().getRow() + 1][pieceArray[p]->getPosn().getCol() - 1] != nullptr && board[pieceArray[p]->getPosn().getRow() + 1][pieceArray[p]->getPosn().getCol() - 1]->getType() == 'k' && board[pieceArray[p]->getPosn().getRow() + 1][pieceArray[p]->getPosn().getCol() - 1]->getColour() == "black"){
                    return true;
                }
                // down right
                if(pieceArray[p]->getPosn().getRow() != 7 && pieceArray[p]->getPosn().getCol() != 7 && board[pieceArray[p]->getPosn().getRow() + 1][pieceArray[p]->getPosn().getCol() + 1] != nullptr && board[pieceArray[p]->getPosn().getRow() + 1][pieceArray[p]->getPosn().getCol() + 1]->getType() == 'k' && board[pieceArray[p]->getPosn().getRow() + 1][pieceArray[p]->getPosn().getCol() + 1]->getColour() == "black"){
                    return true;
                }
                // up right
                if(pieceArray[p]->getPosn().getRow() != 0 && pieceArray[p]->getPosn().getCol() != 7 && board[pieceArray[p]->getPosn().getRow() - 1][pieceArray[p]->getPosn().getCol() + 1] != nullptr && board[pieceArray[p]->getPosn().getRow() - 1][pieceArray[p]->getPosn().getCol() + 1]->getType() == 'k' && board[pieceArray[p]->getPosn().getRow() - 1][pieceArray[p]->getPosn().getCol() + 1]->getColour() == "black"){
                    return true;
                }
                // up left
                if(pieceArray[p]->getPosn().getRow() != 0 && pieceArray[p]->getPosn().getCol() != 0 && board[pieceArray[p]->getPosn().getRow() - 1][pieceArray[p]->getPosn().getCol() - 1] != nullptr && board[pieceArray[p]->getPosn().getRow() - 1][pieceArray[p]->getPosn().getCol() - 1]->getType() == 'k' && board[pieceArray[p]->getPosn().getRow() - 1][pieceArray[p]->getPosn().getCol() - 1]->getColour() == "black"){
                    return true;
                }
            }
        }
    }
    return false;
}

int Board::getNumWhiteKings(){
    return numWhiteKings;
}

int Board::getNumBlackKings(){
    return numBlackKings;
}

bool Board::getWhiteInCheck() {
    return whiteInCheck;
}

bool Board::getBlackInCheck() {
    return blackInCheck;
}

bool Board::getWhiteInCheckmate() {
    return whiteInCheckmate;
}
bool Board::getBlackInCheckmate() {
    return blackInCheckmate;
}

bool Board::getBoardInStalemate() {
    return boardInStalemate;
}

vector<vector<Piece*>> &Board::getBoardArr() {
    return board;
}

bool Board::inPositionToPromote(Move move){
    if((board[move.getStartRow()][move.getStartCol()]->getColour() == "white") && (move.getEndRow() == 0)) return true;
    else if((board[move.getStartRow()][move.getStartCol()]->getColour() == "black") && (move.getEndRow() == 7)) return true;
    else return false;
}

bool Board::canPromote(Move move, string colour, char promoteType){
    // If it is a White pawn
     if(board[move.getStartRow()][move.getStartCol()]->getColour() == "white"){
        if(move.getEndRow() == 0){
            if(promoteType == 'Q' || promoteType == 'R' || promoteType == 'B' || promoteType == 'N'){
                return true;
            } 
            return false;
        } else {
            return false;
        }
    } else {
        if(move.getEndRow() == 7){
            if(promoteType == 'q' || promoteType == 'r' || promoteType == 'b' || promoteType == 'n'){
                return true;
            }
            return false;
        } else {
            return false;
        }
    } 
}

void Board::actuallyPromote(Move move, string colour, char promoteType){
    if(board[move.getEndRow()][move.getEndCol()]->getColour() == "white"){
        // Remove existing pawn from pieceArray
        for(auto it = pieceArray.begin(); it != pieceArray.end(); ++it){
            if(board[move.getEndRow()][move.getEndCol()] == it->get()){
                pieceArray.erase(it);
            }
        break;
        }
        if(promoteType == 'Q') {
            pieceArray.emplace_back(make_unique<Queen>("white", move.getEndRow(), move.getEndCol()));
            board[move.getEndRow()][move.getEndCol()] = pieceArray.back().get();
        } else if(promoteType == 'R') {
            pieceArray.emplace_back(make_unique<Rook>("white", move.getEndRow(), move.getEndCol()));
            board[move.getEndRow()][move.getEndCol()] = pieceArray.back().get();
        } else if(promoteType == 'B') {
            pieceArray.emplace_back(make_unique<Bishop>("white", move.getEndRow(), move.getEndCol()));
            board[move.getEndRow()][move.getEndCol()] = pieceArray.back().get();
        } else if(promoteType == 'N') {
            pieceArray.emplace_back(make_unique<Knight>("white", move.getEndRow(), move.getEndCol()));
            board[move.getEndRow()][move.getEndCol()] = pieceArray.back().get();
        }
    } else {
        // Remove existing pawn from pieceArray
        for(auto it = pieceArray.begin(); it != pieceArray.end(); ++it){
            if(board[move.getEndRow()][move.getEndCol()] == it->get()){
                pieceArray.erase(it);
            }
        break;
        }
        if(promoteType == 'q') {
            pieceArray.emplace_back(make_unique<Queen>("black", move.getEndRow(), move.getEndCol()));
            board[move.getEndRow()][move.getEndCol()] = pieceArray.back().get();
        } else if(promoteType == 'r') {
            pieceArray.emplace_back(make_unique<Rook>("black", move.getEndRow(), move.getEndCol()));
            board[move.getEndRow()][move.getEndCol()] = pieceArray.back().get();
        } else if(promoteType == 'b') {
            pieceArray.emplace_back(make_unique<Bishop>("black", move.getEndRow(), move.getEndCol()));
            board[move.getEndRow()][move.getEndCol()] = pieceArray.back().get();
        } else if(promoteType == 'n') {
            pieceArray.emplace_back(make_unique<Knight>("black", move.getEndRow(), move.getEndCol()));
            board[move.getEndRow()][move.getEndCol()] = pieceArray.back().get();
        }
    }
}

bool Board::validMoveOnBoard(Move move){
    //invalid cases:
    
    //start spot is the same as the end spot, ex: move b3 b3
    if (move.getStartRow() == move.getEndRow() && move.getStartCol() == move.getEndCol()) return false;
    //starting spot is empty
    if (board[move.getStartRow()][move.getStartCol()] == nullptr) return false;
    //starting spot has the other player's piece at that spot
    if (board[move.getStartRow()][move.getStartCol()]->getColour() != move.getColour()) return false;


    //calls the individual pieces validMove() function to check if the move is allowed for that given piece
    if (!(board[move.getStartRow()][move.getStartCol()]->validMove(move, board))) return false;
    return true;
}

void Board::moveOnBoard(Move move){
    //loop... for checks...

        //two cases:
    if (board[move.getEndRow()][move.getEndCol()] == nullptr) {     //if moving into an empty spot:
        //nothing left to do
     } else {     //if taking the piece:
        //delete the piece from the piece array NEED TO TEST THIS
        for(auto it = pieceArray.begin(); it != pieceArray.end(); ++it){
            if(it->get() == board[move.getEndRow()][move.getEndCol()]){
                pieceArray.erase(it);
                break;
            }
        }
    }


    //actually move the piece
    board[move.getEndRow()][move.getEndCol()] = board[move.getStartRow()][move.getStartCol()];//this has to be move ctor if it's taking a piece
    board[move.getEndRow()][move.getEndCol()]->updatePosn(move.getEndRow(), move.getEndCol());

    board[move.getStartRow()][move.getStartCol()] = nullptr;

        // ----- Check if player made an enpassant move -----
    // Check if piece moved is a pawn
    if(board[move.getEndRow()][move.getEndCol()]->getType() == 'p'){
        // Check if pawn is white
        if(board[move.getEndRow()][move.getEndCol()]->getColour() == "white"){
            // Check if pawn moved diagonally up right into open space
            if(move.getEndRow() == move.getStartRow() - 1 && move.getEndCol() == move.getStartCol() + 1){
                // Check if nothing behind
                if(board[move.getEndRow() + 1][move.getEndCol()] == nullptr){

                }
                // Check if there is an enemy pawn behind it once player's pawn moves
                else if(board[move.getEndRow() + 1][move.getEndCol()]->getType() == 'p' && board[move.getEndRow() + 1][move.getEndCol()]->getColour() != board[move.getEndRow()][move.getEndCol()]->getColour()){
                    for(auto it = pieceArray.begin(); it != pieceArray.end(); ++it){
                        if(it->get() == board[move.getEndRow() + 1][move.getEndCol()]){
                            pieceArray.erase(it);
                            break;
                        }
                    }
                    board[move.getEndRow() + 1][move.getEndCol()] = nullptr;
                }
            }
            // Check if pawn moved diagonally up left into open space  
            else if(move.getEndRow() == move.getStartRow() - 1 && move.getEndCol() == move.getStartCol() - 1){
                // Check if nothing behind
                if(board[move.getEndRow() + 1][move.getEndCol()] == nullptr){

                }
                // Check if there is an enemy pawn behind it once player's pawn moves
                else if(board[move.getEndRow() + 1][move.getEndCol()]->getType() == 'p' && board[move.getEndRow() + 1][move.getEndCol()]->getColour() != board[move.getEndRow()][move.getEndCol()]->getColour()){
                    for(auto it = pieceArray.begin(); it != pieceArray.end(); ++it){
                        if(it->get() == board[move.getEndRow() + 1][move.getEndCol()]){
                            pieceArray.erase(it);
                            break;
                        }
                    }
                    board[move.getEndRow() + 1][move.getEndCol()] = nullptr;
                }
            } 
        } else if(board[move.getEndRow()][move.getEndCol()]->getColour() == "black"){
            // Check if pawn moved diagonally down right into open space
            if(move.getEndRow() == move.getStartRow() + 1 && move.getEndCol() == move.getStartCol() + 1){
                // Check if nothing behind
                if(board[move.getEndRow() - 1][move.getEndCol()] == nullptr){

                }
                // Check if there is an enemy pawn behind it once player's pawn moves
                else if(board[move.getEndRow() - 1][move.getEndCol()]->getType() == 'p' && board[move.getEndRow() - 1][move.getEndCol()]->getColour() != board[move.getEndRow()][move.getEndCol()]->getColour()){
                    for(auto it = pieceArray.begin(); it != pieceArray.end(); ++it){
                        if(it->get() == board[move.getEndRow() + 1][move.getEndCol()]){
                            pieceArray.erase(it);
                            break;
                        }
                    }
                    board[move.getEndRow() - 1][move.getEndCol()] = nullptr;
                }
            }
            // Check if pawn moved diagonally down left into open space  
            else if(move.getEndRow() == move.getStartRow() + 1 && move.getEndCol() == move.getStartCol() - 1){
                // Check if nothing behind
                if(board[move.getEndRow() - 1][move.getEndCol()] == nullptr){

                }
                // Check if there is an enemy pawn behind it once player's pawn moves
                else if(board[move.getEndRow() - 1][move.getEndCol()]->getType() == 'p' && board[move.getEndRow() - 1][move.getEndCol()]->getColour() != board[move.getEndRow()][move.getEndCol()]->getColour()){
                    for(auto it = pieceArray.begin(); it != pieceArray.end(); ++it){
                        if(it->get() == board[move.getEndRow() - 1][move.getEndCol()]){
                            pieceArray.erase(it);
                            break;
                        }
                    }
                    board[move.getEndRow() - 1][move.getEndCol()] = nullptr;
                }
            }
        }
    }

    // ------ Check if a pawn moved such that they can be taken by enpassant by the opposing player ------
    // Check if piece moved if a pawn
    if(board[move.getEndRow()][move.getEndCol()]->getType() == 'p'){
        Pawn *tmpPawn = dynamic_cast<Pawn*>(board[move.getEndRow()][move.getEndCol()]);
        // Check if pawn white, if on first move, and if it double jumped
        if(board[move.getEndRow()][move.getEndCol()]->getColour() == "white" && tmpPawn->getHasntMoved() && move.getEndRow() == 4){
            // Check if there is nothing to the left
            if(board[move.getEndRow()][move.getEndCol() - 1] == nullptr || move.getEndCol() == 0){

            }
            // Check if there is an enemy pawn to the left 
            else if(board[move.getEndRow()][move.getEndCol() - 1]->getType() == 'p' && board[move.getEndRow()][move.getEndCol() - 1]->getColour() != board[move.getEndRow()][move.getEndCol()]->getColour()){
                tmpPawn->setEnpassantAble(true);
            }
            // Check if there is nothing to the right
            if(board[move.getEndRow()][move.getEndCol() + 1] == nullptr || move.getEndCol() == 7){

            }
            // Check if there is an enemy pawn to the right
            else if(board[move.getEndRow()][move.getEndCol() + 1]->getType() == 'p' && board[move.getEndRow()][move.getEndCol() + 1]->getColour() != board[move.getEndRow()][move.getEndCol()]->getColour()){
                tmpPawn->setEnpassantAble(true);
            }
        // Check if pawn black, if on first move, and if it double jumped
        } else if(board[move.getEndRow()][move.getEndCol()]->getColour() == "black" && tmpPawn->getHasntMoved() && move.getEndRow() == 3){
            // Check if there is nothing to the left
            if(board[move.getEndRow()][move.getEndCol() - 1] == nullptr || move.getEndCol() == 0){

            }
            // Check if there is an enemy pawn to the left
            else if(board[move.getEndRow()][move.getEndCol() - 1]->getType() == 'p' && board[move.getEndRow()][move.getEndCol() - 1]->getColour() != board[move.getEndRow()][move.getEndCol()]->getColour()){
                tmpPawn->setEnpassantAble(true);
            } 
            // Check if there is nothing to the right
            if(board[move.getEndRow()][move.getEndCol() + 1] == nullptr || move.getEndCol() == 7){

            }
            // Check if there is an enemy pawn to the right
            else if(board[move.getEndRow()][move.getEndCol() + 1]->getType() == 'p' && board[move.getEndRow()][move.getEndCol() + 1]->getColour() != board[move.getEndRow()][move.getEndCol()]->getColour()){
                tmpPawn->setEnpassantAble(true);
            }
        }
    }

    // Check if King castled
    if(board[move.getEndRow()][move.getEndCol()]->getType() == 'k'){
        // Check if King is white
        if(board[move.getEndRow()][move.getEndCol()]->getColour() == "white"){
            // Check if King moved two moves from starting position to the right
            if(move.getStartRow() == 7 && move.getStartCol() == 4 && move.getEndRow() == 7 && move.getEndCol() == 6){
                board[7][5] = board[7][7];
                board[7][5]->updatePosn(7, 5);
                board[7][7] = nullptr;
            }
            // Check if King moved two moves from starting position to the left
            if(move.getStartRow() == 7 && move.getStartCol() == 4 && move.getEndRow() == 7 && move.getEndCol() == 2){
                board[7][3] = board[7][0];
                board[7][3]->updatePosn(7, 3);
                board[7][0] = nullptr;
            }
        }
        // Check if King is black
        else {
            // Check if King moved two moves from starting position to the right
            if(move.getStartRow() == 0 && move.getStartCol() == 4 && move.getEndRow() == 0 && move.getEndCol() == 6){
                board[0][5] = board[0][7];
                board[0][5]->updatePosn(0, 5);
                board[0][7] = nullptr;
            }
            // Check if King moved two moves from starting position to the left
            if(move.getStartRow() == 0 && move.getStartCol() == 4 && move.getEndRow() == 0 && move.getEndCol() == 2){
                board[0][3] = board[0][0];
                board[0][3]->updatePosn(0, 3);
                board[0][0] = nullptr;
            }
        }
    }
    
    // updateBoard();
    
    //castling + pawn promotion (later)
}

void Board::updateBoard() {
    for (auto it = pieceArray.begin(); it != pieceArray.end(); ++it) {
        (*it)->updatePossibleMoves(board, *this);
    }

    //change to checking for other team's check once piece's possible moves is properly updated
    // cout << "Here 1" << endl;
    whiteInCheck = InCheck("white");
    blackInCheck = InCheck("black");
    whiteInCheckmate = InCheck("white") && MovesLeft("white");
    blackInCheckmate = InCheck("black") && MovesLeft("black");
    boardInStalemate = !InCheck("white") && !InCheck("black") && (MovesLeft("white") || MovesLeft("black"));

    if (!boardInStalemate) {
        if (pieceArray.size() == 2) {
            boardInStalemate = true;
        }
    }
}

bool Board::InCheck(const string &colour) {
    Position kingPosn{0, 0};
    int incr;
    Position p = {0, 0};

    // Finding the position of colour's king
    for (auto it = pieceArray.begin(); it != pieceArray.end(); ++it) {
        if (((*it)->getType() == 'k') && ((*it)->getColour() == colour)) {
            kingPosn = {(*it)->getPosn()};
            break;
        }
    } 

    // checking if King is in check by a pawn
    if (colour == "white") {
        p = {kingPosn.getRow() - 1, kingPosn.getCol() - 1};
        if (p.positionWithinBounds()) {
            if (board[p.getRow()][p.getCol()] != nullptr) {
                if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                    if (board[p.getRow()][p.getCol()]->getType() == 'p') {
                        return true;
                    }
                }
            }
        }
        p = {kingPosn.getRow() - 1, kingPosn.getCol() + 1};
        if (p.positionWithinBounds()) {
            if (board[p.getRow()][p.getCol()] != nullptr) {
                if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                    if (board[p.getRow()][p.getCol()]->getType() == 'p') {
                        return true;
                    }
                }
            }
        }
    } else {
        p = {kingPosn.getRow() + 1, kingPosn.getCol() - 1};
        if (p.positionWithinBounds()) {
            if (board[p.getRow()][p.getCol()] != nullptr) {
                if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                    if (board[p.getRow()][p.getCol()]->getType() == 'p') {
                        return true;
                    }
                }
            }
        }   
        p = {kingPosn.getRow() + 1, kingPosn.getCol() + 1};
        if (p.positionWithinBounds()) {
            if (board[p.getRow()][p.getCol()] != nullptr) {
                if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                    if (board[p.getRow()][p.getCol()]->getType() == 'p') {
                        return true;
                    }
                }
            }
        }
    }

    // checking if King is in check from a knight
    p = {kingPosn.getRow() - 2, kingPosn.getCol() - 1};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'n') {
                    return true;
                }
            }
        }
    }

    p = {kingPosn.getRow() - 1, kingPosn.getCol() - 2};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'n') {
                    return true;
                }
            }
        }
    }

    p = {kingPosn.getRow() - 2, kingPosn.getCol() + 1};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'n') {
                    return true;
                }
            }
        }
    }

    p = {kingPosn.getRow() - 1, kingPosn.getCol() + 2};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'n') {
                    return true;
                }
            }
        }
    }

    p = {kingPosn.getRow() + 2, kingPosn.getCol() - 1};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'n') {
                    return true;
                }
            }
        }
    }

    p = {kingPosn.getRow() + 1, kingPosn.getCol() - 2};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'n') {
                    return true;
                }
            }
        }
    }

    p = {kingPosn.getRow() + 2, kingPosn.getCol() + 1};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'n') {
                    return true;
                }
            }
        }
    }

    p = {kingPosn.getRow() + 1, kingPosn.getCol() + 2};
    if (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if (board[p.getRow()][p.getCol()]->getType() == 'n') {
                    return true;
                }
            }
        }
    }

    // checking if King is in check from the left
    incr = 1;
    p = {kingPosn.getRow(), kingPosn.getCol() - incr};

    while (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if ((board[p.getRow()][p.getCol()]->getType() == 'q') || (board[p.getRow()][p.getCol()]->getType() == 'r')) {
                    return true;
                }
            }
            break;
        }
        ++incr;
        p = {kingPosn.getRow(), kingPosn.getCol() - incr};
    }

    // checking if King is in check from the right
    incr = 1;
    p = {kingPosn.getRow(), kingPosn.getCol() + incr};

    while (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if ((board[p.getRow()][p.getCol()]->getType() == 'q') || (board[p.getRow()][p.getCol()]->getType() == 'r')) {
                    return true;
                }
            }
            break;
        }
        ++incr;
        p = {kingPosn.getRow(), kingPosn.getCol() + incr};
    }

    // checking if King is in check from above
    incr = 1;
    p = {kingPosn.getRow() - incr, kingPosn.getCol()};

    while (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if ((board[p.getRow()][p.getCol()]->getType() == 'q') || (board[p.getRow()][p.getCol()]->getType() == 'r')) {
                    return true;
                }
            }
            break;
        }
        ++incr;
        p = {kingPosn.getRow() - incr, kingPosn.getCol()};
    }

    // checking if King is in check from below
    incr = 1;
    p = {kingPosn.getRow() + incr, kingPosn.getCol()};

    while (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if ((board[p.getRow()][p.getCol()]->getType() == 'q') || (board[p.getRow()][p.getCol()]->getType() == 'r')) {
                    return true;
                }
            }
            break;
        }
        ++incr;
        p = {kingPosn.getRow() + incr, kingPosn.getCol()};
    }

    // checking if King is in check from the bottom right
    incr = 1;
    p = {kingPosn.getRow() + incr, kingPosn.getCol() + incr};

    while (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if ((board[p.getRow()][p.getCol()]->getType() == 'q') || (board[p.getRow()][p.getCol()]->getType() == 'b')) {
                    return true;
                }
            }
            break;
        }
        ++incr;
        p = {kingPosn.getRow() + incr, kingPosn.getCol() + incr};
    }

    // checking if King is in check from the top right
    incr = 1;
    p = {kingPosn.getRow() - incr, kingPosn.getCol() + incr};

    while (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if ((board[p.getRow()][p.getCol()]->getType() == 'q') || (board[p.getRow()][p.getCol()]->getType() == 'b')) {
                    return true;
                }
            }
            break;
        }
        ++incr;
        p = {kingPosn.getRow() - incr, kingPosn.getCol() + incr};
    }

    // checking if King is in check from the top left
    incr = 1;
    p = {kingPosn.getRow() - incr, kingPosn.getCol() - incr};

    while (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if ((board[p.getRow()][p.getCol()]->getType() == 'q') || (board[p.getRow()][p.getCol()]->getType() == 'b')) {
                    return true;
                }
            }
            break;
        }
        ++incr;
        p = {kingPosn.getRow() - incr, kingPosn.getCol() - incr};
    }

    // checking if King is in check from the bottom left
    incr = 1;
    p = {kingPosn.getRow() + incr, kingPosn.getCol() - incr};

    while (p.positionWithinBounds()) {
        if (board[p.getRow()][p.getCol()] != nullptr) {
            if (board[p.getRow()][p.getCol()]->getColour() != colour) {
                if ((board[p.getRow()][p.getCol()]->getType() == 'q') || (board[p.getRow()][p.getCol()]->getType() == 'b')) {
                    return true;
                }
            }
            break;
        }
        ++incr;
        p = {kingPosn.getRow() + incr, kingPosn.getCol() - incr};
    }

    // King is not in check
    return false;
}

bool Board::MovesLeft(const string &colour) {
    for (auto it = pieceArray.begin(); it != pieceArray.end(); ++it) {
        if (((*it)->getColour() == colour) && ((*it)->numPossibleMoves() != 0)) {
            return false;
        }
    }

    return true;
}




