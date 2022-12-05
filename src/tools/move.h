#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {

private:
    std::string startPos;
    std::string endPos;

    std::string colour;

    int startRow;
    int startCol;
    int endRow;
    int endCol;

public:
    Move(std::string startPos, std::string endPos, std::string colour);
    Move(int startRow, int startCol, int endRow, int endCol);

    void convert();

    std::string getColour();
    int getStartRow();
    int getStartCol();
    int getEndRow();
    int getEndCol();

    bool operator==(Move &other);

};

#endif
