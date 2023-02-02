#ifndef ASSIGN2_GAMESTATE_H
#define ASSIGN2_GAMESTATE_H

#include "Players.h"
#include "GameBoard.h"
#include <string>
#include "Tiles.h"

class GameState
{

private:
    Players players;

    GameBoard gameBoard;

    Tiles tiles;

    Player currentPlayer;

public:
    // Default Constructor
    GameState();

    // Constructor
    GameState(Players players, GameBoard board, Tiles tiles);

    // Accessors
    Players getPlayers();

    GameBoard getBoard();

    Tiles getTiles();

    // Save the game state to a file
    void save(std::string filename);

    // Load the game state from a file
    void load(std::string filename);
};

#endif // ASSIGN2_GAMESTATE_H