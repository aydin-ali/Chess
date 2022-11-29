#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <map>
#include <vector>
#include <memory>

class Piece;
// don't need class Piece here because it's in game????

class Board {

private:
    std::vector<std::vector<Piece *>> board;
    std::map<std::string, Piece*> boardMap;

public:
    Board();
    void setupBoard();
    void moveOnBoard();
    std::vector<std::vector<Piece*>> &getBoardArr();
};

#endif

