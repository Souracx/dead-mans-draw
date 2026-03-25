#include "Player.h"
#include "Game.h"
#include <unordered_map>

Player::Player() {
    std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" }; 
    _name = names[rand() % 10]; 
}

Player::~Player() {
    for (Card* card : _playArea) {
        delete card; 
    }
    for (Card* card : _bank) {
        delete card; 
    }
}

//Return true if play area contains two cards of same suit 
bool Player::isBust() const {
    //count occurences of each suit 
    std::unordered_map<CardType, int> counts; 
    for (Card* card : _playArea) {
        counts[card->type()]++; 
        if (counts[card->type()] > 1) 
            return true; 
    }
    return false; 
}

//Returns total score of player's bank 
int Player::score() const {
    //track highest value card for each suit
    std::unordered_map<CardType, int> highest_val; 

    for (Card* card : _bank) {
        CardType t = card->type(); 
        if (highest_val[t] < card->value()) {
            highest_val[t] = card->value(); 
        }
    }
    //sum total highest value of each suit 
    int total = 0; 
    for (auto& pair : highest_val) {
        total += pair.second; 
    }
    return total; 
}

//Print player's play area
void Player::printPlayArea() const {
    std::cout << _name << "'s Play Area:" << "\n"; 
    for (Card* card : _playArea) {
        std::cout << "  " << card->str() << "\n"; 
    }
}

//Print Player's Bank with Score
void Player::printBank() const {
    std::cout << _name << "'s Bank:" << "\n"; 
    for (Card* card : _bank) {
        std::cout << "  " << card->str() << "\n"; 
    }
    std::cout << "| Score: " << score() << "\n";
}

//Adds card to player's play area, returns true if player bust 
bool Player::playCard(Card* card, Game& game) {
    //add card to play area
    _playArea.push_back(card); 
    //check if player is bust
    if (isBust()) {
        return true; 
    }
    //play cards ability
    card->play(game, *this); 
    //not bust
    return false; 
}

void Player::bankCards(Game& game) {
    //call willAddToBank on each card before banking 
    for (Card* card : _playArea) {
        card->willAddToBank(game, *this); 
    }
    //move all cards from play area to bank 
    for (Card* card : _playArea) {
        _bank.push_back(card); 
    }
    //clear the playArea
    _playArea.clear(); 
}

std::string Player::getName() const {
    return _name; 
}

CardCollection& Player::getBank() {
    return _bank; 
}

CardCollection& Player::getPlayArea() {
    return _playArea; 
}