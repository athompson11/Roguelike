#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "map.h"
#include <queue>

struct Step {
    int x;
    int y;
};

class Route {
public:
    Route();
    ~Route();

    Route(const Route& other);
    Route& operator=(const Route& other);

    // Methods
    void addStep(int x, int y);   // Add a step to the route
    bool isEmpty() const;         // Check if the route is empty
    Step getNextStep();           // Get the next step in the route
    void clear();                 // Clear the route

protected:
    std::queue<Step> stepsInRoute; // Queue to store the steps in the route
};

Route* findRouteToPointFromPoint(Map *map, int originPointX, int originPointY, int destinationPointX, int destinationPointY);

#endif // PATHFINDING_H
