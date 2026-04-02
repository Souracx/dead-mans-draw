#include <iostream>
#include "OracleCard.h"
#include "Player.h"
#include "Game.h"

std::string OracleCard::str() const {
    return "Oracle(" + std::to_string(_value) + ")"; 
}

//peak at top of card deck before deciding to draw
void OracleCard::play(Game& game, Player& player){
    CardCollection& deck = game.getDeck(); 
    if (deck.empty()) {
        std::cout << " The Oracle sees nothing - the deck is empty.\n"; 
        return;
    }
    //Peek at top
    Card* top = deck.back(); 
    std::cout << "The Oracle sees a " << top->str() << "\n";
}