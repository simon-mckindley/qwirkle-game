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

    do
    {
        std::cout << "\n******************************************\n"
                  << gameState->getPlayers()->getCurrentPlayer()->getName() << ", it's your turn";
        printGameStatus();
        endGame = gamePlayOption();
        gameState->getPlayers()->nextPlayer();

    } while (!endGame);

    delete gameState;
}

void GamePlay::createNewGame()
{
    std::cout << "\nStarting a new game." << std::endl;

    std::string player1name;
    std::string player2name;
    // std::cout << "\nEnter a name for Player 1 (Uppercase characters only)" << std::endl;
    // player1name = getPlayerName();
    // std::cout << "\nEnter a name for Player 2 (Uppercase characters only)" << std::endl;
    // player2name = getPlayerName();
    // std::cout << "\nWelcome, " << player1name << " and " << player2name
    //           << "\n\tLets Play!" << std::endl;

    player1name = "ONE";
    player2name = "TWO";

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
    UserPrompt userPrompt;
    std::cout << "\nLoad a saved game" << std::endl;

    std::string filename;
    std::cout << "\nEnter the filename from which to load a save game" << std::endl;
    filename = userPrompt.getInput();
    std::cout << "\nLoading game from : " << filename << std::endl;

    gameState = new GameState();
    gameState->load(filename);

    gamePlay();
}

// Accepts and validates new player names
std::string GamePlay::getPlayerName()
{
    UserPrompt userPrompt;
    std::string name = "";
    bool valid;
    do
    {
        valid = true;
        name = userPrompt.getInput();
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
    gameState->getPlayers();
    std::cout
        << "\nScore for "
        << gameState->getPlayers()->getPlayer(0)->getName()
        << ": "
        << gameState->getPlayers()->getPlayer(0)->getScore();
    std::cout << "\nScore for "
              << gameState->getPlayers()->getPlayer(1)->getName()
              << ": "
              << gameState->getPlayers()->getPlayer(1)->getScore();
    std::cout << "\nTiles left in Tile Bag: " << gameState->getTileBag() << std::endl;
    std::cout << "\n\nBoard:" << std::endl;
    std::cout << gameState->getGameBoard()->toString() << std::endl;
    std::cout << "\nYour hand is:\n"
              << gameState->getPlayers()->getCurrentPlayer()->getHand() << "\n"
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
        UserPrompt userPrompt;

        std::cout << gameState->getPlayers()->getCurrentPlayer()->getName()
                  << " - What would you like to do?\n"
                  << "\tplace <tile> at <location>\n"
                  << "\treplace <tile>\n"
                  << "\tsave <filename>\n"
                  << "\tquit" << std::endl;

        userInput = userPrompt.getInput();
        int length = userInput.length();

        std::string::size_type pos = userInput.find_first_of(" ");

        // If input contains a space character
        if (pos != std::string::npos)
        {
            // The input before the space
            std::string cmd = userInput.substr(0, pos);

            // Valid commands:
            // "place XX at XX (length=14),
            // "place XX at XXX (length=15),
            // "replace XX" (length=10), "save <filename>" (min_length=7)
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
                // TODO validate tile
                gameState->getPlayers()->getCurrentPlayer()->getHand();
                invalid = replaceTile(tile);
            }
            else if (cmd == "save" && length >= 7)
            {
                std::string fileName = userInput.substr(pos + 1);
                std::cout << "Saving game to: " << fileName << std::endl;
                gameState->save(fileName);
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
            endGame = true;
            std::cout << "\nQuiting game" << std::endl;
        }
        else
        {
            std::cout << "\n*** Invalid input ***\n"
                      << std::endl;
            invalid = true;
        }

    } while (invalid);

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

    if (this->gameState->getPlayers()->getCurrentPlayer()->getHandPtr()->isTileInList(tempTile))
    {
        Tile tilePtr = this->gameState->getPlayers()->getCurrentPlayer()->getHandPtr()->getHead()->getTileByAttributes(colour, shape);
        char xChar = x[0];
        int xCoordinate = GameBoard::alphabetToNumber(xChar);
        int yCoordinate = stoi(y) - 1;
        if (this->gameState->getGameBoard()->validateSetTile(xCoordinate, yCoordinate, *tempTile, this->firstTurn))
        {
            this->firstTurn = false;
            int score = this->gameState->getGameBoard()->setTile(xCoordinate, yCoordinate, tilePtr);
            this->gameState->getPlayers()->getCurrentPlayer()->addScore(score);

            Node *nodeToRemove = this->gameState->getPlayers()->getCurrentPlayer()->getHandPtr()->getNode(tilePtr);
            this->gameState->getPlayers()->getCurrentPlayer()->getHandPtr()->removeItemFromList(nodeToRemove);
            this->gameState->getPlayers()->getCurrentPlayer()->getHandPtr()->addTileToBack(this->gameState->getTileBag()->drawTile());
        }
        else
        {
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

bool GamePlay::replaceTile(std::string tile)
{
    bool invalid = false;
    std::string userSelectionTileColour = tile.substr(0, 1);
    std::string userSelectionTileShape = tile.substr(1, 1);

    Colour colour = Tile::convertToColour(userSelectionTileColour);
    Shape shape = Tile::convertToShape(userSelectionTileShape);
    Tile *tempTile = new Tile(colour, shape);

    if (this->gameState->getPlayers()->getCurrentPlayer()->getHandPtr()->isTileInList(tempTile))
    {
        Tile tilePtr = this->gameState->getPlayers()->getCurrentPlayer()->getHandPtr()->getHead()->getTileByAttributes(colour, shape);
        Node *nodeToRemove = this->gameState->getPlayers()->getCurrentPlayer()->getHandPtr()->getNode(tilePtr);
        this->gameState->getPlayers()->getCurrentPlayer()->getHandPtr()->removeItemFromList(nodeToRemove);
        this->gameState->getPlayers()->getCurrentPlayer()->getHandPtr()->addTileToBack(this->gameState->getTileBag()->replaceTile(&tilePtr));
    }
    else
    {
        std::cout << "\n*** No such tile in your hand ***\n"
                  << std::endl;
        invalid = true;
    }

    return invalid;
}
