#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H

#include "LinkedList.h"
#include "Tile.h"

class TileBag : public LinkedList
{

public:
    // Default constructor
    TileBag();

    TileBag *fillTileBag();
    void addTileToBag(Tile *tile);

    // Remove a tile from player hand and replace it with a new tile.
    Tile *replaceTile(Tile *tileToReplace);

    static const int MAX_BAG_SIZE = 10;
};
#endif // ASSIGN2_TILEBAG_H