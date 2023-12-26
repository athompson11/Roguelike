#ifndef TILE_H
#define TILE_H
#include <string>
class Tile {
protected:
    std::string tileID;
    std::string description;
    char symbol;
    bool isPassable;
    bool isDirty = false;
public:
    Tile(std::string id = "default", std::string desc = "You shouldn't be seeing this.", char sym = '*', bool isPassable = false)
        : tileID(id), description(desc), symbol(sym), isPassable(isPassable) {}

    virtual ~Tile() {}
};

class Wall : public Tile {
public:
    Wall() : Tile("wall", "A wall", '#', false) {}
};

class Floor : public Tile {
public:
    Floor() : Tile("floor", "The floor", '.', true) {}
};

class Door : public Tile {
    protected:
        bool isOpen;
    public:
        Door() : Tile("door", "A door", '+', false), isOpen(false) {}
        virtual ~Door() {}
        virtual void changeState();
};
#endif