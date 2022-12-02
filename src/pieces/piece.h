#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include "../tools/move.h"

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
    std::vector<Move> possibleMoves;
    bool moved;

public:
    Piece(const std::string &colour, const char &type);
    virtual ~Piece();
    virtual bool validMove(Move move, vector<vector<Piece*>>) = 0;
    virtual void updatePossibleMoves(Move move, vector<vector<Piece*>>) = 0;

    //virtual void checkForCheck()=0;
    std::string getColour();
    char getType();
    bool isMoved();
  /*  void adjustMoved(); // NOT DONE
    virtual bool validMove( fill this out );*/
};


#endif

