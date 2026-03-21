#pragma once
#include "Card.h"

class OracleCard : public Card {
public:     
    OracleCard(int value) : Card(Oracle, value) { }
    
    virtual std::string str() const override; 

    virtual void play(Game& game, Player& player) override; 
};