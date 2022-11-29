#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "observer.h"
#include <vector>

class TextDisplay : public Observer{
    std::vector<std::vector<char>> printedBoard;
public:
    TextDisplay();
    ~TextDisplay()=default;
    virtual void notify(std::vector<std::vector<Piece*>> &b);
};

#endif
