#pragma once
#include "Card.h"

class KrakenCard : public Card {
public: 
    KrakenCard(int value) : Card(Kraken, value) {}; 

    virtual std::string str() const override; 

    virtual void play(Game& game, Player& player) override; 

};