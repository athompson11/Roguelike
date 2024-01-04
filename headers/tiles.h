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
    Tile(const Tile& otherTile) : tileID(otherTile.tileID), description(otherTile.description), symbol(otherTile.symbol), isPassable(otherTile.isPassable), isDirty(otherTile.isDirty){};
    virtual Tile* clone() const {
        return new Tile(*this);
    }
    virtual ~Tile() {}
    char getSymbol() const { return symbol; }
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
        Tile* clone() const override { 
            return new Door(*this); 
        }
        Door() : Tile("door", "A door", '+', false), isOpen(false) {}
        Door(const Door& otherDoor) : Tile(otherDoor), isOpen(otherDoor.isOpen) {};      
        virtual ~Door() {};
        virtual void changeState();
    };
#endif