
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

Tile *LinkedList::getTileAtIndex(int index)
{
    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->tile;
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

        return tile;
    }
    else
    {

        // TODO: Placeholder value consider replacing.
        // What should be returned if nullptr?
        Tile *tile = new Tile();
        return tile;
    }
}

// Remove and return the tile chosen by the player.
Tile *LinkedList::removeTile(Tile *tile)
{
    return new Tile();
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

// Remove and return the tile chosen by the player.
void LinkedList::replaceTile(Tile *tileToReplace, LinkedList *tileBag)
{
    // Put the old tile back in the tile bag
    addTileToBack(tileToReplace);

    // Remove the tile from the player's hand
    removeTilesFromFront(1);

    // Draw a new tile from the tile bag
    Tile *newTile = tileBag->drawTile();

    // Add the new tile to the player's hand
    addTileToBack(newTile);
}

void LinkedList::removeTilesFromFront(int numToRemove)
{
    while (getHead() != nullptr && numToRemove > 0)
    {
        Node *node = getHead();
        setHead(getHead()->next);
        delete node;
        numToRemove--;
        this->setSize(this->getSize() - 1);
    }
}

int LinkedList::getSize()
{
    return size;
}

void LinkedList::setSize(int size)
{
    this->size = size;
}

Node *LinkedList::getHead()
{
    return head;
}
void LinkedList::setHead(Node *head)
{
    this->head = head;
}

Node *LinkedList::getTail()
{
    return tail;
}
void LinkedList::setTail(Node *tail)
{
    this->tail = tail;
}