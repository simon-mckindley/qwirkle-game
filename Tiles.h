#ifndef ASSIGN2_TILES_H
#define ASSIGN2_TILES_H

#include "LinkedList.h"
#include "Tile.h"
#include <string>

class Tiles
{
private:
    LinkedList tiles;

public:
    // Default constructor
    Tiles();

    // Constructor for loadGame function()
    // May need refactoring when implementing loadGame()
    Tiles(LinkedList tiles);

    // Add Tile to the Tiles object
    void addTile(Tile tile);

    // Remove a tile from the tiles object
    // Must retain order of list
    //
    // TODO: If we need to retain the order of the list, and
    // we have duplicates of a tile, does it matter which of
    // the duplicates is removed from the list? Unsure.
    void removeTile(Tile tile);

    // Read the current tile bag for saving game state.
    std::string getTiles();
};

#endif // ASSIGN2_TILES_H