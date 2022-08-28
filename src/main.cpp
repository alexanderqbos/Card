#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Cards.h"


int main()
{
    const int SAMPLES = 100000;
    // Seed randomize
    srand(static_cast<unsigned int>(time(0)));
    int numPicks = 0;
    // get card picks
    numPicks = getPickCountNeededForFourSuits();
    std::cout << numPicks << " picks.";
    // for(int i{0}; i < SAMPLES; i++)
    // {
    //     numPicks += getPickCountNeededForFourSuits(false);
    // }
    // std::cout << static_cast<double>(numPicks) / SAMPLES << " average picks per " << SAMPLES << ".";
}