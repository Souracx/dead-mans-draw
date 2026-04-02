#include "MermaidCard.h"
#include <iostream>

std::string MermaidCard::str() const {
    return "Mermaid(" + std::to_string(_value) + ")"; 
}

void MermaidCard::play(Game &game, Player& player) {
    std::cout << " No effect but Mermaids are worth more.\n"; 
}

