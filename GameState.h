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
    Player *player1;
    Player *player2;
    Player *currentPlayer;
    GameBoard *gameBoard;
    TileBag *tileBag;

public:
    // Constructor
    GameState(Player *player1, Player *player2, GameBoard *board, Tiles tiles, Player *currentPlayer);

    GameState(Players *players, GameBoard *gameBoard, TileBag *tileBag);

    GameState();

    // Save the game state to a file
    void save(std::string filename);

    // Load the game state from a file
    void load(std::string filename);

    Players *getPlayers() { return players; };

    void setPlayer1(Player player1);
    Player *getPlayer1();
    void setPlayer2(Player player2);
    Player *getPlayer2();
    GameBoard *getGameBoard();
    Player *getCurrentPlayer();
    TileBag *getTileBag();
};

#endif // ASSIGN2_GAMESTATEE_H