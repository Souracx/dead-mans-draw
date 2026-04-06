#include "HookCard.h"
#include <iostream>
#include "Game.h"
#include "Player.h" 

std::string HookCard::str() const {
    return "Hook(" + std::to_string(_value) + ")";
}

//Ability - Can use top card from own bank 
void HookCard::play(Game& game, Player& player) {
    //pseudocode 
    //1. Get own bank 
    //2. if bank empty print and return 
    //3. find highest card per suit in own bank 
    //4. Display numbered list of choice 
    //5. Get player's choice 
    //6. Remove chosen card from own bank 
    //7. play the card into play area(check for bust) 
}