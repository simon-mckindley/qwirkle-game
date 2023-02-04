#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "LinkedList.h"
#include "Hand.h"
#include <string>

class Player
{
private:
    std::string name;
    int score;
    TileBag *tileBag;
    Hand *playerHand;

public:
    Player();
    Player(std::string name, TileBag *tileBag);

    void increaseScore(int score);

    // Return the player name.
    std::string getName();

    // Return player score.
    int getScore();

    // Return the player hand as an ordered list.
    std::string getHand();

    // Return the player hand as a pointer to a hand.
    Hand *getHandPtr();
};

#endif // ASSIGN2_PLAYER_H