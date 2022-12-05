#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include "../tools/move.h"
#include "../tools/position.h"

// abstract class Piece

/* struct Posn{
    int x;
    int y;
}; */

class Board;

class Piece {

private:
    char type;

protected:
    std::string colour;
    std::vector<Position> possibleMoves;
    Position posn;
    bool moved;

public:
    Piece(const std::string &colour, const char &type, int row, int col);
    virtual ~Piece();
    virtual bool validMove(Move move, std::vector<std::vector<Piece*>> board) = 0;
    virtual void updatePossibleMoves(std::vector<std::vector<Piece*>> board, Board &b) = 0;

    //virtual void checkForCheck()=0;
    std::string getColour();
    char getType();
    Position getPosn();
    bool isMoved();
    bool moveAllowed(Board &b, Position p);
    bool inPossibleMoves(Position p);
    int numPossibleMoves();
    void updatePosn(int row, int col);
  /*  void adjustMoved(); // NOT DONE
    virtual bool validMove( fill this out );*/
};


#endif

