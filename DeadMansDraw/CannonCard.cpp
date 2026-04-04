#include "CannonCard.h"
#include <iostream>

std::string CannonCard::str() const {
    return "Cannon(" + std::to_string(_value) + ")"; 
}

void CannonCard::play(Game &game , Player& player)  {
    //pseudocode - code todo 
    //1.get the other player (opponent) 
    //2.get opponent's bank 
    //3. check if bank empty (return if empty) 
    //4. else find highest card per suit in opponent's bank : 
    //i. for each card in bank: if suit not seen before add to list ii. if seen and card value is higher -> update highest 
    //5. Print the list of highest card in according to suits 
    //6. ask player for number (validation)_ and get choosen card
    //7. print the discarded
    //8. remove chosen card from opponent's bank 
    //9. add chosen card to discard pile 
}