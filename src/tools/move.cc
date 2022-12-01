#include "move.h"

Move::Move(std::string startPos, std::string endPos) : startPos{startPos}, endPos{endPos} {
    convert();
}

void Move::convert() {

    startRow = startPos[0]-97;
    startCol = startPos[1]-49;
    endRow = endPos[0]-97;
    endCol = endPos[1]-49;

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

