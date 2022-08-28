// Put these constants, enums, and forward declarations in a Cards.h file
enum class Suit {
    SPADES,
    HEARTS,
    DIAMONDS,
    CLUBS
};
enum class Rank {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
}; 
namespace Constants {
    constexpr int CARD_COUNT{ 52 };
    constexpr int NUM_RANKS{ 13 };
    constexpr int NUM_SUITS{ 4 };
    // These string arrays will simplify the task of printing out the card values.
    // We don’t need to use a switch statement to find the string representation
    // of an enum. We can cast the enum as an int to index these arrays.
    const std::string SUITS[] {
        "Spades",
        "Hearts",
        "Diamonds",
        "Clubs"
    };
    const std::string RANKS[] {
        "Ace",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "10",
        "Jack",
        "Queen",
        "King"
    };
}
// FUNCTION PROTOTYPES
// pick a random card from the deck (return a random # between 0-51)
int pickRandomCard();
// return an enum representing the Rank of the card index given.
Rank getRank(int cardIndex);
// return an enum representing the Suit of the card index given.
Suit getSuit(int cardIndex);
// return true if all the Booleans in the given array are true, note we have to pass in the length since our array “decays” to a pointer.
bool allSuitsPicked(const bool suitsPicked[], int length);
// Return an int representing the number of card picks it takes to cover 4 suits.
// If verbose is true, generate output to show cards picked and the pick count.
// This is the function that does all the work behind solving the problem (including
// sending output to the console).
// This function should use an array of Boolean values to represent the suits that
// have been picked already, and make use of allSuitsPicked() to test if complete.
int getPickCountNeededForFourSuits(bool verbose = true);