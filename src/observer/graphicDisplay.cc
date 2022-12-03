#include <iostream>
#include "graphicDisplay.h"

using namespace std;


GraphicDisplay::GraphicDisplay(int rows, int cols) : 
rows{rows}, cols{cols}, windowFrame { make_unique<Xwindow>(rows * 62.5, cols * 62.5) } {

}



void GraphicDisplay::notify(std::vector<std::vector<Piece*>> &b) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
    //   char character = s->getState(i, j);

    //   if (character >= 'a' && character <= 'z') {
    //     windowFrame->fillRectangle( (j - l) * 10, (i - t) * 10, 10, 10, 2);
    //   } else if (character >= 'A' && character <= 'Z') {
    //     windowFrame->fillRectangle( (j - l) * 10, (i - t) * 10, 10, 10, 3);
    //   } else if (character >= '0' && character <= '9') {
    //     windowFrame->fillRectangle( (j - l) * 10, (i - t) * 10, 10, 10, 4);
    //   } else if (character != ' ') {
    //     windowFrame->fillRectangle( (j - l) * 10, (i - t) * 10, 10, 10, 1);
    //   } else {
    //     windowFrame->fillRectangle( (j - l) * 10, (i - t) * 10, 10, 10, 0);
    //   }
        if ((i + j) % 2 == 0) {
            windowFrame->fillRectangle( j * 62.5, i * 62.5, 62.5, 62.5, 0);
        } else {
            windowFrame->fillRectangle( j * 62.5, i * 62.5, 62.5, 62.5, 1);
        }

    }
  }
}

GraphicDisplay::~GraphicDisplay() {} 

