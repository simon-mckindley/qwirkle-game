#ifndef ASSIGN2_PLAYERS_H
#define ASSIGN2_PLAYERS_H

#include "Player.h"

class Players
{
private:
    Player *players[2];
    Player *currentPlayer;

public:
    Players(Player *player1, Player *player2);

    // Returns the next player and assigns them as the current player
    Player nextPlayer();
};

#endif // ASSIGN2_PLAYERS_H