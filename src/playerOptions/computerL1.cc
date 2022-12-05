#include <iostream>
#include <sstream>
#include <vector>
#include <random>

#include "computerL1.h"
#include "../tools/move.h" 
#include "../board/board.h"
#include <ctime>

using namespace std;

ComputerL1::ComputerL1(std::string colour) : Computer{colour} {

}




bool ComputerL1::playerMove(std::string input, Board &gameBoard) {
    //check if the move entered is valid (input wise)
    if (input == "move") {

        srand(time(NULL));

        vector<Move> allPiecesPossibleMoves; 

        for(int row = 0; row < 8; ++row){
            for(int col = 0; col < 8; ++col){

                if (gameBoard.getBoardArr()[row][col] != nullptr && gameBoard.getBoardArr()[row][col]->getColour() == getColour()) {
                    if (gameBoard.getBoardArr()[row][col]->getPossibleMoves().size() >= 1) {

                        // for (auto it = gameBoard.getBoardArr()[row][col]->getPossibleMoves().begin(); it != gameBoard.getBoardArr()[row][col]->getPossibleMoves().end(); ++it){
                        //     Move m = {row, col, it->getRow(), it->getCol()};
                        //     allPiecesPossibleMoves.emplace_back(m);
                        // }

                        for (int i = 0; i < gameBoard.getBoardArr()[row][col]->getPossibleMoves().size(); i++) {
                            Move m = {row, col, gameBoard.getBoardArr()[row][col]->getPossibleMoves()[i].getRow(), gameBoard.getBoardArr()[row][col]->getPossibleMoves()[i].getCol()};
                            allPiecesPossibleMoves.emplace_back(m);
                        }

                    }
                }

            }
        }

        int randomMoveIndex = rand() % (allPiecesPossibleMoves.size());
        
        //convert to a move object
        Move m = allPiecesPossibleMoves[randomMoveIndex];

        char promoteType;
        if (getColour() == "white") {
            promoteType = 'Q';
        } else if (getColour() == "black") {
            promoteType = 'q';
        }


        // Check if piece is a pawn
        if(gameBoard.getBoardArr()[m.getStartRow()][m.getStartCol()] != nullptr && gameBoard.getBoardArr()[m.getStartRow()][m.getStartCol()]->getType() == 'p'){
            // Check if pawn is in position to promote 
            if (gameBoard.inPositionToPromote(m)) {
                // Check all other conditions for pawn to actually promote
                if(gameBoard.canPromote(m, gameBoard.getBoardArr()[m.getStartRow()][m.getStartCol()]->getColour(), promoteType)){

                    gameBoard.moveOnBoard(m);
                    gameBoard.actuallyPromote(m, gameBoard.getBoardArr()[m.getEndRow()][m.getEndCol()]->getColour(), promoteType);
                    promoteType = ' ';
                }
            } else {
                gameBoard.moveOnBoard(m);
            }
        } else {
            gameBoard.moveOnBoard(m); //if the piece is NOT a pawn, just move it normally
        }
        return true;     


    } else { //entered move is invalid input
        cout << "Invalid move: Invalid input" << endl << endl;
    }

    return false;}
