#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "../tools/move.h"

// abstract class Piece

/* struct Posn{
    int x;
    int y;
}; */

class Piece {

private:
    std::string colour;
    char type;
    bool moved;

public:
    Piece(const std::string &colour, const char &type);
    virtual ~Piece();
    virtual bool validMove(Move move) = 0;
    //virtual void checkForCheck()=0;
    std::string getColour();
    char getType();
    bool isMoved();
  /*  void adjustMoved(); // NOT DONE
    virtual bool validMove( fill this out );*/
};


#endif

