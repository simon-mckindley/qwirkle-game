#include "Tile.h"

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

Colour Tile::convertToColour(std::string colour)
{
    Colour code = ' ';
    if (colour == "R")
    {
        code = RED;
    }
    else if (colour == "O")
    {
        code = ORANGE;
    }
    else if (colour == "Y")
    {
        code = YELLOW;
    }
    else if (colour == "G")
    {
        code = GREEN;
    }
    else if (colour == "B")
    {
        code = BLUE;
    }
    else if (colour == "P")
    {
        code = PURPLE;
    }

    return code;
}

Shape Tile::convertToShape(std::string shape)
{
    Shape code = ' ';
    if (shape == "1")
    {
        code = CIRCLE;
    }
    else if (shape == "2")
    {
        code = STAR_4;
    }
    else if (shape == "3")
    {
        code = DIAMOND;
    }
    else if (shape == "4")
    {
        code = SQUARE;
    }
    else if (shape == "5")
    {
        code = STAR_6;
    }
    else if (shape == "6")
    {
        code = CLOVER;
    }

    return code;
}