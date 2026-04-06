#include "CannonCard.h"
#include <iostream>
#include "Player.h"
#include "Game.h"
#include <unordered_map>

std::string CannonCard::str() const {
    return "Cannon(" + std::to_string(_value) + ")"; 
}

//Discard highest value card of a chosen suit from opponent's bank 
void CannonCard::play(Game &game , Player& player)  {

    Player& otherPlayer = game.getOtherPlayer(player); //get opponent 
    CardCollection& bank = otherPlayer.getBank();  //get opponent's bank 
    //check if bank is empty 
    if (bank.empty()) {
        std::cout << "No cards in " << otherPlayer.getName() << "'s Bank. Continue Playing.\n"; 
        return; 
    }

    //find highest card per suit in opponent's bank 
    std::unordered_map<CardType, Card*> highest; 
    std::vector<CardType> order; 
    for (Card* card : bank) {
        if (highest.find(card->type()) == highest.end()) {
            order.push_back(card->type()); 
            highest[card->type()] = card; 
        }
        else if (card->value() > highest[card->type()]->value()) {
            highest[card->type()] = card; 
        }
    }

    //display choices to the player 
    std::cout << " Discard the top card of any suit from " << otherPlayer.getName() << "'s Bank.\n"; 
    for (int i = 0; i < order.size(); i++) {
        std::cout << " (" << (i + 1) << ") " << highest[order[i]]->str() << "\n"; 
    }

    //get player's choice 
    int choice = 0;
    while (choice<1 || choice > order.size()) {
        std::cout << "Which card do you pick? "; 
        std::cin >> choice; 
    }

    Card* target = highest[order[choice - 1]]; 
    std::cout << player.getName() << " discards " << target->str() << " from " << otherPlayer.getName() << "'s Bank.\n"; 
    //remove from the opponent bank into discard pile
    bank.erase(std::remove(bank.begin(), bank.end(), target), bank.end()); 
    game.getDiscard().push_back(target); //add 
}