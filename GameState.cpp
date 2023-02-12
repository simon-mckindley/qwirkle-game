#include "GameState.h"
#include "fstream"
#include "iostream"
#include "TileBag.h"
#include "Player.h"

GameState::GameState(Players *players, GameBoard *gameBoard, TileBag *tileBag)
{
    this->players = players;
    this->gameBoard = gameBoard;
    this->tileBag = tileBag;
}

// Default GameState, used for loading game
// GameState::GameState()
// {
//     TileBag *tileBag = new TileBag();
//     tileBag->fillTileBag();

//     Player *player1 = new Player("", tileBag);
//     Player *player2 = new Player("", tileBag);

//     GameBoard *gameBoard = new GameBoard();

//     this->player1 = player1;
//     this->player2 = player2;
//     this->gameBoard = gameBoard;
//     this->tileBag = tileBag;
//     this->currentPlayer = this->player1;
// }

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
        file << players->getPlayer(0)->getName() << std::endl;
        file << players->getPlayer(0)->getScore() << std::endl;
        file << players->getPlayer(0)->getHand() << std::endl;

        // Write player 2 information
        file << players->getPlayer(1)->getName() << std::endl;
        file << players->getPlayer(1)->getScore() << std::endl;
        file << players->getPlayer(1)->getHand() << std::endl;

        // Write board information
        file << gameBoard->getHeight() << "," << gameBoard->getWidth() << std::endl;
        file << gameBoard->getState() << std::endl;

        // Write tile bag contents
        file << tileBag->printBag() << std::endl;

        // Write current players name
        file << players->getCurrentPlayer()->getName() << std::endl;

        file.close();

        std::cout << "\nGame saved successfully to " << filename << "\n"
                  << std::endl;
    }
}

// Takes a filepath to an existing file, reads file to construct GameState and
// returns GameState
void GameState::load(std::string filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cout << "Error: File Not Found." << std::endl;
        return;
    }

    // Read player 1 information
    std::string player1Name;
    int player1Score;
    std::string player1Hand;

    std::getline(file, player1Name);
    file >> player1Score;
    std::getline(file, player1Hand);

    // Read player 2 information
    std::string player2Name;
    int player2Score;
    std::string player2Hand;

    std::getline(file, player2Name);
    file >> player2Score;
    std::getline(file, player2Hand);

    // Hard-code the board height and width.
    int boardDimension = 26;

    // Read board information
    std::string boardState;
    std::getline(file, boardState);

    // Read tile bag contents
    std::string tileBag;
    std::getline(file, tileBag);

    // Read current player name
    std::string currentPlayerName;
    std::getline(file, currentPlayerName);

    file.close();

    // Use the read information to update the current game state
    // player1->setName(player1Name);
    // player1->setScore(player1Score);
    // player1->setHand(player1Hand);

    // player2->setName(player2Name);
    // player2->setScore(player2Score);
    // player2->setHand(player2Hand);

    gameBoard->setHeight(boardDimension);
    gameBoard->setWidth(boardDimension);
    gameBoard->setState(boardState);

    // tile.setTiles(tileBag);

    // currentPlayer->setName(currentPlayerName);

    std::cout << "Game loaded successfully" << std::endl;
}

GameBoard *GameState::getGameBoard()
{
    return gameBoard;
}

TileBag *GameState::getTileBag()
{
    return tileBag;
}