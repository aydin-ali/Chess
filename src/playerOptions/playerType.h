#ifndef PLAYERTYPE_H
#define PLAYERTYPE_H

#include <string>

class PlayerType {

private:
    std::string colour;

public:

    PlayerType(std::string colour);
    virtual void playerMove();
    virtual ~PlayerType() = 0;
    std::string getColour();

};

#endif
