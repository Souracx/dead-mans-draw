#include "HookCard.h"
#include <iostream>
#include "Game.h"
#include "Player.h" 
#include <unordered_map>
#include <vector>


std::string HookCard::str() const {
    return "Hook(" + std::to_string(_value) + ")";
}

//Ability - Can use top card from own bank 
void HookCard::play(Game& game, Player& player) {
   
    CardCollection& bank = player.getBank(); //get player's bank 
    //check if empty 
    if (bank.empty()) {
        std::cout << " No card's in your bank. Continue playing.\n";
        return;
    }

    //find highest card per suit in own bank 
    std::unordered_map<CardType, Card*> highest; //store best seen card 
    std::vector<CardType> order; //track insertion order 
    for (Card* card : bank) {
        if (highest.find(card->type()) == highest.end()) {
            order.push_back(card->type());
            highest[card->type()] = card;
        }
        else if (card->value() > highest[card->type()]->value()) {
            highest[card->type()] = card; 
        }
    }

    //display choices to player 
    std::cout << "Select a highest-value card from any of suits in your Bank:\n"; 
    for (int i = 0; i < order.size(); i++) {
        std::cout << " (" << (i + 1) << ") " << highest[order[i]]->str() << "\n"; 
    }

    //get players choice 
    int choice = 0; 
    while (choice < 1 || choice > order.size()) {
        std::cout << "Which card do you pick? "; 
        std::cin >> choice; 
    }
    Card* target = highest[order[choice - 1]]; 
    //remove from own bank 
    bank.erase(std::remove(bank.begin(), bank.end(), target), bank.end());
    std::cout << player.getName() << " hooks " << target->str() << " from their bank.\n"; 

    //play the hooked card into play area
    bool bust = player.playCard(target, game); 
    if (bust) {
        std::cout << "BUST" << player.getName() << " loses all cards in play area.\n"; 
        player.discardPlayArea(game); 
    }
}