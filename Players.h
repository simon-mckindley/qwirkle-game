#ifndef ASSIGN2_PLAYERS_H
#define ASSIGN2_PLAYERS_H

#include "LinkedList.h"
#include "Player.h"
#include "Node.h"
#include <string>

class Players
{
    private:
        // TODO: Does LinkedList need to take a generic type so we're able
        // to declare what type of element is in linkedList? 
        LinkedList players;
        
        // Points to the node in the linked list in which the current player 
        // us stored. Will require updating with each nextPlayer() call
        Node* currentPlayer;

    public:
        Players();

        Player nextPlayer();
        

};

#endif // ASSIGN2_PLAYERS_H