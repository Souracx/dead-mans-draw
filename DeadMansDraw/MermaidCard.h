#pragma once
#include "Card.h"

class MermaidCard : public Card {
public: 
    MermaidCard(int value) : Card(Mermaid, value) {}; 

    virtual std::string str() const override; 

    virtual void play(Game& game, Player& player) override;

};
