
#include "Node.h"

Node::Node(Tile *tile, Node *next)
{
    this->tile = tile;
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

Tile Node::getTile()
{
    return *tile;
}

Tile Node::getTileByAttributes(Colour colour, Shape shape)
{
    for (Node *current = this; current != nullptr; current = current->next)
    {
        if (current->tile->getColour() == colour && current->tile->getShape() == shape)
        {
            return *current->tile;
        }
    }
    return Tile(0, 0);
}

void Node::setTile(Tile *tile)
{
    this->tile = tile;
}
