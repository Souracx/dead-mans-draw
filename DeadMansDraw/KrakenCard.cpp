#include "KrakenCard.h"
#include <iostream>

std::string KrakenCard::str() const {
    return "Kraken(" + std::to_string(_value) + ")"; 
}

void KrakenCard::play(Game& game, Player& player) {
    //todo 
}