#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H

#include <string>
#include "sstream"

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

    // Constructor from string list
    TileBag(std::string bagString);

    TileBag *fillTileBag();

    // Remove a tile from player hand and replace it with a new tile.
    Tile *replaceTile(Tile *tileToReplace);

    // Returns a comma separated string of the tile bag contents
    std::string printBag();

private:
    int getRandomDigit(int max);
};
#endif // ASSIGN2_TILEBAG_H