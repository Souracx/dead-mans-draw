#pragma once
#include "Card.h"

class ChestCard : public Card {
public: 
    ChestCard(int value) : Card(Chest, value) { }

    virtual std::string str() const override;

    virtual void play(Game& game, Player& player) override; 

    virtual void willAddToBank(Game& game, Player& player) override;



};