#include "SwordCard.h"
#include <iostream>
#include "Game.h"
#include "Player.h"
#include <unordered_map>
#include <vector>

std::string SwordCard::str() const {
    return "Sword(" + std::to_string(_value) + ")";
}
//Can steal opponents card 
void SwordCard::play(Game& game, Player& player) {

    Player& otherPlayer = game.getOtherPlayer(player); //opponent 
    CardCollection& bank = otherPlayer.getBank(); //get stored cards of opponent 

    //check if the bank is empty 
    if (bank.empty()) {
        std::cout << " No cards in " << otherPlayer.getName() << "'s Bank. Play continues.\n"; 
        return; 
    }
    
    //find highest card per suit in opponent's bank 
    std::unordered_map<CardType, Card*> highest; 
    std::vector<CardType> order; //track order of insertion 

    for (Card* card : bank) {
        if (highest.find(card->type()) == highest.end()) {
            order.push_back(card->type()); 
            highest[card->type()] = card; 
        }
        else if (card->value() > highest[card->type()]->value()) {
            highest[card->type()] = card; 
        }
    }
    //display choice to player 
    std::cout << " Steal the top card of any suit from " << otherPlayer.getName() << "'s Bank into your play area.\n"; 
    for (int i = 0; i < order.size(); i++) {
        std::cout << " (" << (i + 1) << ") " << highest[order[i]]->str() << "\n"; 
    }

    //get player's choice
    int choice = 0; 
    while (choice < 1 || choice > order.size()) {
        std::cout << " Which card do you pick? "; 
        std::cin >> choice; 
    }

    Card* target = highest[order[choice - 1]];
    //remove from opponent's bank 
    bank.erase(std::remove(bank.begin(), bank.end(), target), bank.end());

    std::cout << "  " << player.getName() << " steals " << target->str() << ".\n";

    // Play the stolen card into play area  
    bool bust = player.playCard(target, game);
    if (bust) {
        std::cout << "BUST! " << player.getName() << " loses all cards in play area.\n";
        player.discardPlayArea(game);
    }
}