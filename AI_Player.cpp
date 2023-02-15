#include "AI_Player.h"

AI_Player::AI_Player() {}

// Constructor to assign name and hand at creation.
AI_Player::AI_Player(TileBag *tileBag)
{
    this->name = "AI Arty";
    this->score = 0;
    this->playerHand = new Hand(tileBag);
    this->isAI = true;
}

std::string AI_Player::gamePlay(GameBoard *board)
{
    int topScore = 0;
    std::string tileCode = "";
    std::string location = "";
    std::string result = "";

    // Loop through all board positions
    for (int x = 0; x < board->getHeight(); x++)
    {
        for (int y = 0; y < board->getWidth(); y++)
        {
            // Find board position that is adjacent
            if (board->validateAdjacent(x, y))
            {
                // Loop through all tiles in the hand
                for (int i = 0; i < this->playerHand->getSize(); i++)
                {
                    Tile *tile = this->playerHand->getTileAtIndex(i);
                    // Find if valid placement for tile
                    if (board->validateValidPlacement(x, y, *tile))
                    {
                        int newScore = board->getScore(x, y, *tile);
                        // If the score is the largest so far
                        if (newScore > topScore)
                        {
                            // Save placement info
                            topScore = newScore;
                            tileCode = tile->getColour() + std::to_string(tile->getShape());
                            location = char(65 + x) + std::to_string(y + 1);
                            std::cout << "\t" << tileCode << "@" << location << ":" << topScore << "\t";
                        }
                    }
                }
            }
        }
    }

    if (topScore > 0)
    {
        result.push_back(PLACE_CMD);
        result.append(tileCode + location);
    }
    else
    {
        Tile *tile = this->playerHand->getTileAtIndex(0);
        result.push_back(REPLACE_CMD);
        result.push_back(tile->getColour());
        result.append(std::to_string(tile->getShape()));
    }
    return result;
}
