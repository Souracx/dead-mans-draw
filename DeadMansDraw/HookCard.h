#pragma once
#include "Card.h"

class HookCard : public Card {
public: 
    HookCard(int value) : Card(Hook, value) {}; 

    virtual std::string str() const override; 

    virtual void play(Game& game, Player& player) override; 
};