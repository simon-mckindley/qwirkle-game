#include "GamePlay.h"

#include <iostream>
#include <string>

// Main gameplay function
void GamePlay::gamePlay()
{
    bool endGame = false;

    do
    {
        std::cout << "\n\n"
                  << gameState->getPlayers().getCurrentPlayer().getName() << ", it's your turn";
        printGameStatus();
        endGame = gamePlayOption();
        gameState->getPlayers().nextPlayer();

    } while (!endGame);
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
              << "\n\tLets Play!";

    // TODO Initialise new game 2.3.10
    // TODO Shuffle Tile Bag
    Tiles tileBag;

    // TODO Allocate hands to players
    LinkedList *player1hand;
    LinkedList *player2hand;

    // Creates new players
    Player *player1 = new Player(player1name, player1hand);
    Player *player2 = new Player(player2name, player2hand);

    // Creates new Gamestate object for the pointer
    gameState = new GameState(*(new Players(player1, player2)), *(new GameBoard()), tileBag);

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

    // TODO Load game from file 2.2.2
    gameState = new GameState();
    // gameState->load(filename);

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
                std::cout << "Invalid input" << std::endl;
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
              << gameState->getPlayers().getPlayer(1).getName()
              << ": "
              << gameState->getPlayers().getPlayer(1).getScore();
    std::cout << "\nScore for "
              << gameState->getPlayers().getPlayer(2).getName()
              << ": "
              << gameState->getPlayers().getPlayer(2).getScore();
    std::cout << "\nPRINT BOARD HERE" << std::endl;
    std::cout << "\nYour hand is:\n"
              // TODO getHand() seg faulting << gameState->getPlayers().getCurrentPlayer().getHand() << "\n"
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
        userInput = userPrompt.getInput();
        int pos = userInput.find_first_of(" ");

        // If input contains a space character
        if (pos != std::string::npos)
        {
            // The input before the space
            std::string cmd = userInput.substr(0, pos);

            // Valid input: place, replace, save
            if (cmd == "place")
            {
                std::string tile = userInput.substr(pos + 1, 2);
                std::string location = userInput.substr(pos + 7);
                std::cout << "Place:" << tile << ":" << location << std::endl;
                // TODO validate tile and location
            }
            else if (cmd == "replace")
            {
                std::string tile = userInput.substr(pos + 1, 2);
                std::cout << "Replace:" << tile << std::endl;
                // TODO validate tile
            }
            else if (cmd == "save")
            {
                std::string fileName = userInput.substr(pos + 1);
                std::cout << "Saving game to: " << fileName << std::endl;
                gameState->save(fileName);
            }
            else
            {
                std::cout << "Invalid input" << std::endl;
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
            std::cout << "Invalid input" << std::endl;
            invalid = true;
        }

    } while (invalid);

    return endGame;
}
