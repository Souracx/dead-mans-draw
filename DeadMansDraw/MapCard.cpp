#include <iostream>
#include "MapCard.h"
#include "Game.h"
#include "Player.h"


std::string MapCard::str() const {
    return "Map(" + std::to_string(_value) + ")"; 
}

//Draw 3 cards form discard and play one into play area
void MapCard::play(Game& game, Player& player){
 
    CardCollection& discard = game.getDiscard(); 
    //check if discard pile is empty
    if (discard.empty()) {
        std::cout << " No cards in discard. Play continues.\n"; 
        return; 
    }

    std::cout << "Draw 3 cards from the discard and pick one to add the play area.\n"; 
    //draw upto 3 cards from discard 
    std::vector<Card*> drawn_card; 
    for (int i = 0; i < 3 && !discard.empty(); i++) {
        drawn_card.push_back(game.drawFromDiscard()); 
    }

    //display drawn cards to player
    for (int i = 0; i < drawn_card.size(); i++) {
        std::cout << " (" << (i + 1) << ") " << drawn_card[i]->str() << "\n"; 
    }
    //get player's choice 
    int choice = 0; 
    while (choice < 1 || choice> drawn_card.size()) {
        std::cout << " Which card do you pick? "; 
        std::cin >> choice; 
    }

    Card* chosen = drawn_card[choice - 1]; 
    //return unselected card back to discard 
    for (int i = 0; i < drawn_card.size(); i++) {
        if (i != choice - 1) {
            discard.push_back(drawn_card[i]); 
        }
    }
    //play chosen card into play area
    bool bust = player.playCard(chosen, game); 
    if (bust) {
        std::cout << "BUST!" << player.getName() << " loses all cards in play area.\n"; 
        player.discardPlayArea(game); 
    }
}