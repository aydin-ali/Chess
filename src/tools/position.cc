#include "position.h"

Position::Position(int row, int col) : 
row{row}, col{col} {}

int Position::getRow() {
    return row;
}

int Position::getCol() {
    return col;
} 

bool Position::positionWithinBounds() {
    return (((0 <= row) && (row <= 7)) && ((0 <= col) && (col <= 7)));
}