#include "CannonCard.h"
#include <iostream>

std::string CannonCard::str() const {
    return "Cannon(" + std::to_string(_value) + ")"; 
}

void CannonCard::play(Game &game , Player& player)  {
    //todo 
}