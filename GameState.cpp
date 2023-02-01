#include "GameState.h"
#include "fstream"
#include "iostream"

GameState::GameState(Player player1, Player player2, GameBoard board, Tiles tiles, Player currentPlayer)
{
    this->player1 = player1;
    this->player2 = player2;
    this->gameBoard = gameBoard;
    this->tiles = tiles;
    this->currentPlayer = currentPlayer;
}

void GameState::save(std::string filename)
{
    std::ofstream file(filename);

    if (!file)
    {
        std::cout << "Error: File Not Found." << std::endl;
    }
    else
    {
        // Write player 1 information
        file << player1.getName() << std::endl;
        file << player1.getScore() << std::endl;
        file << player1.getHand() << std::endl;

        // Write player 2 information
        file << player2.getName() << std::endl;
        file << player2.getScore() << std::endl;
        file << player2.getHand() << std::endl;

        // Write board information
        file << gameBoard.getHeight() << "," << gameBoard.getWidth() << std::endl;

        file << gameBoard.getState() << std::endl;

        // Write tile bag contents
        file << tiles.getTiles() << std::endl;

        // Write current players name.
        file << currentPlayer.getName() << std::endl;

        file.close();

        std::cout << "Game saved successfully" << std::endl;
    }
}

void GameState::load(std::string filename)
{
}