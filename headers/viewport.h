#ifndef VIEWPORT_H
#define VIEWPORT_H
#include "./game.h"
class Viewport{
    protected:

    private:
        int sizeX = 20; //Tiles
        int sizeY = 15; //Tiles
        int locationX = 0;
        int locationY = 0;
    public:
        int getLocationX();
        int getLocationY();
        
};
#endif