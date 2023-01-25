#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include "TileCodes.h"

// Define a Colour type.
typedef char Colour;

// Define a shape type.
typedef int Shape;

class Tile
{
public:
    // Default Constructor
    Tile();

    // Constructor
    Tile(Colour colour, Shape shape);

    // Accessors
    Colour getColour();
    Shape getShape();

    // Mutators
    void setColour(Colour colour);
    void setShape(Shape shape);

private:
    Colour colour;
    Shape shape;
};

#endif // ASSIGN2_TILE_H
