#include "KrakenCard.h"
#include <iostream>
#include "Game.h"
#include "Player.h"

std::string KrakenCard::str() const {
    return "Kraken(" + std::to_string(_value) + ")"; 
}

//Ability - must draw 3 cards consecutively 
void KrakenCard::play(Game& game, Player& player) {
    std::cout << "Draw 3 cards from the deck and play each: \n"; 

    for (int i = 0; i < 3; i++) {
        //check if deck is empty 
        if (game.getDeck().empty()) {
            std::cout << "Deck is empty - Kraken stops.\n"; 
            break; 
        }
        //draw and play card
        Card* card = game.drawCard(); 
        std::cout << player.getName() << " draws a " << card->str() << "\n"; 

        bool bust = player.playCard(card, game); 
        if (bust) {
            std::cout << "BUST! " << player.getName() << " loses all cards in play area\n"; 
            player.discardPlayArea(game); 
            return; //turn is over
        }

    }
}