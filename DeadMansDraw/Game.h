#pragma once
#include "Card.h"
#include "Player.h"

class Game {
private: 
    int _turn;  //current turn number
    int _round; //current round number 
    int _currentPlayer;  //index to track current player (0 or 1) 
    CardCollection _deck; //shared deck of cards
    CardCollection _discard; //shared discarded card piles 
    Player* _players[2]; //two player - dynamically allocated 

    void createDeck(); //creates 54 cards
    void shuffleDeck(); //shuffles the deck 

public: 
    Game(); //Constructor
    ~Game(); //Destructor  

    void startGame(); //initializes and starts the game 
    void playTurn(); //one player's turn 
    void endGame(); //ends the game 
    void printFinalScores(); //print final scores 

    Card* drawCard(); //Draw top card from deck 

    Player& getCurrentPlayer(); //return current player 
    Player& getOtherPlayer(Player& player); //return other player 

    CardCollection& getDeck();     //returns deck
    CardCollection& getDiscard();  //return discard pile 

};
