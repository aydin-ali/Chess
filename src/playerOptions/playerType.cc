#include "playerType.h"

PlayerType::PlayerType(char colour) : colour{colour} {

}

PlayerType::~PlayerType() { }

void PlayerType::playerMove() {

}

char PlayerType::getColour() {
    return colour;
}
