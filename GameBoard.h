#include "Tile.h"
#include <vector>

using std::vector;

class GameBoard
{
private:
    // Each vector is a row, and the nested vector of tiles
    // within is the existing columns and their values
    vector<vector<Tile>> board;

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

    // Return the state of the board as a vector of strings.
    std::vector<std::string> getState();
};