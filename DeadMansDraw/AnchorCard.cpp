#include "AnchorCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <algorithm>

std::string AnchorCard::str() const {
    return "Anchor(" + std::to_string(_value) + ")"; 
}

//Card drawn before anchor are safe 
void AnchorCard::play(Game& game, Player& player) {
    CardCollection& playArea = player.getPlayArea(); 
    CardCollection& bank = player.getBank(); 

    //move all cards except anchor directly in bank 
    for (Card* card : playArea) {
        if (card != this) {
            bank.push_back(card); 
        }
    }
    //keeps the anchor in the playArea and removes all card that are not anchor
    playArea.erase(
        std::remove_if(playArea.begin(), playArea.end(),
            [this](Card* c) { return c != this;  }),
        playArea.end());
}