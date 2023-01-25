#ifndef ASSIGN2_GAMESTATEE_H
#define ASSIGN2_GAMESTATEE_H

#include <string>
#include "Players.h"
#include "GameBoard.h"

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
        GameState() {
            
            // TODO: Initalize with default values

        }

        // Constructor for loadGame method
        GameState(Players players, GameBoard gameBoard, Tiles bag);

        bool saveGame(std::string filepath);

        GameState loadGame(std::string filepath);

    

};

#endif // ASSIGN2_GAMESTATEE_H