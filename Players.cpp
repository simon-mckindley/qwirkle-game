
#include "Players.h"

// Default constructor
Players::Players() {}

Players::Players(Player *player1, Player *player2)
{
    this->players[0] = player1;
    this->players[1] = player2;
    this->currentPlayer = this->players[0];
}

Player Players::nextPlayer()
{
    if (this->currentPlayer == this->players[1])
    {
        this->currentPlayer = this->players[0];
    }
    else
    {
        this->currentPlayer = this->players[1];
    }

    return *this->currentPlayer;
}

Player Players::getPlayer(int i)
{
    return *this->players[i - 1];
}

Player Players::getCurrentPlayer()
{
    return *this->currentPlayer;
}

void Players::setCurrentPlayer(Player *player)
{
    this->currentPlayer = player;
}