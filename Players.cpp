
#include "Players.h"

// Default constructor
Players::Players()
{
    this->currentPlayerIndex = 0;
}

void Players::addPlayer(Player player)
{
    this->players.push_back(player);
}

// Returns the next player and assigns them as the current player
Player *Players::nextPlayer()
{
    if (this->currentPlayerIndex >= this->players.size() - 1)
    {
        this->currentPlayerIndex = 0;
    }
    else
    {
        this->currentPlayerIndex++;
    }

    return &this->players.at(this->currentPlayerIndex);
}

Player *Players::getPlayer(int i)
{
    return &this->players.at(i);
}

Player *Players::getCurrentPlayer()
{
    return &this->players.at(this->currentPlayerIndex);
}

void Players::setCurrentPlayerIndex(int i)
{
    this->currentPlayerIndex = i;
}

int Players::getCurrentPlayerIndex()
{
    return this->currentPlayerIndex;
}

int Players::getSize()
{
    return this->players.size();
}