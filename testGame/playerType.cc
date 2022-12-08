#include "playerType.h"

PlayerType::PlayerType(std::string colour) : 
colour{colour} {

}

PlayerType::~PlayerType() { }

bool PlayerType::playerMove(std::string input, Board &gameBoard) {

}

std::string PlayerType::getColour() {
    return colour;
}






