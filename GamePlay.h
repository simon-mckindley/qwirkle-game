#ifndef ASSIGN2_GAMEPLAY_H
#define ASSIGN2_GAMEPLAY_H

#include "GameState.h"
#include "UserPrompt.h"
#include "Players.h"

class GamePlay
{
private:
    GameState *gameState;

    bool validateChoice(std::string input, std::string location, GameState gameState);

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

    // Accepts and validates player names
    std::string getPlayerName();
};

#endif // ASSIGN2_GAMEPLAY_H