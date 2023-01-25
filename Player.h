#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "Tiles.h"
#include <string>

class Player
{
    private: 
        std::string name;
        int score;
        Tiles playerHand;

    public:
        Player();
        Player(std::string name);

        void increaseScore(int score);

};

#endif // ASSIGN2_PLAYER_H