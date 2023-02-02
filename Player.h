#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "LinkedList.h"
#include <string>
#include <sstream>

class Player
{
private:
    std::string name;
    int score;
    LinkedList *playerHand;

public:
    Player();
    Player(std::string name, LinkedList *playerHand);

    void increaseScore(int score);

    // Return the player name.
    std::string getName();

    // Return player score.
    int getScore();

    // Return the player hand as an ordered list.
    std::string getHand();

    // Set current player state from file.
    void setName(std::string name);
    void setScore(int score);
    void setHand(std::string hand);
};

#endif // ASSIGN2_PLAYER_H