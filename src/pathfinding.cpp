#include "pathfinding.h"

Route* findRouteToPointFromPoint(Map *map, int originX, int originY, int destX, int destY) {
    // Initialize data structures (costs, previous nodes, priority queue)
    // Add origin point to the queue with cost 0
    Route *routeToDestination;
    while (!queue.empty()) {
        // Dequeue the point with the lowest cost
        // If it's the destination, break the loop

        // For each neighbor of the dequeued point:
            // If moving to this neighbor is cheaper:
                // Update its cost
                // Update its previous node
                // Enqueue the neighbor
    }
    return routeToDestination;
    // Reconstruct and return the route from the destination to the origin
}
