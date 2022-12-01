#include "playerType.h"

PlayerType::PlayerType(std::string colour) : colour{colour} {

}

PlayerType::~PlayerType() { }

void PlayerType::playerMove() {

}

std::string PlayerType::getColour() {
    return colour;
}
