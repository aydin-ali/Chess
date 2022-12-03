#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <vector>
#include <memory>
#include "observer.h"
#include "../board/board.h"

class TextDisplay : public Observer {
    std::vector<std::vector<char>> printedBoard;
public:
    TextDisplay();
    ~TextDisplay()=default;
    void notify(std::vector<std::vector<Piece*>> &b) override;
};

#endif
