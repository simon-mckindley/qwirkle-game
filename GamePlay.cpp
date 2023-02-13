#include "GamePlay.h"
#include "TileBag.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

// Main gameplay function
void GamePlay::gamePlay()
{
    bool endGame = false;
    currentPlayer = gameState->getPlayers()->getCurrentPlayer();

    do
    {
        std::cout << "\n******************************************\n"
                  << currentPlayer->getName() << ", it's your turn";
        printGameStatus();
        endGame = gamePlayOption();
        currentPlayer = gameState->getPlayers()->nextPlayer();

    } while (!endGame);

    delete gameState;
}

void GamePlay::createNewGame()
{
    std::cout << "\nStarting a new game." << std::endl;

    std::string player1name;
    std::string player2name;
    std::cout << "\nEnter a name for Player 1 (Uppercase characters only)" << std::endl;
    player1name = getPlayerName();
    std::cout << "\nEnter a name for Player 2 (Uppercase characters only)" << std::endl;
    player2name = getPlayerName();
    std::cout << "\nWelcome, " << player1name << " and " << player2name
              << "\n\tLets Play!" << std::endl;

    // player1name = "ONE";
    // player2name = "TWO";

    TileBag *tileBag = new TileBag();
    tileBag->fillTileBag();

    // Creates new players and allocate hands of tiles
    Player *player1 = new Player(player1name, tileBag);
    Player *player2 = new Player(player2name, tileBag);

    // Creates new Gamestate object for the pointer
    Players *players = new Players(player1, player2);
    GameBoard *gameBoard = new GameBoard();

    gameState = new GameState(players, gameBoard, tileBag);

    gamePlay();
}

void GamePlay::loadGame()
{
    std::cout << "\nLoad a saved game" << std::endl;

    std::string filename;
    std::cout << "\nEnter the filename from which to load a save game" << std::endl;
    filename = UserPrompt::getInput();
    std::cout << "\nLoading game from : " << filename << std::endl;

    gameState = new GameState();
    bool loaded = gameState->load(filename);

    if (loaded)
    {
        gamePlay();
    }
}

// Accepts and validates new player names
std::string GamePlay::getPlayerName()
{
    std::string name = "";
    bool valid;
    do
    {
        valid = true;
        name = UserPrompt::getInput();
        for (char c : name)
        {
            if (!isupper(c))
            {
                valid = false;
                std::cout << "Invalid name format" << std::endl;
                break;
            }
        }

    } while (!valid);

    return name;
}

// Prints the game status at the start of each players turn
void GamePlay::printGameStatus()
{
    std::cout << "\nScore for "
              << gameState->getPlayers()->getPlayer(0)->getName()
              << ": " << gameState->getPlayers()->getPlayer(0)->getScore();
    std::cout << "\nScore for "
              << gameState->getPlayers()->getPlayer(1)->getName()
              << ": " << gameState->getPlayers()->getPlayer(1)->getScore();
    std::cout << "\nTiles left in Tile Bag: "
              << gameState->getTileBag()->getSize() << std::endl;
    std::cout << "\n"
              << gameState->getGameBoard()->toString() << std::endl;
    std::cout << "Your hand is:\n"
              << currentPlayer->getHand() << "\n"
              << std::endl;
}

// Prints the results at the end of a game
void GamePlay::printEndGame()
{
    int p1Score = gameState->getPlayers()->getPlayer(0)->getScore();
    int p2Score = gameState->getPlayers()->getPlayer(1)->getScore();
    std::string winner = "";

    std::cout << "\n\tGAME OVER"
              << "\nScore for "
              << gameState->getPlayers()->getPlayer(0)->getName()
              << ": " << p1Score;
    std::cout << "\nScore for "
              << gameState->getPlayers()->getPlayer(1)->getName()
              << ": " << p2Score
              << std::endl;

    if (p1Score == p2Score)
    {
        std::cout << "The game is a tie!\n"
                  << std::endl;
        return;
    }
    else if (p1Score > p2Score)
    {
        winner = gameState->getPlayers()->getPlayer(0)->getName();
    }
    else if (p2Score > p1Score)
    {
        winner = gameState->getPlayers()->getPlayer(1)->getName();
    }

    std::cout << "Player "
              << winner
              << " has won!\n"
              << std::endl;
}

// Gets and validates user gameplay input
bool GamePlay::gamePlayOption()
{
    bool invalid;
    bool endGame = false;
    std::string userInput;
    do
    {
        invalid = false;

        std::cout << currentPlayer->getName()
                  << " - What would you like to do?\n"
                  << "\tplace <tile> at <location>\n"
                  << "\treplace <tile>\n"
                  << "\tsave <filename>\n"
                  << "\tquit" << std::endl;

        userInput = UserPrompt::getInput();
        int length = userInput.length();

        std::string::size_type pos = userInput.find_first_of(" ");

        // If input contains a space character
        if (pos != std::string::npos)
        {
            // The input before the space
            std::string cmd = userInput.substr(0, pos);

            /* Valid commands:
            "place XX at XX (length=14),
            "place XX at XXX (length=15),
            "replace XX" (length=10), "save <filename>" (min_length=7) */
            if (cmd == "place" && length >= 14)
            {
                std::string tile = userInput.substr(pos + 1, 2);
                std::string location = userInput.substr(pos + 7);
                std::cout << "Tile: " << tile << "  Place: " << location << std::endl;
                invalid = placeTile(location, tile);
            }
            else if (cmd == "replace" && length == 10)
            {
                std::string tile = userInput.substr(pos + 1, 2);
                std::cout << "Replace:" << tile << std::endl;
                invalid = replaceTile(tile);
            }
            else if (cmd == "save" && length >= 7)
            {
                std::string fileName = userInput.substr(pos + 1);
                std::cout << "Saving game to: " << fileName << std::endl;
                gameState->save(fileName);
                invalid = true;
            }
            else
            {
                std::cout << "\n*** Invalid input ***\n"
                          << std::endl;
                invalid = true;
            }
        }
        else if (userInput == "quit")
        {
            std::cout << "\nQuiting game" << std::endl;
            return true;
        }
        else
        {
            std::cout << "\n*** Invalid input ***\n"
                      << std::endl;
            invalid = true;
        }

    } while (invalid);

    endGame = checkEndGame();
    if (endGame)
    {
        printEndGame();
    }

    return endGame;
}

// Validates tile and placement location, then places tile and updates gameState
bool GamePlay::placeTile(std::string location, std::string tile)
{
    bool invalid = false;
    std::string x = location.substr(0, 1);
    std::string y = location.substr(1);
    std::string userSelectionTileColour = tile.substr(0, 1);
    std::string userSelectionTileShape = tile.substr(1, 1);

    Colour colour = Tile::convertToColour(userSelectionTileColour);
    Shape shape = Tile::convertToShape(userSelectionTileShape);
    Tile *tempTile = new Tile(colour, shape);

    if (this->currentPlayer->getHandPtr()->isTileInList(tempTile))
    {
        Tile tilePtr = this->currentPlayer->getHandPtr()->getHead()->getTileByAttributes(colour, shape);
        char xChar = x[0];
        int xCoordinate = GameBoard::alphabetToNumber(xChar);
        try
        {
            int yCoordinate = stoi(y) - 1;

            if (this->gameState->getGameBoard()->validateSetTile(xCoordinate, yCoordinate, *tempTile, this->firstTurn))
            {
                this->firstTurn = false;
                int score = this->gameState->getGameBoard()->setTile(xCoordinate, yCoordinate, tilePtr);
                this->currentPlayer->addScore(score);
                std::cout << "Score for this placement: " << score << std::endl;

                Node *nodeToRemove = this->currentPlayer->getHandPtr()->getNode(tilePtr);
                this->currentPlayer->getHandPtr()->removeItemFromList(nodeToRemove);
                Tile *newTile = this->gameState->getTileBag()->drawTile();
                if (newTile != nullptr)
                {
                    this->currentPlayer->getHandPtr()->addTileToBack(newTile);
                }
            }
            else
            {
                invalid = true;
            }
        }
        catch (std::invalid_argument arg)
        {
            std::cout << "Invalid location" << std::endl;
            invalid = true;
        }
    }
    else
    {
        std::cout << "Invalid tile" << std::endl;
        invalid = true;
    }

    delete tempTile;

    return invalid;
}

// Validates the tile, puts it back in the tilebag and replaces it with a newly drawn tile
bool GamePlay::replaceTile(std::string tile)
{
    bool invalid = false;
    std::string userSelectionTileColour = tile.substr(0, 1);
    std::string userSelectionTileShape = tile.substr(1, 1);

    Colour colour = Tile::convertToColour(userSelectionTileColour);
    Shape shape = Tile::convertToShape(userSelectionTileShape);
    Tile *tempTile = new Tile(colour, shape);

    if (this->gameState->getTileBag()->getSize() == 0)
    {
        std::cout << "\n*** The tile bag is empty ***\n"
                  << std::endl;
        invalid = true;
    }
    else if (this->currentPlayer->getHandPtr()->isTileInList(tempTile))
    {
        Tile tilePtr = this->currentPlayer->getHandPtr()->getHead()->getTileByAttributes(colour, shape);
        Node *nodeToRemove = this->currentPlayer->getHandPtr()->getNode(tilePtr);
        this->currentPlayer->getHandPtr()->removeItemFromList(nodeToRemove);
        this->currentPlayer->getHandPtr()->addTileToBack(this->gameState->getTileBag()->replaceTile(&tilePtr));
    }
    else
    {
        std::cout << "\n*** No such tile in your hand ***\n"
                  << std::endl;
        invalid = true;
    }

    delete tempTile;

    return invalid;
}

// Checks if the players hand is empty - endgame
bool GamePlay::checkEndGame()
{
    if (this->currentPlayer->getHandPtr()->getSize() > 0)
    {
        return false;
    }

    return true;
}
