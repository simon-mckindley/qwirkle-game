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
        std::string name;
        std::string score;
        std::string hand;
        TileBag *newHand;
        std::string boardDimension;
        std::string boardState;
        std::string tileBag;
        std::string currentPlayerName;

        // Read player 1 information
        std::getline(file, name);
        std::getline(file, score);
        std::getline(file, hand);
        newHand = new TileBag(hand);
        Player *player1 = new Player(name, newHand);
        player1->addScore(stoi(score));

        // Read player 2 information
        std::getline(file, name);
        std::getline(file, score);
        std::getline(file, hand);
        newHand = new TileBag(hand);
        Player *player2 = new Player(name, newHand);
        player2->addScore(stoi(score));

        // Read board height and width.
        std::getline(file, boardDimension);

        // Read board information
        std::getline(file, boardState);

        // Read tile bag contents
        std::getline(file, tileBag);

        // Read current player name
        std::getline(file, currentPlayerName);

        file.close();

        // Create players
        this->players = new Players(player1, player2);
        if (currentPlayerName == player1->getName())
        {
            this->players->setCurrentPlayer(player1);
        }
        else
        {
            this->players->setCurrentPlayer(player2);
        }

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
}