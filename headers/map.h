#ifndef MAP_H
#define MAP_H
#include "tiles.h"
#include "rooms.h"
#include <string>
#include <algorithm>
class Map {
    protected:
        std::string name;
        int mapID;
        Tile map[20][80];
        Map *above = nullptr;
        Map *below = nullptr;
    public:
        Map(std::string name, Tile newMap[20][80])
        : name(name) {
            for (int i = 0; i < 20; ++i) {
                std::copy(newMap[i], newMap[i] + 80, map[i]);
            }
        }
        void generateMap(int budget){};

        virtual ~Map() {}
};
#endif