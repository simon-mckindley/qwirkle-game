#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "LinkedList.h"
#include "Hand.h"
#include "TileBag.h"
#include <string>
#include <sstream>

class Player
{
protected:
    std::string name;
    int score;
    Hand *playerHand;
    bool isAI;

public:
    Player();
    Player(std::string name, TileBag *tileBag);

    // Return the player name.
    std::string getName();

    // Return player score.
    int getScore();

    // Return the player hand as an ordered list.
    std::string getHand();

    // Return the player hand as a pointer to a hand.
    Hand *getHandPtr();

    // Set current player state from file.
    void setHand(std::string hand);

    // Increase the players score
    void addScore(int score);

    bool getIsAI();
};

#endif // ASSIGN2_PLAYER_H