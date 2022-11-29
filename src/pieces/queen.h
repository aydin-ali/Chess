#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include <string>

class Queen : public Piece{
public:
    Queen(const std::string &colour);
};

#endif


