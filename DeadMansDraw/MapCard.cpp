#include <iostream>
#include "MapCard.h"
#include "Game.h"
#include "Player.h"

std::string MapCard::str() const {
    return "Map(" + std::to_string(_value) + ")"; 
}

void MapCard::play(Game& game, Player& player){
    //Pseudocode 
    //Get discard pile 
    //if discard empty print message and return 
    //draw up 3 cards from discard 
    //display numbered list of drawn cards
    //player picks one card to play 
    //return unselected card to discard
    //play chosen card into play area - check bust 
}