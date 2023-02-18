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
    std::string tileCode = "";
    std::string location = "";
    std::vector<placement> valid_moves = {};
    std::string cmd = "";

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
                        placement currentPlacement;
                        currentPlacement.tile = (*tile);
                        currentPlacement.x = x;
                        currentPlacement.y = y;
                        currentPlacement.score = board->getScore(x, y, *tile);
                        valid_moves.push_back(currentPlacement);
                        std::cout << tile->getColour() << tile->getShape() << ":" << x << y << ", ";
                        // // If the score is the largest so far
                        // if (newScore > topScore)
                        // {
                        //     // Save placement info
                        //     topScore = newScore;
                        //     tileCode = tile->getColour() + std::to_string(tile->getShape());
                        //     location = char(65 + x) + std::to_string(y + 1);
                        // }
                    }
                }
            }
        }
    }
    std::cout << "\n1, ";
    placement choice = choosePlacement(board, valid_moves);
    cmd = createCmd(choice);
    return cmd;
}

/*
These tips from https://boardgamegeek.com/thread/837784/few-qwirkle-strategy-tips
were followed to create these placement/replacement choice algorithms:

1. Don't set up Qwirkle-scores for the other players.
2. Rack Management - The WORST thing you can do is hold onto an identical pair of tiles for any time whatsoever.
3. Count tiles.
4. Blocking.
*/

placement AI_Player::choosePlacement(GameBoard *board, std::vector<placement> valid_moves)
{
    const int min_qwirkle_score = 12;
    std::vector<placement> ordered_moves = {};
    bool found = false;
    placement choice;
    choice.score = 0;

    // do
    // {
    //     for (int i = 0; i < valid_moves.size(); i++)
    //     {
    //         for (int j = 0; j < ordered_moves.size(); j++)
    //         {
    //             if (valid_moves[i].score > ordered_moves[j].score)
    //             {
    //                 ordered_moves.insert(ordered_moves.begin() + j, valid_moves[i]);
    //             }
    //         }
    //     }

    //     if (ordered_moves[0].score >= min_qwirkle_score)
    //     {
    //         found = true;
    //     }

    // } while (!found);

    // std::vector<Tile> rowTiles = board->getTilesOnRow(x, y);
    // std::vector<Tile> colTiles = board->getTilesOnCol(x, y);

    return choice;
}

// Creates the command string to send to the GamePlay function
std::string AI_Player::createCmd(placement choice)
{
    std::string cmd = "";
    std::string tileCode = choice.tile.getColour() + std::to_string(choice.tile.getShape());
    std::string location = char(65 + choice.x) + std::to_string(choice.y + 1);

    // Replace cmd created
    if (choice.score == 0)
    {
        Tile *replaceTile = this->playerHand->getTileAtIndex(0);
        int index = hasDuplicates();
        if (index > 0)
        {
            replaceTile = this->playerHand->getTileAtIndex(index);
        }

        cmd.push_back(REPLACE_CMD);
        cmd.push_back(replaceTile->getColour());
        cmd.append(std::to_string(replaceTile->getShape()));
    }
    // Place cmd created
    else
    {
        cmd.push_back(PLACE_CMD);
        cmd.append(tileCode + location);
    }

    return cmd;
}

// Finds if the hand contains duplicate tiles and returns the index of the first one
int AI_Player::hasDuplicates()
{
    int index = 0;
    Tile *i_tile;
    Tile *j_tile;

    for (int i = 0; i < this->playerHand->getSize(); i++)
    {
        i_tile = this->playerHand->getTileAtIndex(i);
        for (int j = 1; j < this->playerHand->getSize(); j++)
        {
            j_tile = this->playerHand->getTileAtIndex(0);
            if (j_tile->getColour() == i_tile->getColour() && j_tile->getShape() == i_tile->getShape())
            {
                index = i;
                break;
            }
        }
    }

    return index;
}
