
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#include "Tile.h"

class LinkedList
{
public:
    // Constructor/Destructor
    LinkedList();
    ~LinkedList();

    // Method to implement destructor.
    void clearList();

    // Accessors
    int getSize();

    Tile *getTileAtIndex(int index);

    // Functions to add/remove tiles.

    // Add a tile to the list.
    void addTileToBack(Tile *tile);

    // Get the front tile from the list.
    Tile *drawTile();

    // Remove a tile from player hand.
    Tile *removeTile(Tile *tile);

private:
    Node *head;
    Node *tail;
    int size;
};

#endif // ASSIGN2_LINKEDLIST_H