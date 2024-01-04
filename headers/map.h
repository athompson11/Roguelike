#ifndef MAP_H
#define MAP_H
#include "tiles.h"
#include "rooms.h"
#include <string>
#include <algorithm>
class Map {
    protected:
        std::string name = "";
        int mapID;
        Tile *map[20][80];
        Map *above = nullptr;
        Map *below = nullptr;
        int MAP_HEIGHT = 20;
        int MAP_WIDTH = 80;
        int numRooms = 0;
        Room *rooms[];
    public:
        Map(std::string name, Tile *newMap[20][80])
        : name(name) {
            for(int i = 0; i < this->MAP_HEIGHT; i++){
                for(int j = 0; j < this->MAP_WIDTH; j++){
                    if (newMap[i][j] != nullptr) {
                        this->map[i][j] = newMap[i][j]->clone();
                    } else {
                        this->map[i][j] = nullptr;
                    }

                }
            }
        }
        Map(){};
        void generateMapBudget(int budget){};
        void generateMap();
        Tile* getMapTile(int y, int x){
            return this->map[y][x];
        }
        virtual ~Map() {
        for (int i = 0; i < MAP_HEIGHT; ++i) {
            for (int j = 0; j < MAP_WIDTH; ++j) {
                delete map[i][j];
                }
            }
        }
        int getMapHeight(){ return this->MAP_HEIGHT;}
        int getMapWidth(){ return this->MAP_WIDTH;}
};

#endif