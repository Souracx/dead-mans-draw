#include "HookCard.h"
#include <iostream>

std::string HookCard::str() const {
    return "Hook(" + std::to_string(_value) + ")";
}

void HookCard::play(Game& game, Player& player) {
    //todo 
}