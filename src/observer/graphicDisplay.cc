#include <iostream>
#include "graphicDisplay.h"

using namespace std;


GraphicDisplay::GraphicDisplay(Game *g, int rows, int cols) : 
g{g}, rows{rows}, cols{cols}
{ 

    //windowFrame { std::make_unique<Xwindow>( 500, 500 ) };

    g->attach(this);
}

GraphicDisplay::~GraphicDisplay() {
    // delete windowFrame;
    // s->detach(this);
} 

void GraphicDisplay::notify(std::vector<std::vector<Piece*>> &b) {
//   for (int i = t; i <= b; i++) {
//     for (int j = l; j <= r; j++) {
//       char character = s->getState(i, j);

//       if (character >= 'a' && character <= 'z') {
//         windowFrame->fillRectangle( (j - l) * 10, (i - t) * 10, 10, 10, 2);
//       } else if (character >= 'A' && character <= 'Z') {
//         windowFrame->fillRectangle( (j - l) * 10, (i - t) * 10, 10, 10, 3);
//       } else if (character >= '0' && character <= '9') {
//         windowFrame->fillRectangle( (j - l) * 10, (i - t) * 10, 10, 10, 4);
//       } else if (character != ' ') {
//         windowFrame->fillRectangle( (j - l) * 10, (i - t) * 10, 10, 10, 1);
//       } else {
//         windowFrame->fillRectangle( (j - l) * 10, (i - t) * 10, 10, 10, 0);
//       }

//     }
//   }
}


