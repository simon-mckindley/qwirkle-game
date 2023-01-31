#include "Tile.h"
#include <vector>
#include <string>
#include <iostream>

using std::vector;

class GameBoard
{
private:
    // Each vector is a row, and the nested vector of tiles
    // within is the existing columns and their values
    std::vector<std::vector<Tile>> board{26, std::vector<Tile>{26, Tile()}};

public:
    // Default constructor - Initializes as a 26 x 26 grid
    GameBoard();

    // Constructor for loading a board - may require changes
    // to suit loadGame() implementation
    GameBoard(vector<vector<Tile>> board);

    // Return board height.
    int getHeight();

    // Return board width.
    int getWidth();

    void setTile(int x, int y, Tile tile);

    // Return the state of the board as a vector of strings.
    std::vector<std::string> getState();

    // Print the board to console
    std::string toString();
};