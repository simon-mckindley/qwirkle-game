
#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList()
{
    clearList();
}

int LinkedList::getSize()
{
    return size;
}

// Add a tile to the back of the list. Update pointer.
void LinkedList::addTileToBack(Tile *tile)
{
    Node *node = new Node(tile, nullptr);
    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
    size++;
}

// Remove and return the tile from the head of the list.
Tile *LinkedList::drawTile()
{
    if (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        Tile *tile = temp->tile;
        size--;
        delete temp;

        return tile;
    }
}

// Remove and return the tile chosen by the player.
Tile *LinkedList::removeTile(Tile *tile)
{
}

// Deallocate LinkedList memory.
void LinkedList::clearList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
}
