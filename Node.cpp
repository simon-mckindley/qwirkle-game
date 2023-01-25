
#include "Node.h"

Node::Node(Tile *tile, Node *next)
{
    this->tile = new Tile(tile->getColour(), tile->getShape());
    this->next = next;
}

Node::~Node()
{
    delete tile;
}

// Copy Constructor (Deep Copy).
Node::Node(Node &other)
{
    this->tile = new Tile(*(other.tile));
    this->next = other.next;
}
