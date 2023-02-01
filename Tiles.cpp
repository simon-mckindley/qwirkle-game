#include "Tiles.h"

// Default constructor
Tiles::Tiles()
{
    // TODO
}

void Tiles::addTile(Tile newTile)
{
    // TODO
}

void Tiles::removeTile(Tile tile)
{
    // TODO
}

std::string Tiles::getTiles()
{
    std::string tileAsString;
    for (int i = 0; i < tiles.getSize(); i++)
    {
        Tile *tile = tiles.getTileAtIndex(i);
        tileAsString += tile->getColour();
        tileAsString += std::to_string(tile->getShape());
        tileAsString += ", ";
    }
    return tileAsString;
}