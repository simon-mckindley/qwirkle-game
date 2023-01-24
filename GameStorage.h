#ifndef ASSIGN2_GAMESTORAGE_H
#define ASSIGN2_GAMESTORAGE_H

// #include "Tiles.h"
#include <string>
#include "Players.h"
#include "GameBoard.h"
#include "TilesBag.h"

class GameStorage
{
    public:
        bool SaveGame(Players players, GameBoard gameBoard, TilesBag bag);

};

#endif // ASSIGN2_GAMESTORAGE_H