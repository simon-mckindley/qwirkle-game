#include "TileCodes.h"
#include "Tile.h"

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

Colour Tile::convertToColour(std::string colour)
{
    if (colour == "R")
    {
        return RED;
    }
    else if (colour == "O")
    {
        return ORANGE;
    }
    else if (colour == "Y")
    {
        return YELLOW;
    }
    else if (colour == "G")
    {
        return GREEN;
    }
    else if (colour == "B")
    {
        return BLUE;
    }
    else if (colour == "P")
    {
        return PURPLE;
    }
    else
    {
        return RED;
    }
}

Shape Tile::convertToShape(std::string shape)
{
    if (shape == "1")
    {
        return CIRCLE;
    }
    else if (shape == "2")
    {
        return STAR_4;
    }
    else if (shape == "3")
    {
        return DIAMOND;
    }
    else if (shape == "4")
    {
        return SQUARE;
    }
    else if (shape == "5")
    {
        return STAR_6;
    }
    else if (shape == "6")
    {
        return CLOVER;
    }
    else
    {
        return CIRCLE;
    }
}