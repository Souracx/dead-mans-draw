#include "KeyCard.h"
#include <iostream>

std::string KeyCard::str() const {
    return "Key(" + std::to_string(_value) + ")"; 
}

void KeyCard::play(Game& game, Player& player) {}

void KeyCard::willAddToBank(Game& game, Player& player) {}