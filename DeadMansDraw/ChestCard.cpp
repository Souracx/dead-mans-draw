#include "ChestCard.h"
#include <iostream>
#include "Player.h"
#include "Game.h"

std::string ChestCard::str() const {
    return "Chest(" + std::to_string(_value) + ")"; 
}

//No immediate effect on draw 
void ChestCard::play(Game& game, Player& player) {
    std::cout << " No immediate effect. If banked with a key, draw as many bonus cards from the Discard pile as you moved into your Bank.\n"; 
}

//Called before banking - if play area has a key 
void ChestCard::willAddToBank(Game& game, Player& player) {
    CardCollection& playArea = player.getPlayArea(); 

    //Check if there's a key in the play area
    bool hasKey = false; 
    for (Card* card : playArea) {
        if (card->type() == Key) {
            hasKey = true; 
            break; 
        }
    }
    // no key found - no effect 
    if (!hasKey) return; 

    //bonus count equals number of cards being banked
    int bonusCount = playArea.size(); 
    CardCollection& discard = game.getDiscard(); 

    //check if discard is empty 
    if (discard.empty()) {
        std::cout << " Chest and Key activated. No cards in discard to draw.\n"; 
        return; 
    }
    std::cout << " Chest and Key activated. Added"; 

    //draw bonus card from discard
    std::vector<Card*> added_cards; 
    for (int i = 0; i < bonusCount && !discard.empty(); i++) {
        Card* bonus = game.drawFromDiscard(); 
        added_cards.push_back(bonus); 
        std::cout << bonus->str(); 
        if (i < bonusCount - 1 && !discard.empty()) {
            std::cout << ", "; 
        }
    }

    //Add Bonus cards directly into the bank 
    for (Card* card : added_cards) {
        player.getBank().push_back(card); 
    }

}

