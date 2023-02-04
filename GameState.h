#ifndef ASSIGN2_GAMESTATEE_H
#define ASSIGN2_GAMESTATEE_H

#include "Player.h"
#include "GameBoard.h"
#include "TileBag.h"

class GameState
{

private:
    Players players;

    GameBoard gameBoard;

    Tiles tiles;

    Player currentPlayer;

public:
    // Constructor
    GameState(Player player1, Player player2, GameBoard board, Tiles tiles, Player currentPlayer);

    // Save the game state to a file
    void save(std::string filename);

    // Load the game state from a file
    void load(std::string filename);

private:
    Player player1;
    Player player2;
    GameBoard gameBoard;
    TileBag *tileBag;
    Player currentPlayer;
};

#endif // ASSIGN2_GAMESTATEE_H