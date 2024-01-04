#include "rng.h"

RNG::RNG()
{
    //
}

int RNG::generate(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}

int RNG::coinflip(){
    return RNG::generate(0,1);
}