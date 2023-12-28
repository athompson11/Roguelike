#ifndef GAME_H
#define GAME_H
#include "map.h"
#include "render.h"
#include "rng.h"

class Game {
    protected:
        Renderer *renderer = nullptr;
        Map *maps = nullptr;
        Map *currentMap = nullptr;
        RNG *rng = nullptr;
    public:
        Game(Renderer *renderer)
        : renderer(renderer){};
        Game(){};
        void init();
        void mainLoop();
        void handleTurn();
    };
#endif