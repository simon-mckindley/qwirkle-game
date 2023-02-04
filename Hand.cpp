#include "Hand.h"
#include "Node.h"
#include "Tile.h"
#include <iostream>

Hand::Hand(TileBag *tileBag)
{
    for (int i = 0; i < HAND_SIZE; i++)
    {
        Tile *tile = tileBag->drawTile();
        this->addTileToBack(tile);
    }
}

Hand::~Hand()
{
}