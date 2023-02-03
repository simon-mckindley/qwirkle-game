#ifndef ASSIGN2_GAMESTATE_H
#define ASSIGN2_GAMESTATE_H

#include "Players.h"
#include "GameBoard.h"
#include "TileBag.h"

class GameState
{
public:
    // Default Constructor
    GameState();
    // Constructor
    GameState(Players players, GameBoard board, TileBag *tileBag);

    Players getPlayers();
    GameBoard getBoard();
    TileBag *getTileBag();

    // Save the game state to a file
    void save(std::string filename);

    // Load the game state from a file
    void load(std::string filename);

private:
    Players players;
    GameBoard gameBoard;
    TileBag *tileBag;
    Player currentPlayer;
};

#endif // ASSIGN2_GAMESTATE_H