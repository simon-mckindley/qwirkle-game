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

    // bool validateChoice(std::string input, std::string location, GameState gameState);

    bool placeTile(std::string location, std::string tile);

    bool replaceTile(std::string tile);

    // Prints the game status at the start of each players turn
    void printGameStatus();

    // Gets and validates user gameplay input
    bool gamePlayOption();

    GameState getGameState() { return *gameState; };

    // Gets all the tiles of a row left of coordinates
    // vector<Tile> getSetDirection(int x, int y, bool);

    // Accepts and validates player names
    std::string getPlayerName();

    bool firstTurn = true; // TODO: Using this to track first turn is really clunky, change this in future

public:
    // Constructor
    // GamePlay();

    void createNewGame();

    void loadGame();

};

#endif // ASSIGN2_GAMEPLAY_H