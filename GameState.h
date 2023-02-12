#ifndef ASSIGN2_GAMESTATEE_H
#define ASSIGN2_GAMESTATEE_H

#include "Player.h"
#include "Players.h"
#include "Tiles.h"
#include "GameBoard.h"
#include "TileBag.h"

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
    // GameState(Player *player1, Player *player2, GameBoard *board, Tiles tiles, Player *currentPlayer);

    // Save the game state to a file
    void save(std::string filename);

    // Load the game state from a file
    void load(std::string filename);

    Players *getPlayers() { return players; };
    GameBoard *getGameBoard();
    TileBag *getTileBag();
};

#endif // ASSIGN2_GAMESTATEE_H