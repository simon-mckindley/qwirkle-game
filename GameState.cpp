#include "GameState.h"

GameState::GameState(Players *players, GameBoard *gameBoard, TileBag *tileBag)
{
    this->players = players;
    this->gameBoard = gameBoard;
    this->tileBag = tileBag;
}

// Save a the current game data to the specified file
void GameState::save(std::string filename)
{
    std::ofstream file(filename);

    if (!file)
    {
        std::cout << "Error: File Not Found." << std::endl;
    }
    else
    {
        // Write the number of players in the game
        file << players->getSize() << std::endl;

        // Write player information
        for (int i = 0; i < players->getSize(); i++)
        {
            file << players->getPlayer(i)->getName() << std::endl;
            file << players->getPlayer(i)->getScore() << std::endl;
            file << players->getPlayer(i)->getHand() << std::endl;
        }

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
bool GameState::load(std::string filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cout << "Error: File Not Found." << std::endl;
        return false;
    }
    else
    {
        players = new Players();
        std::string input;
        std::string name;
        std::string score;
        std::string hand;
        TileBag *newHand;
        std::string boardDimension;
        std::string boardState;
        std::string tileBag;
        std::string currentPlayerName;

        try
        {
            std::getline(file, input);
            int numPlayers = stoi(input);

            // Read and create player
            for (int i = 0; i < numPlayers; i++)
            {
                std::getline(file, name);
                std::getline(file, score);
                std::getline(file, hand);
                newHand = new TileBag(hand);
                Player *player = new Player(name, newHand);
                player->addScore(stoi(score));
                players->addPlayer(*player);
            }

            // Read board height and width.
            std::getline(file, boardDimension);

            // Read board information
            std::getline(file, boardState);

            // Read tile bag contents
            std::getline(file, tileBag);

            // Read current player name
            std::getline(file, currentPlayerName);

            file.close();

            // Get dimensions from string
            std::string::size_type pos = boardDimension.find_first_of(",");
            int height = stoi(boardDimension.substr(0, pos));
            int width = stoi(boardDimension.substr(pos + 1));

            // Create gameboard
            this->gameBoard = new GameBoard();
            this->gameBoard->setState(boardState, height, width);

            // Create tilebag
            this->tileBag = new TileBag(tileBag);

            std::cout << "Game loaded successfully" << std::endl;
            return true;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Error: Invalid file format." << std::endl;
            return false;
        }
    }
}