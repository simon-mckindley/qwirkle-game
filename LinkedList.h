
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

    Tile *getTileAtIndex(int index);

    // Method to implement destructor.
    void clearList();

    // Accessors
    Node *getHead();
    Node *getTail();
    int getSize();

    // Mutators
    void setHead(Node *head);
    void setTail(Node *tail);
    void setSize(int size);

    // Functions to add/remove TileBag.

    void addTileToBack(Tile *tile);
    void addTileToFront(Tile *tile);
    void addTileAtIndex(int index, Tile *tile);

    // Get the front tile from the list.
    Tile *drawTile();

    // Remove a tile from player hand.
    void removeItemFromList(Node *nodeToDelete);

    bool isTileInList(Tile *tile);

    Node *getNode(Tile tile);

    // count total nodes
    int countOfNodes(struct Node *head);

private:
    Node *head;
    Node *tail;
    int size;
};

#endif // ASSIGN2_LINKEDLIST_H