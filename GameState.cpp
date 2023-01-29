#include "GameState.h"
#include "fstream"
#include "iostream"

GameState::GameState() {}

GameState::GameState(Players players, GameBoard board, Tiles tiles)
{
    this->players = players;
    this->gameBoard = gameBoard;
    this->tiles = tiles;
}

Players GameState::getPlayers()
{
    return this->players;
}

GameBoard GameState::getBoard()
{
    return this->gameBoard;
}

Tiles GameState::getTiles()
{
    return this->tiles;
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
        file << players.getPlayer(1).getName() << std::endl;
        file << players.getPlayer(1).getScore() << std::endl;
        file << players.getPlayer(1).getHand() << std::endl;

        // Write player 2 information
        file << players.getPlayer(2).getName() << std::endl;
        file << players.getPlayer(2).getScore() << std::endl;
        file << players.getPlayer(2).getHand() << std::endl;

        /* UNCOMMENT TO CONTINUE BOARD IMPLEMENTATION */

        // Write board information
        file << gameBoard.getHeight() << "," << gameBoard.getWidth() << std::endl;

        // May need to print with loop: file << gameBoard.getState() << std::endl;

        // // Write tile bag contents
        // file << tiles.getContents() << std::endl;

        // Write current players name.
        file << currentPlayer.getName() << std::endl;

        file.close();
    }
}