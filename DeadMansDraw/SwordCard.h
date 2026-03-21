#pragma once
#include "Card.h"

class SwordCard : public Card {
public:
    SwordCard(int value) : Card(Sword, value) {}; 

    virtual std::string str() const override; 

    virtual void play(Game& game, Player& player) override; 

};
