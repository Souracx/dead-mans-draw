#pragma once
#include "Card.h"

class MermaidCard : public Card {

    MermaidCard(int value) : Card(Mermaid, value) {}; 

    virtual std::string str() const override; 

    virtual void play(Game& game, Player& player) override;

};
