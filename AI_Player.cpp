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

void AI_Player::gamePlay()
{
    // Find board position that is adjacent
    // loop through tile from hand to find highest scoring valid placement - save it tile and location
    // repeat for next adjacent tile

    // place tile in the saved placement
    // if no valid placements replace front tile

}
