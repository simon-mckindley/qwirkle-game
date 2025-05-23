
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
        if (current->next != nullptr)
        {
            current = current->next;
        }
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

// Add a tile to the front of the list. Update pointer.
void LinkedList::addTileToFront(Tile *tile)
{
    Node *node = new Node(tile, nullptr);
    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
    size++;
}

// Add a tile to the list at the index provided
void LinkedList::addTileAtIndex(int index, Tile *tile)
{
    // Add to head
    if (index == 0)
    {
        addTileToFront(tile);
    }
    // Add to tail
    else if (index == size - 1)
    {
        addTileToBack(tile);
    }
    // Add to anywhere inbetween
    else if (index < size)
    {
        Node *newNode = new Node(tile, nullptr);
        Node *target = head;
        Node *previous = nullptr;
        for (int i = 0; i < index; i++)
        {
            previous = target;
            target = target->next;
        }
        newNode->next = target;
        previous->next = newNode;
        size++;
    }
    else
    {
        std::cout << "Invalid Index" << std::endl;
    }
}

// Remove and return the tile from the head of the list.
Tile *LinkedList::drawTile()
{
    Tile *tile = nullptr;
    if (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        tile = temp->tile;
        size--;
    }

    return tile;
}

// Remove the tile chosen by the player.
void LinkedList::removeItemFromList(Node *nodeToDelete)
{
    if (head == nullptr)
        return;

    // Delete from beginning
    if (nodeToDelete == head)
    {
        head = head->next;
        delete nodeToDelete;
        size--;
    }
    // Delete from end
    else if (nodeToDelete == tail)
    {
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        tail = temp;
        delete nodeToDelete;
        size--;
    }
    // Delete from elsewhere
    else
    {
        Node *current = head;
        Node *previous = nullptr;
        while (current != nodeToDelete)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete nodeToDelete;
        size--;
    }
}

// count total nodes
int LinkedList::countOfNodes(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
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

// Returns true if tile is in the list, else false
bool LinkedList::isTileInList(Tile *tile)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->tile->getColour() == tile->getColour() && current->tile->getShape() == tile->getShape())
        {
            return true;
        }
        current = current->next;
    }
    return false;
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

// Returns the pointer to the node containing the tile or nullptr
Node *LinkedList::getNode(Tile tile)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->tile->getColour() == tile.getColour() && current->tile->getShape() == tile.getShape())
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}