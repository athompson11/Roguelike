#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "map.h"
#include "render.h"

class Game {
    protected:
        Player *player = nullptr;
        Renderer *renderer = nullptr;
        Map *maps = nullptr;
        Map *currentMap = nullptr;
    public:
        Game(Player *player, Renderer *renderer)
        : player(player), renderer(renderer){};
        Game(){};
        void init();
        void mainLoop();
    };
#endif