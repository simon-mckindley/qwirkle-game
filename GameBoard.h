#include "Tile.h"
#include "TileCodes.h"

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using std::vector;

class GameBoard
{
private:
    // Each vector is a row, and the nested vector of TileBag
    // within is the existing columns and their values
    std::vector<std::vector<Tile>> board{26, std::vector<Tile>{26, Tile(NO_COL, NO_SHAPE)}};

    // Used to track the current tiles in play. This avoids counting tiles
    // that have been placed within the same move twice.
    vector<Tile> currentTiles;

    // Helper method that returns all the tiles in a row or column that are
    // in play with a tile in the given x, y space. This does NOT include tiles
    // that share a row or column, but are seperated by an empty tiles space
    vector<Tile> getTilesOnAxis(int x, int y, bool rowAxis);

    // Helper method to calculate either a row or column
    bool validateTileAgainstSet(std::vector<Tile> tileSet, Tile tile);

    // Gets a vector of tiles that share the same row as the x, y coords given
    std::vector<Tile> getTilesOnRow(int x, int y);

    // Gets a vector of tiles that share the same col as the x, y corrds given
    std::vector<Tile> getTilesOnCol(int x, int y);

    // Validates the given tiles colour against the given colour
    bool checkColourMatch(Colour colour, Tile adjacentTile);

    // Validates the given tiles shape agains the given shape
    bool checkShapeMatch(Shape shape, Tile adjacentTile);

    // Helper method to setTile which calculates the score achieved by the
    // tile placement
    int getScore(int x, int y, Tile tile);

public:
    // Default constructor
    GameBoard();

    // Constructor for loading a board - may require changes
    // to suit loadGame() implementation
    GameBoard(vector<vector<Tile>> board);

    // Return board height.
    int getHeight();

    // Return board width.
    int getWidth();

    // Returns the tile at the given coordinates
    Tile getTile(int x, int y);

    // Takes x and y coordinates and a tile and assigns that tile to
    // the gameboard space. Returns the resulting score as an int
    int setTile(int x, int y, Tile tile);

    // Validates that a space is within the bounds of the board
    bool validSpace(int x, int y);

    // Validate that tile can be placed there within the rules of the game.
    bool validateSetTile(int x, int y, Tile tile, bool firstTurn);

    static int alphabetToNumber(char letter);

    // Return the state of the board as a string
    std::string getState();

    // Sets the board according to the data passed in from the load file method
    void setState(std::string &state, int height, int width);

    // Print the board to console
    std::string toString();
};