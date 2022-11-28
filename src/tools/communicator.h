#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <string>

class Communicator {

private:


public:
    void outputMessage(std::string msg);
    std::string takeStringInput();
    int takeIntInput();

};

#endif
