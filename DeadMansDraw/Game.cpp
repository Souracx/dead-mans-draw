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

static const int MAX_TURNS = 20;

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

//Draws and remove the top card from the deck 
Card* Game::drawCard() {
    if (_deck.empty()) return nullptr; 
    Card* card = _deck.back(); 
    _deck.pop_back(); 
    return card; 
}

//Draws and remove from the discard pile
Card* Game::drawFromDiscard() {
    if (_discard.empty()) return nullptr; 
    Card* card = _discard.back(); 
    _discard.pop_back(); 
    return card; 
}

//Returns a reference to the current player
Player& Game::getCurrentPlayer() {
    return *_players[_currentPlayer]; 
}

//Returns a reference to other Player 
Player& Game::getOtherPlayer(Player& player) {
    if (&player == _players[0]) {
        return *_players[1]; 
    }
    return *_players[0]; 
}

//Returns a reference to the deck
CardCollection& Game::getDeck() {
    return _deck; 
}

//Returns a reference to the discard pile 
CardCollection& Game::getDiscard() {
    return _discard; 
}

//Initialize and run the game loop until max turns or empty deck
void Game::startGame() {
    std::cout << GAME_TITLE << "\n"; 
    std::cout << "Starting Dead Man's Draw++!\n"; 
    //continue until max turn or deck is empty
    while (_turn <= MAX_TURNS && !_deck.empty()) {
        //calculate current round
        _round = (_turn + 1) / 2; 
        std::cout << "--- Round " << _round << ", Turn " << _turn << "---\n"; 
        playTurn(); 
        _turn++; 
    }
    endGame(); 
}

// Controls a single player's turn
void Game::playTurn() {
    Player& player = getCurrentPlayer();
    std::cout << player.getName() << "'s turn.\n";
    player.printBank();

    bool turnOver = false;

    while (!turnOver) {
        // check if deck is empty mid-turn
        if (_deck.empty()) {
            std::cout << "Deck is empty!\n";
            player.bankCards(*this);
            player.printBank();
            turnOver = true;
            break;
        }

        // draw a card from the deck
        Card* card = drawCard();
        std::cout << player.getName() << " draws a " << card->str() << "\n";

        // add card to play area, check if bust
        bool bust = player.playCard(card, *this);

        //check if bust happened inside a card ability
        if (!bust && player.getPlayArea().empty()) {
            turnOver = true; 
            break; 
        }

        if (bust) {
            // player busts, discard all cards in play area
            std::cout << "BUST! " << player.getName() << " loses all cards in play area.\n";
            player.discardPlayArea(*this);
            turnOver = true;
        }
        else {
            player.printPlayArea();

            // ask player if they want to draw again
            std::string input;
            //add input validation
            do {
                std::cout << "Draw again? (y/n): ";
                std::cin >> input;
            } while (input != "y" && input != "n"); 

            if (input != "y") {
                // player banks their cards
                player.bankCards(*this);
                player.printBank();
                turnOver = true;
            }
        }
    }

    // switch to other player
    _currentPlayer = 1 - _currentPlayer;
}

// Prints final scores and declares winner
void Game::printFinalScores() {
    std::cout << "--- Game Over ---\n";
    // print each player's bank
    for (int i = 0; i < 2; i++) {
        std::cout << _players[i]->getName() << "'s Bank:\n";
        _players[i]->printBank();
    }
    //winnner is determined
    int score0 = _players[0]->score();
    int score1 = _players[1]->score();
    if (score0 > score1)
        std::cout << _players[0]->getName() << " wins!\n";
    else if (score1 > score0)
        std::cout << _players[1]->getName() << " wins!\n";
    else
        std::cout << "It's a tie!\n";
}

// Ends the game
void Game::endGame() {
    printFinalScores();
}