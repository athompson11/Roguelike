#ifndef RNG_H
#define RNG_H
#include <random>
#include <iostream>
class RNG{
    protected:
        static std::random_device rd; 
        static std::mt19937 rng;
    public:
        RNG();
        int static generate(int min, int max);
        int static coinflip();
};

#endif
