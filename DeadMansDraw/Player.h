#pragma once 
#include "Card.h"
#include <iostream>

class Game; 

class Player {
private: 
    std::string _name; 
    CardCollection _playArea; 
    CardCollection _bank; 

public: 
    Player(); 
    ~Player(); 

    //Adds card to play area, returns true if bust 
    bool playCard(Card* card, Game& game); 
    void bankCards(Game& game); //moves play area to bank 
    void discardPlayArea(Game& game); //moves play area to discard (on bust) 

    int score() const; //return total score of bank 
    bool isBust() const; //return true if play area has duplicate suit 

    void printPlayArea() const; //prints play are to screen 
    void printBank() const; //prints bank to screen 

    std::string getName() const; //returns player's name 
    CardCollection& getBank(); //returns reference to bank 
    CardCollection& getPlayArea(); //returns reference to play area
};