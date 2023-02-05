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

    bool validateChoice(std::string input, std::string location, GameState gameState);

    bool firstTurn = true; // TODO: Using this to track first turn is really clunky, change this in future

public:
    // Constructor
    // GamePlay();

    void createNewGame();

    void loadGame();

    // Main gameplay function
    void gamePlay();

    // Prints the game status at the start of each players turn
    void printGameStatus();

    // Gets and validates user gameplay input
    bool gamePlayOption();

    GameState getGameState() { return *gameState; };

    // Gets all the tiles of a row left of coordinates
    vector<Tile> getSetDirection(int x, int y, bool);

    // Accepts and validates player names
    std::string getPlayerName();
};

#endif // ASSIGN2_GAMEPLAY_H