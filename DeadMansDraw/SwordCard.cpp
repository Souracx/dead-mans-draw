#include "SwordCard.h"
#include <iostream>

std::string SwordCard::str() const {
    return "Sword(" + std::to_string(_value) + ")";
}

void SwordCard::play(Game& game, Player& player) {}