#include "Hand.h"
#include "Node.h"
#include "Tile.h"
#include <iostream>

Hand::Hand(TileBag *tileBag)
{
    std::cout << "Assigning player hand..." << std::endl;

    for (int i = 0; i < HAND_SIZE; i++)
    {
        Tile *tile = tileBag->drawTile();
        this->addTileToBack(tile);
    }
}

Hand::~Hand()
{
}