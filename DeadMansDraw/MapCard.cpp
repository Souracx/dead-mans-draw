#include <iostream>
#include "MapCard.h"

std::string MapCard::str() const {
    return "Map(" + std::to_string(_value) + ")"; 
}

void MapCard::play(Game& game, Player& player){ }