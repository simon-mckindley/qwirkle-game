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

        // TODO: I'm not sure if converting pos from int to size_type
        // will still perform the same funciton, but compasing an int to
        // an npos throws an error trying to compare an int with a long
        // unsigned int when compiling. This resolves that error.
        //
        // Need to confirm that this doesn't introduce any logical errors
        // or runtime errors, but at a first pass it appears to work fine.
        std::string::size_type pos = userInput.find_first_of(" ");

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
                bool isValid = validateChoice(tile, location, *gameState);
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

int GamePlay::getAxisScore(int x, int y, Tile tile, bool row)
{
    // Determines if the x (rows) or y (cols) axis is being checked
    int xMod, yMod;
    int xCoord = x;
    int yCoord = y;

    if (row)
    {
        xMod = 1;
        yMod = 0;
    }
    else
    {
        xMod = 0;
        yMod = 1;
    }

    // Initialize variables to check if row matches against colours or shapes
    // and for how many tiles that match is true for
    Colour colour = tile.getColour();
    Shape shape = tile.getShape();

    bool colourMatch = true;
    bool shapeMatch = true;

    // Used to remember if row/col negative of placed tile matches
    // colours or shapes. Prevents a scenario in which we count points
    // towards shapes on the left of a placed tiles, then colours on
    // the right.
    bool colourMatchingOnly = true;

    GameBoard gameboard = getGameState().getBoard();

    int score = 1;

    // Check score for x axis
    // Check negative of x/y axis
    while (xCoord > 0 && yCoord > 0 && (colourMatch || shapeMatch))
    {
        xCoord -= xMod;
        yCoord -= yMod;

        if (colourMatch)
        {
            if (gameboard.getTile(xCoord, yCoord).getColour() != colour)
            {
                colourMatch = false;
            }
        }

        if (shapeMatch)
        {
            if (gameboard.getTile(xCoord, yCoord).getShape() != shape)
            {
                shapeMatch = false;
            }
        }

        if (colourMatch || shapeMatch)
        {
            score += 1;
        }

        // Define if the row is colour matching or shape matching and check
        // only matching type in next loop
        if (colourMatch && !shapeMatch)
        {
            colourMatchingOnly = true;
        }
        else if (shapeMatch && !colourMatch)
        {
            colourMatchingOnly = false;
        }
    }

    // Reset variables for positive x/y axis score check
    xCoord = x;
    yCoord = y;

    // Set if row is matching colour or matching shapes
    if (colourMatchingOnly)
    {
        colourMatch = true;
        shapeMatch = false;
    }
    else
    {
        shapeMatch = true;
        colourMatch = false;
    }

    while (xCoord < gameboard.getWidth() && yCoord < gameboard.getHeight() && (colourMatch || shapeMatch))
    {
        xCoord += xMod;
        yCoord += yMod;

        if (colourMatch)
        {
            if (gameboard.getTile(xCoord, yCoord).getColour() != colour)
            {
                colourMatch = false;
            }
        }

        if (shapeMatch)
        {
            if (gameboard.getTile(xCoord, yCoord).getShape() != shape)
            {
                shapeMatch = false;
            }
        }

        if (colourMatch || shapeMatch)
        {
            score += 1;
        }
    }

    return score;
}

// Assumes move has been validated as allowed withn the rules of the game
int GamePlay::getScore(int x, int y, Tile tile)
{
    // Initialize variables
    GameBoard gameBoard = getGameState().getBoard();

    Colour colour = tile.getColour();
    Shape shape = tile.getShape();

    int xCoord = x;
    int yCoord = y;

    int score = 1;
    int qwirkleCount = 0;

    // Check score for x axis
    int xScore = getAxisScore(x, y, tile, true);
    score += xScore;
    if (xScore >= 7)
    {
        std::cout << "QWIRKLE!!! on the x axis" << std::endl;
        score += 6;
    }

    // Check score for y axis
    int yScore = getAxisScore(x, y, tile, false);
    score += yScore;
    if (yScore >= 7)
    {
        std::cout << "QWIRKLE!!! on the y axis" << std::endl;
        score += 6;
    }

    return score;
}

// TODO: Implement validation from GameBoard, not this method here
bool GamePlay::validateChoice(std::string tileChoice, std::string location, GameState gameState)
{
    std::cout << tileChoice << " " << location << std::endl;

    // Validate piece exists in players hand
    Player player = gameState.getPlayers().getCurrentPlayer();
    // LinkedList* playerHand = player.getHand()
    // iterate through list and confirm tile exists in players hand.

    // Validate piece can be placed on the board

    return true;
}