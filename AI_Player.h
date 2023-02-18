#ifndef ASSIGN2_AI_PLAYER_H
#define ASSIGN2_AI_PLAYER_H

#include "Player.h"
#include "Hand.h"
#include "GameBoard.h"
#include <string>
#include <vector>
#include <list>

#define PLACE_CMD 'P'
#define REPLACE_CMD 'R'

struct placement {
    Tile tile;
    int x;
    int y;
    int score;
};

class AI_Player : public Player
{
public:
    // Default constructor
    AI_Player();

    // Constructor to assign name and hand at creation.
    AI_Player(TileBag *tileBag);

    std::string gamePlay(GameBoard *board);

private:
    // Returns True if this is the best tile to place, so far
    placement choosePlacement(GameBoard *board, std::vector<placement> valid_moves);

    // Creates the command string to send to the GamePlay function
    std::string createCmd(placement choice);

    // Finds if the hand contains duplicate tiles and returns the index of the first one
    int hasDuplicates();
};

#endif // ASSIGN2_AI_PLAYER_H