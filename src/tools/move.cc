#include "move.h"

Move::Move(std::string startPos, std::string endPos, std::string colour) : 
startPos{startPos}, endPos{endPos}, colour{colour} {
    convert();
}

void Move::convert() {

    startRow = 7 - startPos[1] + 49;
    startCol = startPos[0] - 97;
    endRow = 7 - endPos[1] + 49;
    endCol = endPos[0] - 97;

}


std::string Move::getColour() {
    return colour;
}

int Move::getStartRow() {
    return startRow;
}
int Move::getStartCol() {
    return startCol;
}
int Move::getEndRow() {
    return endRow;
}
int Move::getEndCol() {
    return endCol;
}

