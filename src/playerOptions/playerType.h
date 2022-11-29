#ifndef PLAYERTYPE_H
#define PLAYERTYPE_H

class PlayerType {

private:
    char colour;

public:

    //PlayerType();

    virtual void playerMove();
    virtual ~PlayerType() = 0;

};

#endif
