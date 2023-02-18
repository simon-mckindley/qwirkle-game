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
                        // std::cout << valid_moves[valid_moves.size() - 1].tile.getColour() << valid_moves[valid_moves.size() - 1].tile.getShape() << ":" << x << "-" << y << ", ";
                    }
                }
            }
        }
    }

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
4. Blocking - Place tiles to block other players moves.
*/

placement AI_Player::choosePlacement(GameBoard *board, std::vector<placement> valid_moves)
{
    const int min_qwirkle_score = 12;
    std::vector<placement> ordered_moves = {};
    bool found = false;
    int dupIndex = hasDuplicates();
    placement choice;
    choice.score = 0;

    // Creates a vector of placements ordered by score (highest to lowest)
    bool added;
    ordered_moves.push_back(valid_moves[0]);
    for (int i = 1; i < valid_moves.size(); i++)
    {
        added = false;
        for (int j = 0; j < ordered_moves.size(); j++)
        {
            if (valid_moves[i].score > ordered_moves[j].score)
            {
                ordered_moves.insert(ordered_moves.begin() + j, valid_moves[i]);
                added = true;
                break;
            }
        }

        if (!added)
        {
            ordered_moves.push_back(valid_moves[i]);
        }
    }

    for (placement p : ordered_moves)
    {
        std::cout << p.tile.getColour() << p.tile.getShape() << ":" << p.x << "-" << p.y << ":" << p.score << ", ";
    }

    // If qwirkle has been scored make it the choice
    if (ordered_moves[0].score >= min_qwirkle_score)
    {
        choice = ordered_moves[0];
        found = true;
    }
    // If there's duplicate tiles in the hand
    else if (dupIndex > 0)
    {
        for (placement p : ordered_moves)
        {
            // If the duplicate tile is able to be played make it the choice.
            // Otherwise return no choice to get it replaced.
            if (p.tile.getColour() == this->playerHand->getTileAtIndex(dupIndex)->getColour() && p.tile.getShape() == this->playerHand->getTileAtIndex(dupIndex)->getShape())
            {
                choice = p;
            }
        }
        found = true;
    }

    while (!found)
    {
    };

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
