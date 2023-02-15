#ifndef ASSIGN2_AI_PLAYER_H
#define ASSIGN2_AI_PLAYER_H

#include "Player.h"
#include "Hand.h"
#include "GameBoard.h"
#include <string>

#define PLACE_CMD 'P'
#define REPLACE_CMD 'R'

class AI_Player : public Player
{
public:
    // Default constructor
    AI_Player();

    // Constructor to assign name and hand at creation.
    AI_Player(TileBag *tileBag);

    std::string gamePlay(GameBoard *board);
};

#endif // ASSIGN2_AI_PLAYER_H