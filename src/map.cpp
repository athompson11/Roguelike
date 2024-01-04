#include "map.h"
#include "rooms.h"
#include "rng.h"
#include <ncurses.h>

void Map::generateMap() {
    int minRooms = 6;
    bool notPlaced = true;
    int xPosition = 0;
    int yPosition = 0;
    Room *newRoom = nullptr;

    for (int i = 0; i < minRooms; i++) {
        if (newRoom != nullptr) {
            delete newRoom;
        }
        newRoom = new Room();

        while (notPlaced) {
            xPosition = RNG::generate(1, this->getMapWidth() - newRoom->getRoomWidth() - 2);
            yPosition = RNG::generate(1, this->getMapHeight() - newRoom->getRoomHeight() - 2);

            bool validLocation = true;
            for (int j = yPosition-1; j < newRoom->getRoomHeight()+1 + yPosition; j++) {
                for (int k = xPosition-1; k < newRoom->getRoomWidth()+1 + xPosition; k++) {
                    if (this->map[j][k] != nullptr) {
                        validLocation = false;
                        goto invalidLocation;
                    }
                }
            }
            notPlaced = false;  // Room placement successful
            for (int j = yPosition; j < yPosition + newRoom->getRoomHeight() + 2; j++) {
                for (int k = xPosition; k < xPosition + newRoom->getRoomWidth() + 2; k++) {
                     // Check if the current position (j, k) is on the perimeter
                Tile *newTile;
                bool isOnPerimeter = (j == yPosition) ||  // Top edge
                                     (j == yPosition + newRoom->getRoomHeight() + 1) ||  // Bottom edge
                                     (k == xPosition) ||  // Left edge
                                     (k == xPosition + newRoom->getRoomWidth() + 1);  // Right edge

                if (isOnPerimeter) {
                    newTile = new Wall();
                } else {
                    newTile = new Floor();
                    }
                this->map[j][k] = newTile->clone();
                        }
                    }

            mvprintw(0, 0, "Placed room %d at position (%d, %d)", i, xPosition, yPosition);
            refresh();

            invalidLocation:
            if (!validLocation) {
                mvprintw(1, 0, "Failed to place room %d at position (%d, %d)", i, xPosition, yPosition);
                refresh();
            }
        }

        notPlaced = true;  // Reset for the next room
    }
}
