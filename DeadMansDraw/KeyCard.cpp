#include "KeyCard.h"
#include <iostream>

std::string KeyCard::str() const {
    return "Key(" + std::to_string(_value) + ")"; 
}

void KeyCard::play(Game& game, Player& player) {
    std::cout << " No immediate effect. If banked with chest, draw as many bonus cards from the Discard pile as you moved into your Bank.\n"; 
}
//Chest hand's the ability 
void KeyCard::willAddToBank(Game& game, Player& player) {}