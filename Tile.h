#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include <iostream>
#include <string>
#include "TileCodes.h"

// Define a Colour type.
typedef char Colour;

// Define a shape type.
typedef int Shape;

class Tile
{
public:
    // Default Constructor
    Tile() {};

    // Constructor
    Tile(Colour colour, Shape shape);

    static Colour convertToColour(std::string colour);
    static Shape convertToShape(std::string shape);

    // Accessors
    Colour getColour();
    Shape getShape();
    Tile *getTile();
    Tile getTile(Colour colour, Shape shape);

    // Mutators
    void setColour(Colour colour);
    void setShape(Shape shape);
    void setTile(Tile *tile);

private:
    Colour colour;
    Shape shape;
};

#endif // ASSIGN2_TILE_H
