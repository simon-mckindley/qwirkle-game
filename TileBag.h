#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H

#include "LinkedList.h"
#include "Tile.h"
#include "TileCodes.h"

// Define a Colour type.
typedef char Colour;
// Define a shape type.
typedef int Shape;

class TileBag : public LinkedList
{
public:
    // Default constructor
    TileBag();

    TileBag *fillTileBag();
    // void addTileToBag(Tile *tile);
    // void removeFromBag(int index);

    // Remove a tile from player hand and replace it with a new tile.
    Tile *replaceTile(Tile *tileToReplace);

    void printBag();

private:
    int getRandomDigit(int max);
};
#endif // ASSIGN2_TILEBAG_H