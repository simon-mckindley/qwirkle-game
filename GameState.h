#ifndef ASSIGN2_GAMESTATEE_H
#define ASSIGN2_GAMESTATEE_H

#include "Player.h"
#include "Players.h"
#include "Tiles.h"
#include "TileBag.h"
#include "GameBoard.h"
#include "fstream"
#include "iostream"

class GameState
{

private:
    Players *players;
    GameBoard *gameBoard;
    TileBag *tileBag;

public:
    // Default Constructor
    GameState(){};

    // New game constructor
    GameState(Players *players, GameBoard *gameBoard, TileBag *tileBag);

    // Save the game state to a file
    void save(std::string filename);

    // Load the game state from a file
    bool load(std::string filename);

    Players *getPlayers() { return players; };
    GameBoard *getGameBoard() { return gameBoard; };
    TileBag *getTileBag() { return tileBag; };
};

#endif // ASSIGN2_GAMESTATEE_H