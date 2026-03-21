#pragma once
#include "Card.h"

class KeyCard : public Card {
public: 
    KeyCard(int value) : Card(Key, value){ }

    virtual std::string str() const override; 

    virtual void play(Game& game, Player& player) override; 

    virtual void willAddToBank(Game& game, Player& player) override; 

};