#ifndef ASSIGN2_GAMEPLAY_H
#define ASSIGN2_GAMEPLAY_H

#include "GamePlay.h"
#include "GameState.h"
#include "Tile.h"
#include "TileCodes.h"
#include "UserPrompt.h"

class GamePlay
{
private:
    GameState *gameState;

    // Main gameplay function
    void gamePlay();

    // Place the tile on the board
    bool placeTile(std::string location, std::string tile);

    // Replace a tile in the players hand
    bool replaceTile(std::string tile);

    // Prints the game status at the start of each players turn
    void printGameStatus();

    // Gets and validates user gameplay input
    bool gamePlayOption();

    // Accepts and validates player names
    std::string getPlayerName();

    bool firstTurn = true;

public:

    // Creates and starts a new Qwirkle game
    void createNewGame();

    // Loads a Qwirkle game from the specified file
    void loadGame();

};

#endif // ASSIGN2_GAMEPLAY_H