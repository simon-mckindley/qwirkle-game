
#include "Players.h"

// Default constructor
Players::Players() {}

Players::Players(Player *player1, Player *player2)
{
    this->players[0] = player1;
    this->players[1] = player2;
    this->currentPlayer = this->players[0];
}

// Returns the next player and assigns them as the current player
Player *Players::nextPlayer()
{
    if (this->currentPlayer == this->players[1])
    {
        setCurrentPlayer(this->players[0]);
    }
    else
    {
        setCurrentPlayer(this->players[1]);
    }

    return this->currentPlayer;
}

Player *Players::getPlayer(int i)
{
    return this->players[i];
}

void Players::setCurrentPlayer(Player *player)
{
    this->currentPlayer = player;
}