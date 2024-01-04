#ifndef ROOM_H
#define ROOM_H
class Room {
    protected:
        std::string message = "";
        int topLeftX;
        int topLeftY;
        int goldSpent = 0;
        int roomWidth = 5;
        int roomHeight = 5;
    public:
        Room(std::string message="", int topLeftX=0, int topLeftY=0)
        : message(message), topLeftX(topLeftX), topLeftY(topLeftY) {}
        int getRoomWidth(){
            return roomWidth;
        }
        int getRoomHeight(){
            return roomHeight;
        }
        virtual ~Room() {}
};
#endif