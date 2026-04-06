#include "SwordCard.h"
#include <iostream>

std::string SwordCard::str() const {
    return "Sword(" + std::to_string(_value) + ")";
}

void SwordCard::play(Game& game, Player& player) {
    //pseudocode - similar to hook but opponent 
    //1. Get opponent and the bank 
    //2. Check for empty bank - print and return 
    //3. Find highest card per suit in opponents' bank 
    //4. Display choice 
    //5. Get player's choice 
    //6. Remove chosen card from opponent's bank 
    //7. Play stlen card into play area ( can bust ) 
}