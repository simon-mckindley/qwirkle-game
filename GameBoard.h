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

    Tile getTile(int x, int y);

    // Takes x and y coordinates and a tile and assigns that tile to
    // the gameboard space
    void setTile(int x, int y, Tile tile);

    // Validates that a space is within the bounds of the board
    bool validSpace(int x, int y);

    // Validate that tile can be placed there within the rules of the
    // game
    bool validateSetTile(int x, int y, Tile tile);

    // Validates the given tiles colour against the given colour
    bool validateAdjacentColour(Colour colour, Tile adjacentTile);

    // Validates the given tiles shpae agains the given shape
    bool validateAdjacentShape(Shape shape, Tile adjacentTile);

    // Return the state of the board as a vector of strings.
    std::vector<std::string> getState();

    // Print the board to console
    std::string toString();
};