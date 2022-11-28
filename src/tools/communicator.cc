#include <iostream>
#include <string>

#include "communicator.h"


void Communicator::outputMessage(std::string msg) {
    std::cout << msg << std::endl;
}

std::string Communicator::takeInput() {
    std::string in;
    std::cin >> in;
    return in;
}
