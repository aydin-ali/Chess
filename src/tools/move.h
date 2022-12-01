#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {

private:
    std::string startPos;
    std::string endPos;

    int startRow;
    int startCol;
    int endRow;
    int endCol;

public:
    Move(std::string startPos, std::string endPos);
    void convert();

    int getStartRow();
    int getStartCol();
    int getEndRow();
    int getEndCol();

};

#endif
