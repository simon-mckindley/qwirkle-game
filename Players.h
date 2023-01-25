#ifndef ASSIGN2_PLAYERS_H
#define ASSIGN2_PLAYERS_H

#include "LinkedList.h"
#include "Player.h"
#include "Node.h"
#include <string>

class Players
{
    private:
        // TODO: This needs to be correctly implemented, this is just a placeholder
        LinkedList players;
        Node* currentPlayer;

    public:
        Players();

        // Returns the next player in the LinkedList
        Player nextPlayer();
        

};

#endif // ASSIGN2_PLAYERS_H