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
    Player *currentPlayer;

    // Main gameplay function
    void gamePlay();

    // Place the tile on the board
    bool placeTile(std::string location, std::string tile);

    // Replace a tile in the players hand
    bool replaceTile(std::string tile);

    // Checks if the players hand is empty, which is the end of the game
    bool checkEndGame();

    // Prints the game status at the start of each players turn
    void printGameStatus();

    // Prints the results at the end of a game
    void printEndGame();

    // Gets and validates user gameplay input
    bool gamePlayOption();

    bool aiPlayOption();

    // Validates and returns the number of players
    int validatePlayerNum();

    // Accepts and validates player names
    std::string getPlayerName();

    bool firstTurn = true;

public:
    // Creates and starts a new Qwirkle game
    void createNewGame();

    // Creates and starts a new Qwirkle game with AI player
    void createAIGame();

    // Loads a Qwirkle game from the specified file
    void loadGame();
};

#endif // ASSIGN2_GAMEPLAY_H