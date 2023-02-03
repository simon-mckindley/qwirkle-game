#include "Tile.h"
#include "TileBag.h"
#include <iostream>

TileBag::TileBag()
{
    std::cout << "Creating Tile Bag..." << std::endl;
    setHead(nullptr);
    setTail(nullptr);
}

TileBag *TileBag::
    fillTileBag()
{
    std::cout << "Filling Tile Bag..." << std::endl;

    for (int i = 0; i < MAX_BAG_SIZE; i++)
    {
        Tile *newTile = new Tile();
        this->addTileToBag(newTile);
        this->setSize(this->getSize() + 1);
    }

    return this;
}

// Add a tile to the back of the list. Update pointer.
void TileBag::addTileToBag(Tile *tile)
{
    Node *node = new Node(tile, nullptr);
    if (this->getSize() == 0)
    {
        setHead(node);
        setTail(node);
    }
    else
    {
        getTail()->next = node;
        setTail(node);
    }
}

// Remove and return the tile chosen by the player.
Tile *TileBag::replaceTile(Tile *tileToReplace)
{
    // Put the old tile back in the tile bag
    addTileToBag(tileToReplace);
    // Draw a new tile from the tile bag
    Tile *newTile = this->drawTile();

    // Return the new tile
    return newTile;
}