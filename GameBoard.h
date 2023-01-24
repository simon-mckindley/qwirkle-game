#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tile.h"
#include <vector>

using std::vector;

class Board
{
    private:
        // Each vector is a row, and the nested vector of tiles
        // within is the existing columns and their values
        vector<vector <Tile>> board;

    public:
        // Default constructor - Initializes as a 26 x 26 grid
        Board();

        // Constructor for loading a board - may require changes 
        // to suit loadGame() implementation
        Board(vector<vector <Tile>> board);
};

#endif // ASSIGN2_NODE_H