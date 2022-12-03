#ifndef POSITION_H
#define POSITION_H

#include <string>

class Position {

private:
    int row;
    int col;

public:
    Position(int row, int col);
    int getRow();
    int getCol();
    bool positionWithinBounds();
    bool operator==(Position &other);
};

#endif
