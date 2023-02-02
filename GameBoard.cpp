#include "GameBoard.h"

GameBoard::GameBoard(){};

GameBoard::GameBoard(vector<vector<Tile>> board)
{
    board = board;
}

int GameBoard::getHeight()
{
    return board.size();
}

int GameBoard::getWidth()
{
    if (board.size() > 0)
    {
        return board[0].size();
    }
    else
    {
        return 0;
    }
}

// Gets tile from x and y coordinates of the gameboard. Returns a
// default tile if coordinates are not valid.
Tile GameBoard::getTile(int x, int y)
{
    Tile *tile = new Tile();
    if (validSpace(x, y))
    {
        tile->setColour(board[y][x].getColour());
        tile->setShape(board[y][x].getShape());
    }
    return *tile;
}

bool GameBoard::validSpace(int x, int y)
{
    if (x > 0 && x < getWidth() && y > 0 && y < getHeight())
    {
        return true;
    }
    return false;
}

bool GameBoard::validateAdjacentColour(Colour colour, Tile adjacentTile)
{
    if (adjacentTile.getColour() != 'X')
    {
        if (colour != adjacentTile.getColour())
        {
            return false;
        }
    }

    return true;
}

bool GameBoard::validateAdjacentShape(Shape shape, Tile adjacentTile)
{
    if (adjacentTile.getShape() != 'X')
    {
        if (shape != adjacentTile.getShape())
        {
            return false;
        }
    }

    return true;
}

// Checks if Tile placement is valid in relation to
// surrounding tiles, returns true if valid
bool GameBoard::validateSetTile(int x, int y, Tile tile)
{
    Colour colour = tile.getColour();
    Shape shape = tile.getShape();

    // TODO: Delete this
    std::cout << getWidth() << " " << getHeight() << std::endl;

    // Validate that target coordinates exist and get existing
    Tile existingTile;
    if (validSpace(x, y))
    {
        Tile existingTile = getTile(x, y);
    }
    else
    {
        std::cout << "target coordinates are not within the bounds of the board" << std::endl;
        return false;
    }

    // Validate that existing tile space is blank
    if (existingTile.getColour() != 'X' || existingTile.getShape() != 0)
    {
        std::cout << "tile already exists in this space" << std::endl;
        return false;
    }

    // Validate placement in relation to surrounding tiles

    // Initializes surrounding tiles
    Tile leftTile = (x > 0) ? getTile(x - 1, y) : Tile();
    Tile rightTile = (x < getWidth()) ? getTile(x + 1, y) : Tile();
    Tile aboveTile = (y > 0) ? getTile(x, y - 1) : Tile();
    Tile belowTile = (y < getHeight()) ? getTile(x, y + 1) : Tile();

    // Validate that at least one tile is touching
    if (leftTile.getColour() != 'X' || rightTile.getColour() != 'X' ||
        aboveTile.getColour() != 'X' || belowTile.getColour() != 'X')
    {
        std::cout << "Cannot place a tile that is not touching adjacent to another tile" << std::endl;
        return false;
    }

    // Initializes booleans for row and column checks
    bool colourValidY = true;
    bool shapeValidY = true;

    bool colourValidX = true;
    bool shapeValidX = true;

    // Validate X axis. Both left and right tiles must match on either shape or colour, not a
    // combination of both
    // Validate tile to the left
    colourValidX = (validateAdjacentColour(colour, leftTile)) ? true : false;
    shapeValidX = (validateAdjacentShape(shape, leftTile)) ? true : false;

    // Validate tile to the right
    if (!colourValidX || !validateAdjacentColour(colour, rightTile))
    {
        colourValidX = false;
    }

    if (!shapeValidX || !validateAdjacentShape(shape, rightTile))
    {
        shapeValidX = false;
    }

    if (!colourValidX && !shapeValidX)
    {
        std::cout << "Neither the colour or shape match across the row" << std::endl;
        return false;
    }

    // Validate Y axis.
    // Validate tile above.
    colourValidY = (validateAdjacentColour(colour, aboveTile));
    shapeValidY = (validateAdjacentShape(shape, aboveTile));

    // Validate tile below
    if (!colourValidY || !validateAdjacentColour(colour, belowTile))
    {
        colourValidY = false;
    }
    if (!shapeValidY || !validateAdjacentShape(shape, belowTile))
    {
        shapeValidY = false;
    }

    if (!colourValidY && !shapeValidY)
    {
        std::cout << "Neither the colour or shape match down the column" << std::endl;
        return false;
    }

    std::cout << "Valide placement!" << std::endl;
    return true;
}

// Sets the x and y coordinates of the board to the assigned Tile.
void GameBoard::setTile(int x, int y, Tile tile)
{
    // bool success = false;

    try
    {
        board[y][x] = tile;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

std::vector<std::string> GameBoard::getState()
{
    std::vector<std::string> state;

    // Added 'size' vairalbe to avoid an error in which int is compared with long unsigned int
    int size = board.size();
    for (int i = 0; i < size; i++)
    {
        // Added 'iSize' vairalbe to avoid an error in which int is compared with long unsigned int
        int iSize = board[i].size();
        for (int j = 0; j < iSize; j++)
        {
            if (board[i][j].getColour() != ' ')
            {
                state.push_back(board[i][j].getColour() + std::to_string(board[i][j].getShape()) + "@(" + std::to_string(i) + "," + std::to_string(j) + ")");
            }
        }
    }
    return state;
}

// iterates through each row of the board and builds a string
// for printing to the console
std::string GameBoard::toString()
{
    std::string boardString = "";

    for (vector<Tile> row : board)
    {
        for (Tile col : row)
        {
            boardString.push_back('|');

            // Converts type to char or white space if empty tile
            char c = (col.getColour() != 'X') ? col.getColour() : ' ';
            std::string s = (col.getShape() == 0) ? " " : std::to_string(col.getShape());

            // Add characters to board
            boardString.push_back(c);
            boardString.append(s);
        }
        boardString.append("|\n");
    }
    return boardString;
}