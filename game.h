#include "subject.h"
#include "board.h"
#include "communicator.h"

class Game : public Subject {

private:
    Board board;
    Communicator communicator;

public:
    //ctor dtor?
    void move();
    void setup(bool normalMode);
    

};