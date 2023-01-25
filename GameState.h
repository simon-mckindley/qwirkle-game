#ifndef ASSIGN2_GAMESTATEE_H
#define ASSIGN2_GAMESTATEE_H

#include <string>
#include "Players.h"
#include "GameBoard.h"

#include <iostream>
#include <fstream>

class GameState
{
private:
    // Elements required to save or load a game
    Players players;

    Tiles bag;

    GameBoard gameBoard;

    // The index of the active player (player who's turn it currently is)
    // within the players list
    int activePlayerIndex;

public:
    // Default constructor
    GameState()
    {

        // TODO: Initalize with default values
    }

    // Constructor for loadGame method
    GameState(Players players, GameBoard gameBoard, Tiles bag);

    // Setters
    void setPlayers(Players players);

    void setBag(Tiles bag);

    void setGameboard(GameBoard gameBoard);

    void setActivePlayerIndex(int activePlayerIndex);

    // Getters
    Players *getPlayers();

    Tiles *getBag();

    GameBoard *getGameboard();

    int *getActivePlayerIndex();

    // Saves this GameState object to a file in the specified gamepath
    bool saveGame(std::string filepath);

    // Takes a filepath and loads the file into a GameState object which can
    // be then be put into play.
    GameState loadGame(std::string filepath);
};

#endif // ASSIGN2_GAMESTATEE_H