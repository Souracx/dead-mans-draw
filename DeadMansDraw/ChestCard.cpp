#include "ChestCard.h"
#include <iostream>

std::string ChestCard::str() const {
    return "Chest(" + std::to_string(_value) + ")"; 
}

void ChestCard::play(Game& game, Player& player) {}

void ChestCard::willAddToBank(Game& game, Player& player) {}

