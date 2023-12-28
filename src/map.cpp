#include "map.h"
#include "rooms.h"
#include "rng.h"
void Map::generateMap(){
    int minRooms = 4;
    bool gaveDownStairs = false;
    bool notPlaced = true;
    int xPosition = 0;
    int yPosition = 0;
    Room *newRoom = nullptr;
    for (int i=0; i<minRooms;i++){
        if (newRoom != nullptr){
            delete newRoom;
        }
        newRoom = new Room();
        while (notPlaced){
            xPosition = RNG::generate(1, this->getMapWidth() - newRoom->getRoomWidth() - 1);
            yPosition = RNG::generate(1, this->getMapHeight() - newRoom->getRoomHeight() - 1);

            for (int j=yPosition;j<newRoom->getRoomHeight()+yPosition;j++){
                for (int k=xPosition;k<newRoom->getRoomWidth()+xPosition;k++){
                    if (this->map[j][k] != nullptr){
                        goto invalidLocation;
                    }
                }
            }
            //If we're here, we're good to go
            for (int j = yPosition - 1; j <= yPosition + newRoom->getRoomHeight(); j++) {
                for (int k = xPosition - 1; k <= xPosition + newRoom->getRoomWidth(); k++) {
                // Check if the current position (j, k) is on the perimeter
                Tile *newTile;
                bool isOnPerimeter = (j == yPosition - 1) ||  // Top edge
                                    (j == yPosition + newRoom->getRoomHeight()) ||  // Bottom edge
                                    (k == xPosition - 1) ||  // Left edge
                                    (k == xPosition + newRoom->getRoomWidth());  // Right edge

                    if (isOnPerimeter) {
                        newTile = new Wall();
                        this->map[j][k] = newTile->clone();
                    } else {
                        newTile = new Floor();
                        this->map[j][k] = newTile->clone();
                        }
                    }
                }
                invalidLocation:
                ;
            
            }
        }
        notPlaced = true;
    }