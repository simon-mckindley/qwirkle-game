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

        if (currentPlayer->getIsAI())
        {
            endGame = aiPlayOption();
        }
        else
        {
            endGame = gamePlayOption();
        }

        if (!endGame)
        {
            std::cout << "Press <Enter> to continue...";
            std::string str;
            std::getline(std::cin, str);

            currentPlayer = gameState->getPlayers()->nextPlayer();
        }

    } while (!endGame);

    delete gameState;
}

// Creates a new 2-4 (human) player game
void GamePlay::createNewGame()
{
    std::cout << "\nStarting a new game." << std::endl;

    Players *players = new Players();
    TileBag *tileBag = new TileBag();
    GameBoard *gameBoard = new GameBoard();
    tileBag->fillTileBag();

    int numPlayers = validatePlayerNum();

    // Create new players
    for (int i = 1; i <= numPlayers; i++)
    {
        std::cout << "\nEnter a name for Player " << i
                  << " (Uppercase characters only)" << std::endl;
        std::string playerName = getPlayerName();

        Player *player = new Player(playerName, tileBag);
        players->addPlayer(*player);
    }

    // Welcome message
    std::cout << "\nWelcome, ";
    for (int i = 0; i < players->getSize(); i++)
    {
        std::cout << players->getPlayer(i)->getName();
        if (i < players->getSize() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "\n\tLets Play!" << std::endl;

    // Creates new Gamestate object for the pointer
    gameState = new GameState(players, gameBoard, tileBag);

    gamePlay();
}

// Creates a new AI versus (human) player game
void GamePlay::createAIGame()
{
    std::cout << "\nStarting a new game." << std::endl;

    std::string playerName;
    std::cout << "\nEnter your player name (Uppercase characters only)" << std::endl;
    playerName = getPlayerName();
    std::cout << "\nWelcome, " << playerName
              << "\n\tLets Play!" << std::endl;

    // player1name = "ONE";

    TileBag *tileBag = new TileBag();
    tileBag->fillTileBag();

    // Creates new players and allocate hands of tiles
    Player *player = new Player(playerName, tileBag);
    Player *ai_player = new AI_Player(tileBag);
    Players *players = new Players();
    players->addPlayer(*player);
    players->addPlayer(*ai_player);

    // Creates new Gamestate object for the pointer
    GameBoard *gameBoard = new GameBoard();

    gameState = new GameState(players, gameBoard, tileBag);

    gamePlay();
}

// Calls the load method of gamestate with the specified file
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

// Validates and returns the number of players
int GamePlay::validatePlayerNum()
{
    int numPlayers = 0;
    const int minPlayers = 2;
    const int maxPlayers = 4;

    std::cout << "\nHow many players are there? (" << minPlayers << " - " << maxPlayers << ")"
              << std::endl;
    do
    {
        try
        {
            numPlayers = stoi(UserPrompt::getInput());

            if (numPlayers < minPlayers || numPlayers > maxPlayers)
            {
                std::cout << "Invalid input" << std::endl;
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Invalid input" << std::endl;
        }
    } while (numPlayers < minPlayers || numPlayers > maxPlayers);

    return numPlayers;
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
    for (int i = 0; i < gameState->getPlayers()->getSize(); i++)
    {
        std::cout << "\nScore for "
                  << gameState->getPlayers()->getPlayer(i)->getName()
                  << ": " << gameState->getPlayers()->getPlayer(i)->getScore();
    }

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
    int topScore = 0;
    std::string winner = "";

    std::cout << "\n\tGAME OVER";
    for (int i = 0; i < gameState->getPlayers()->getSize(); i++)
    {
        int score = gameState->getPlayers()->getPlayer(i)->getScore();
        std::string name = gameState->getPlayers()->getPlayer(i)->getName();
        if (score > topScore)
        {
            topScore = score;
            winner = name;
        }
        else if (score == topScore)
        {
            winner = "tied";
        }
        std::cout << "\nScore for " << name << ": " << score;
    }

    if (winner == "tied")
    {
        std::cout << "The game is a tie!\n"
                  << std::endl;
    }
    else
    {
        std::cout << "Player " << winner << " has won!\n"
                  << std::endl;
    }
}

// Gets and validates user gameplay input
bool GamePlay::gamePlayOption()
{
    bool loopAgain;
    bool endGame = false;
    std::string userInput;
    do
    {
        loopAgain = false;

        std::cout << currentPlayer->getName()
                  << " - What would you like to do?\n"
                  << "\tplace <tile> at <location>\n"
                  << "\treplace <tile>\n"
                  << "\thint <tile>\n"
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
            "replace XX" (length=10),
            "hint XX" (length=7),
            "save <filename>" (min_length=7) */

            if (cmd == "place" && length >= 14)
            {
                std::string tile = userInput.substr(pos + 1, 2);
                std::string location = userInput.substr(pos + 7);
                std::cout << "Tile: " << tile << "  Place: " << location << std::endl;
                loopAgain = placeTile(location, tile);
            }
            else if (cmd == "replace" && length == 10)
            {
                std::string tile = userInput.substr(pos + 1, 2);
                std::cout << "Replace:" << tile << std::endl;
                loopAgain = replaceTile(tile);
            }
            else if (cmd == "hint" && length == 7)
            {
                std::string tile = userInput.substr(pos + 1, 2);
                getHint(tile);
                loopAgain = true;
            }
            else if (cmd == "save" && length >= 7)
            {
                std::string fileName = userInput.substr(pos + 1);
                std::cout << "Saving game to: " << fileName << std::endl;
                gameState->save(fileName);
                loopAgain = true;
            }
            else
            {
                std::cout << "\n*** Invalid input ***\n"
                          << std::endl;
                loopAgain = true;
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
            loopAgain = true;
        }

    } while (loopAgain);

    endGame = checkEndGame();
    if (endGame)
    {
        printEndGame();
    }

    return endGame;
}

// Gets the AI gameplay input and processes it
bool GamePlay::aiPlayOption()
{
    AI_Player *ai_player = (AI_Player *)currentPlayer;
    std::string cmdStr = ai_player->gamePlay(gameState->getGameBoard());

    /* cmdStr format:
    To place:   P<tile><location>
    To replace: R<tile> */

    bool endGame = false;

    std::cout << currentPlayer->getName() << " will ";

    if (cmdStr[0] == PLACE_CMD)
    {
        std::string tile = cmdStr.substr(1, 2);
        std::string location = cmdStr.substr(3);
        std::cout << "place a tile\n"
                  << "Tile: " << tile << "  Place: " << location
                  << std::endl;
        placeTile(location, tile);
    }
    else if (cmdStr[0] == REPLACE_CMD)
    {
        std::string tile = cmdStr.substr(1);
        std::cout << "replace:" << tile << std::endl;
        replaceTile(tile);
    }

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
        catch (const std::invalid_argument &e)
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

    this->currentPlayer->addScore(6);
    return true;
}

// Determines and prints the highest scoring location for the passed in tile
void GamePlay::getHint(std::string tile)
{
    std::string userSelectionTileColour = tile.substr(0, 1);
    std::string userSelectionTileShape = tile.substr(1, 1);

    Colour colour = Tile::convertToColour(userSelectionTileColour);
    Shape shape = Tile::convertToShape(userSelectionTileShape);
    Tile *tempTile = new Tile(colour, shape);

    if (this->currentPlayer->getHandPtr()->isTileInList(tempTile))
    {
        int topScore = 0;
        std::string location = "";

        // Loop through all board positions
        for (int x = 0; x < gameState->getGameBoard()->getHeight(); x++)
        {
            for (int y = 0; y < gameState->getGameBoard()->getWidth(); y++)
            {
                // Find board position that is adjacent
                if (gameState->getGameBoard()->validateAdjacent(x, y))
                {
                    // Checks if this tile can be placed in this location
                    if (gameState->getGameBoard()->validateValidPlacement(x, y, *tempTile))
                    {
                        int score = gameState->getGameBoard()->getScore(x, y, *tempTile);
                        // Save the data if it is the highest scoring placement
                        if (score > topScore)
                        {
                            topScore = score;
                            location = char(65 + x) + std::to_string(y + 1);
                        }
                    }
                }
            }
        }

        if (topScore > 0)
        {
            std::cout << "\nHint: place " << tempTile->getColour() << tempTile->getShape()
                      << " at " << location << " to score " << topScore << "\n"
                      << std::endl;
        }
        else
        {
            std::cout << "\nHint: cannot place " << tempTile->getColour() << tempTile->getShape()
                      << " at the moment\n"
                      << std::endl;
        }
    }
    else
    {
        std::cout << "\n*** No such tile in your hand ***\n"
                  << std::endl;
    }

    delete tempTile;
}