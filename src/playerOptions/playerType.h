#ifndef PLAYERTYPE_H
#define PLAYERTYPE_H

class PlayerType {

private:
    char colour;

public:

    PlayerType(char colour);
    virtual void playerMove();
    virtual ~PlayerType() = 0;
    char getColour();

};

#endif
