#include "rng.h"

std::random_device RNG::rd;
std::mt19937 RNG::rng(RNG::rd());

RNG::RNG()
{
    //
}

int RNG::generate(int min, int max)
{
    std::uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}

int RNG::coinflip(){
    return RNG::generate(0,1);
}