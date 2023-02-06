
#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tile.h"

class Node
{
public:
    Node(Tile *tile, Node *next);
    Node(Node &other);
    ~Node();

    Tile *tile;
    Node *next;

    Tile getTile();
    Tile getTileByAttributes(Colour colour, Shape shape);
    void setTile(Tile *tile);
};

#endif // ASSIGN2_NODE_H
