#pragma once
#include "Card.h"

class CannonCard : public Card {

    CannonCard(int value) : Card(Cannon, value) { }

    virtual std::string str() const override; 

    virtual void play(Game& game, Player& player) override;

};