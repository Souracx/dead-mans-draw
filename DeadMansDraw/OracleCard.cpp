#include <iostream>
#include "OracleCard.h"

std::string OracleCard::str() const {
    return "Oracle(" + std::to_string(_value) + ")"; 
}

void OracleCard::play(Game& game, Player& player){ }