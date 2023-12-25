class Room {
    protected:
        std::string message = "";
        int topLeftX;
        int topLeftY;
        int bottomRightX;
        int bottomRightY;
        int goldSpent = 0;
    public:
        Room(std::string message, int topLeftX, int topLeftY, int bottomRightX, int bottomRightY)
        : message(message), topLeftX(topLeftX), topLeftY(topLeftY), bottomRightX(bottomRightX), bottomRightY(bottomRightY) {}

        virtual ~Room() {}
};