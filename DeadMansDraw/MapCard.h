#pragma once
#include "Card.h"

class MapCard : public Card {
public: 
    MapCard(int value) : Card(Map, value) {}

    virtual std::string str() const override; 

    virtual void play(Game& game, Player& player) override; 
};