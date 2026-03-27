#include "Game.h"
#include "game_title.h"
#include "MermaidCard.h"
#include "CannonCard.h"
#include "ChestCard.h"
#include "KeyCard.h"
#include "SwordCard.h"
#include "HookCard.h"
#include "OracleCard.h"
#include "MapCard.h"
#include "KrakenCard.h"
#include <iostream>
#include <algorithm>
#include <random>


// Constructor
Game::Game() : _turn(1), _round(1), _currentPlayer(0), _players{ nullptr, nullptr } {
    //heap allocated players
    _players[0] = new Player();
    _players[1] = new Player();
    createDeck();
    shuffleDeck();
}

// Destructor - manually frees heap - allocated players and card
Game::~Game() {
    delete _players[0];
    delete _players[1];
    for (Card* card : _deck) {
        delete card;
    }
    for (Card* card : _discard) {
        delete card;
    }
}

void Game::createDeck() {
    //creates all card except mermaid 
    for (int i = 2; i <= 7; i++) {
        _deck.push_back(new CannonCard(i));
        _deck.push_back(new ChestCard(i));
        _deck.push_back(new KeyCard(i));
        _deck.push_back(new SwordCard(i));
        _deck.push_back(new HookCard(i));
        _deck.push_back(new OracleCard(i));
        _deck.push_back(new MapCard(i));
        _deck.push_back(new KrakenCard(i));
    }
    //Mermaid card (value 4 - 9)
    for (int i = 4; i <= 9; i++) {
        _deck.push_back(new MermaidCard(i));
    }
}

void Game::shuffleDeck() {
    CardCollection shuffled{ _deck.begin(), _deck.end() };
    std::shuffle(shuffled.begin(), shuffled.end(), std::mt19937{ std::random_device{}() });
    std::copy(shuffled.begin(), shuffled.end(), _deck.begin());
}

