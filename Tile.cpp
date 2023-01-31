#include "Tile.h"

// TODO: X and 0 are placeholder values, should be replaced with a NULL
Tile::Tile() : colour('X'), shape(0) {}

Tile::Tile(Colour colour, Shape shape) : colour(colour), shape(shape) {}

Colour Tile::getColour()
{
    return colour;
}

Shape Tile::getShape()
{
    return shape;
}

void Tile::setColour(Colour colour)
{
    this->colour = colour;
}

void Tile::setShape(Shape shape)
{
    this->shape = shape;
}