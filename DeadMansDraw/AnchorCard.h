#pragma once
#include "Card.h"

class AnchorCard : public Card {
public: 
    AnchorCard(int value) : Card(Anchor, value) {
    }

    virtual std::string str() const override; 

    virtual void play(Game& game, Player& player) override; 

};