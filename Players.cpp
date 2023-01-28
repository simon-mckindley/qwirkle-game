
#include "Players.h"

// Default constructor
Players::Players(Player *player1, Player *player2)
{
    this->players[0] = player1;
    this->players[1] = player2;
    this->currentPlayer = this->players[0];
}

Player Players::nextPlayer()
{
    if (this->currentPlayer == this->players[0])
    {
        this->currentPlayer = this->players[1];
        return *this->players[1];
    }
    else
    {
        this->currentPlayer = this->players[0];
        return *this->players[0];
    }
}