#ifndef ASSIGN2_PLAYERS_H
#define ASSIGN2_PLAYERS_H

#include "Player.h"

class Players
{
private:
    Player *players[2];
    Player *currentPlayer;

public:
    Players();
    Players(Player *player1, Player *player2);

    // Returns the next player and assigns them as the current player
    Player nextPlayer();

    Player getPlayer(int i);
    Player getCurrentPlayer();
    void setCurrentPlayer(Player *player);
};

#endif // ASSIGN2_PLAYERS_H