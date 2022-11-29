#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
class Piece;

class Observer{
public:
    virtual void notify(std::vector<std::vector<Piece*>> &b);
    virtual ~Observer()=default;
};

#endif
