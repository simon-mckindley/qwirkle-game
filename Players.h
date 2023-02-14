#ifndef ASSIGN2_PLAYERS_H
#define ASSIGN2_PLAYERS_H

#include "Player.h"
#include <vector>

class Players
{
private:
    std::vector<Player> players{};
    int currentPlayerIndex;

public:
    // Constructor
    Players();

    // Adds a player to the vector
    void addPlayer(Player player);

    // Returns the next player and assigns them as the current player
    Player *nextPlayer();

    // Accessor / Mutator methods
    Player *getPlayer(int i);
    Player *getCurrentPlayer();
    void setCurrentPlayerIndex(int i);
    int getCurrentPlayerIndex();
    int getSize();
};

#endif // ASSIGN2_PLAYERS_H