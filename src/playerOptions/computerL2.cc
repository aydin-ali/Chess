#include <iostream>
#include <sstream>
#include <vector>
#include <random>

#include "computerL2.h"
#include "../tools/move.h" 
#include "../board/board.h"
#include <ctime>

using namespace std;

ComputerL2::ComputerL2(std::string colour): Computer{colour} {}

bool ComputerL2::playerMove(std::string input, Board &gameBoard) {

    //check if the move entered is valid (input wise)
    if (input == "move") {
        srand(time(NULL));
        vector<Move> allPiecesPossibleMoves;
        vector<Move> allPiecesCheckingCapturingMoves;
        vector<Move> allPiecesCheckingMoves;
        vector<Move> allPiecesCapturingMoves;

        for (int row = 0; row < 8; ++row) {
            for(int col = 0; col < 8; ++col) {
                if (gameBoard.getBoardArr()[row][col] != nullptr && gameBoard.getBoardArr()[row][col]->getColour() == getColour()) {
                    if (gameBoard.getBoardArr()[row][col]->getPossibleMoves().size() >= 1) {
                        for (int i = 0; i < gameBoard.getBoardArr()[row][col]->getPossibleMoves().size(); i++) {
                            Move m = {row, col, gameBoard.getBoardArr()[row][col]->getPossibleMoves()[i].getRow(), gameBoard.getBoardArr()[row][col]->getPossibleMoves()[i].getCol()};
                            allPiecesPossibleMoves.emplace_back(m);
                            if (gameBoard.getBoardArr()[m.getEndRow()][m.getEndCol()] != nullptr) {
                                if ((gameBoard.getBoardArr()[m.getEndRow()][m.getEndCol()]->getColour() != getColour()) && (gameBoard.getBoardArr()[row][col]->checkingMove(gameBoard, {m.getEndRow(), m.getEndCol()}))) {
                                    allPiecesCheckingCapturingMoves.emplace_back(m);
                                }
                            }
                            if (gameBoard.getBoardArr()[m.getEndRow()][m.getEndCol()] != nullptr) {
                                if (gameBoard.getBoardArr()[m.getEndRow()][m.getEndCol()]->getColour() != getColour()) {
                                    allPiecesCapturingMoves.emplace_back(m);
                                }
                            }
                            if (gameBoard.getBoardArr()[row][col]->checkingMove(gameBoard, {m.getEndRow(), m.getEndCol()})) {
                                allPiecesCheckingMoves.emplace_back(m);
                            }
                        }
                    }
                }
            }
        }

        int randomMoveIndex;
        Move m = {0, 0, 0, 0};

        if (allPiecesCheckingCapturingMoves.size() >= 1) {
            randomMoveIndex = rand() % (allPiecesCheckingCapturingMoves.size());
            m = allPiecesCheckingCapturingMoves[randomMoveIndex];
        } else if (allPiecesCheckingMoves.size() >= 1) {
            randomMoveIndex = rand() % (allPiecesCheckingMoves.size());
            m = allPiecesCheckingMoves[randomMoveIndex];
        } else if (allPiecesCapturingMoves.size() >= 1) {
            randomMoveIndex = rand() % (allPiecesCapturingMoves.size());
            m = allPiecesCapturingMoves[randomMoveIndex];
        } else {
            randomMoveIndex = rand() % (allPiecesPossibleMoves.size());
            m = allPiecesPossibleMoves[randomMoveIndex];
        }
        
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
    } else {
        cout << "Invalid move: Invalid input" << endl << endl;
    }
    return false;
}
