#include "Tile.h"
#include <iostream>

Tile::Tile()
{
    this->setColour(generateRandomisedColour());
    this->setShape(generateRandomisedShape());
}

Tile::Tile(Colour colour, Shape shape) : colour(colour), shape(shape) {}

Colour Tile::generateRandomisedColour()
{
    Colour colours[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
    int randomIndex = rand() % 6;

    return colours[randomIndex];
}

Shape Tile::generateRandomisedShape()
{
    Shape shapes[6] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER};
    int randomIndex = rand() % 6;

    return shapes[randomIndex];
}
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