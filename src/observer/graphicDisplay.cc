#include <iostream>
#include "graphicDisplay.h"

using namespace std;


GraphicDisplay::GraphicDisplay(int rows, int cols) : 
rows{rows}, cols{cols}, windowFrame { make_unique<Xwindow>(rows * 75, cols * 75) } {
    windowFrame->fillRectangle( 0, 0, 75 * rows, 75 * cols, 5);
}



//NEXT: redraw as little of thes screen as possible for each new move

void GraphicDisplay::notify(std::vector<std::vector<Piece*>> &b) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {

        if ((i + j) % 2 == 0) { //white squares
            windowFrame->fillRectangle(j * 75, i * 75, 75, 75, 0);
        } else { //black squares
            windowFrame->fillRectangle(j * 75, i * 75, 75, 75, 2);
        }

        if (b[i][j] != nullptr){
            string type;
            if (b[i][j]->getColour() == "white") {
                type += toupper(b[i][j]->getType());
            } else {
                type += b[i][j]->getType();
            }
            windowFrame->drawString(75 * j + 35, i * 75 + 40, type);
            //75 is the distance between the pieces, 38 is the position within the square
        }

    }
  }
}

GraphicDisplay::~GraphicDisplay() {} 

