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

class Piece {

private:
    char type;

protected:
    std::string colour;
    std::vector<Position> possibleMoves;
    bool moved;

public:
    Piece(const std::string &colour, const char &type);
    virtual ~Piece();
    virtual bool validMove(Move move, std::vector<std::vector<Piece*>> board) = 0;
    virtual void updatePossibleMoves(Move move, std::vector<std::vector<Piece*>> board) = 0;

    //virtual void checkForCheck()=0;
    std::string getColour();
    char getType();
    bool isMoved();
  /*  void adjustMoved(); // NOT DONE
    virtual bool validMove( fill this out );*/
};


#endif

