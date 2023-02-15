#ifndef ASSIGN2_AI_PLAYER_H
#define ASSIGN2_AI_PLAYER_H

#include "Player.h"
#include "Hand.h"
#include <string>

class AI_Player : public Player
{
public:
    // Default constructor
    AI_Player();

    // Constructor to assign name and hand at creation.
    AI_Player(TileBag *tileBag);

    void gamePlay();
};

#endif // ASSIGN2_AI_PLAYER_H