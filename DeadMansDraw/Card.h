#pragma once
#include <vector>
#include <string>

//Represents suit/type of a card 
enum CardType { Cannon, Chest , Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken };

class Player; 
class Game; 

//Abstract Base Class representing a card in the game - cannot be instantiated directly 
class Card {
    protected:
        CardType _type;
        int _value;

    public: 
        Card(CardType type, int value) : _type(type), _value(value) {}

        virtual ~Card() {}

        const CardType& type() const {
            return _type; 
        }

        int value() const {
            return _value; 
        }

        virtual std::string str() const = 0; 

        virtual void play(Game& game, Player& player) = 0; 

        virtual void willAddToBank(Game& game, Player& player) {}
};

typedef std::vector<Card*> CardCollection; 