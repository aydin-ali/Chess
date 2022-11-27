#ifndef PIECE_H
#define PIECE_H

// abstract class Piece

class Piece {

private:
    char colour;

public:
    virtual bool validMove();
    virtual void checkForCheck();

};


#endif
