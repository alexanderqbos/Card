#include <iostream>
#include "Cards.h"
#include <cstdlib>

// pick a random card from the deck (return a random # between 0-51)
int pickRandomCard()
{
    return rand() % Constants::CARD_COUNT;
}
// return an enum representing the Rank of the card index given.
Rank getRank(int cardIndex)
{
    int rank = cardIndex % Constants::NUM_RANKS;
    return static_cast<Rank>(rank);
}
// return an enum representing the Suit of the card index given.
Suit getSuit(int cardIndex)
{
    int suit = cardIndex / Constants::NUM_RANKS;
    return static_cast<Suit>(suit);
}
// return true if all the Booleans in the given array are true, note we have to pass in the length since our array “decays” to a pointer.
bool allSuitsPicked(const bool suitsPicked[], int length)
{
    if(length < 3)
        return false;
    bool result = suitsPicked[0] && suitsPicked[1] && suitsPicked[2] && suitsPicked[3];
    return result;
}
// Return an int representing the number of card picks it takes to cover 4 suits.
// If verbose is true, generate output to show cards picked and the pick count.
// This is the function that does all the work behind solving the problem (including
// sending output to the console).
// This function should use an array of Boolean values to represent the suits that
// have been picked already, and make use of allSuitsPicked() to test if complete.
int getPickCountNeededForFourSuits(bool verbose)
{
    bool pickedSuits[]{false, false, false, false};
    int pickedSize = static_cast<int>(std::size(pickedSuits));

    int prevPickedSize = 0;

    int picks = 0;
    while(!allSuitsPicked(pickedSuits, pickedSize))
    {
        int pickedSuitCount = 0;
        int pick =  pickRandomCard();
        Suit pickSuit = getSuit(pick);
        Rank pickRank = getRank(pick);
        
        bool printPick = false;
        pickedSuits[static_cast<int>(pickSuit)] = true;
        for(int i = 0; i < 4; i++)
        {
            if(pickedSuits[i])
            {
                pickedSuitCount++;
            }
        }
        if(prevPickedSize < pickedSuitCount && verbose)
        {
            std::cout << Constants::RANKS[static_cast<int>(getRank(pick))] << " of " << Constants::SUITS[static_cast<int>(getSuit(pick))] << '\n';
        }
        picks++;
    }
    return picks;
}