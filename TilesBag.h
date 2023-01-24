#ifndef ASSIGN2_TILESBAG_H
#define ASSIGN2_TILESBAG_H

#include "Tiles.h"

class TilesBag extends Tiles
{

    public:

        // Default constructor
        TilesBag();

        // Should only be called once at the start of a
        // new game
        //
        // TODO: Depending on how newGame() is implemented
        // this may be redundant
        void shuffleTiles();


};

#endif // ASSIGN2_TILESBAG_H