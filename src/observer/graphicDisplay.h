#ifndef _GRAPHICDISPLAY_H_
#define _GRAPHICDISPLAY_H_

#include <memory>

#include "observer.h"
#include "../game.h"
#include "../window/window.h"

class Subject;

class GraphicDisplay : public Observer {
    int rows, cols;
    std::unique_ptr<Xwindow> windowFrame;

public:
    GraphicDisplay(int rows, int cols);
    void notify(std::vector<std::vector<Piece*>> &b) override;
    ~GraphicDisplay();
};
#endif
