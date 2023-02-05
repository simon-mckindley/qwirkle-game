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
        tile->setColour(board[x][y].getColour());
        tile->setShape(board[x][y].getShape());
    }
    return *tile;
}

bool GameBoard::validSpace(int x, int y)
{
    if (x >= 0 && x < getWidth() && y >= 0 && y < getHeight())
    {
        return true;
    }
    return false;
}

bool GameBoard::checkColourMatch(Colour colour, Tile adjacentTile)
{
    if (adjacentTile.getColour() != NO_COL)
    {
        if (colour != adjacentTile.getColour())
        {
            return false;
        }
    }

    return true;
}

bool GameBoard::checkShapeMatch(Shape shape, Tile adjacentTile)
{
    if (adjacentTile.getShape() != NO_COL)
    {
        if (shape != adjacentTile.getShape())
        {
            return false;
        }
    }

    return true;
}

// Validates that a given tile matches the tileSets colour, or shape. If not,
// returns false
bool GameBoard::validateTileAgainstSet(std::vector<Tile> tileSet, Tile newTile)
{
    Colour colour = newTile.getColour();
    Shape shape = newTile.getShape();

    bool colourMatch = true;
    bool shapeMatch = true;

    for (Tile tile : tileSet)
    {
        std::cout << tile.getColour() << tile.getShape() << " " << std::endl;
        if (colourMatch && tile.getColour() != colour)
        {
            colourMatch = false;
        }

        if (shapeMatch && tile.getShape() != shape)
        {
            shapeMatch = false;
        }

        // Check if duplicate tile exists
        if (tile.getColour() == colour && tile.getShape() == shape)
        {
            std::cout << "Cannot place a tile that has a duplicate in the same row or column" << std::endl;
            return false;
        }

        // Confirm there is either a colour or shape match in the row
        if (!colourMatch && !shapeMatch)
        {
            std::cout << "Either shape or colour must match the row and column" << std::endl;
            return false;
        }
    }

    return true;
}

// Validates that a players attempt to set a tile in a given location is valid within
// the bounds of the rules of qwirkle. If not, prints a warning to console and returns
// false
bool GameBoard::validateSetTile(int x, int y, Tile tile, bool firstTurn)
{
    Colour colour = tile.getColour();
    Shape shape = tile.getShape();

    vector<Tile> rowTiles = getTilesOnRow(x, y);
    vector<Tile> colTiles = getTilesOnCol(x, y);

    // Validate that no tile already exists in that space
    if (!validSpace(x, y))
    {
        std::cout << "Tile space must be within the bounds of the board" << std::endl;
        return false;
    }
    else if (getTile(x, y).getColour() != NO_COL)
    {
        std::cout << "A tile already exists in this space" << std::endl;
        return false;
    }

    // Validate that tiles have at least one adjacent tile (unless it's the first turn)
    if (rowTiles.size() <= 0 && colTiles.size() <= 0 && !firstTurn)
    {
        std::cout << "Unable to place a tile without any adjacent tiles.";
        return false;
    }

    // Validate that either Colour or Shape match both the row and column, and that no duplicate
    // tile exists
    if (!firstTurn && (!validateTileAgainstSet(rowTiles, tile) || !validateTileAgainstSet(colTiles, tile)))
    {
        return false;
    }

    return true;
}

// Takes the tile and coordinates of a players set tile and returns the resulting score. Uses the
// currentTiles list to exclude tiles already placed this turn. Assumes input has already been
// validated as within the rules
int GameBoard::getScore(int x, int y, Tile tile)
{
    int score = 0;

    std::vector<Tile> rowTiles = getTilesOnRow(x, y);
    // if rows include any tiles, add the given tile as well to include it in counting. If not,
    // don't add the tile to avoid double scoring the placed tile
    if (rowTiles.size() > 0)
    {
        rowTiles.push_back(tile);
    }
    score += rowTiles.size(); // Add a point for each tile in the row

    std::vector<Tile> colTiles = getTilesOnCol(x, y);
    if (colTiles.size() > 0)
    {
        colTiles.push_back(tile);
    }
    score += colTiles.size(); // Add a point for each tiile in the col

    // Any row of 6 elements must be a qwirkle (as no duplicate tiles can occur)
    if (colTiles.size() >= 6 or rowTiles.size() >= 6)
    {
        std::cout << "QWIRKLE!!!" << std::endl;
        score += 6;
    }

    return score;
}

// Sets the x and y coordinates of the board to the assigned Tile and returns the resulting score
// Assumes that the validateSetTile method has already passed.
int GameBoard::setTile(int x, int y, Tile tile)
{
    int score;
    try
    {
        board[x][y] = tile;

        score = getScore(x, y, tile);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return score;
}

vector<Tile> GameBoard::getTilesOnAxis(int x, int y, bool rowAxis)
{
    vector<Tile> tiles;

    int xCoord;
    int yCoord;

    bool tileExists = true;

    int modifiers[2] = {-1, 1};

    for (int mod : modifiers)
    {
        tileExists = true;
        xCoord = x;
        yCoord = y;

        // Get tiles left of coordinates
        while (xCoord >= 0 && yCoord >= 0 && xCoord < getWidth() &&
               yCoord < getHeight() && tileExists)
        {
            if (rowAxis)
            {
                xCoord += mod;
            }
            else
            {
                yCoord += mod;
            }

            if (xCoord >= 0 && yCoord >= 0 && xCoord < getWidth() && yCoord < getHeight())
            {
                Tile newTile = getTile(xCoord, yCoord);

                if (newTile.getColour() != NO_COL)
                {

                    tiles.push_back(newTile);
                }
                else
                {
                    tileExists = false;
                }
            }
        }
    }
    return tiles;
}

int GameBoard::alphabetToNumber(char letter)
{
    const unsigned int letter_to_value[] =
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

    letter = toupper(letter);
    const unsigned int index = letter - 'A';
    int value = letter_to_value[index];
    return value;
}

std::vector<Tile> GameBoard::getTilesOnRow(int x, int y)
{
    std::vector<Tile> tiles = getTilesOnAxis(x, y, true);

    return tiles;
}

std::vector<Tile> GameBoard::getTilesOnCol(int x, int y)
{
    std::vector<Tile> tiles = getTilesOnAxis(x, y, false);

    return tiles;
}

std::string GameBoard::getState()
{
    std::string state;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j].getColour() != ' ')
            {
                state += board[i][j].getColour();
                state += std::to_string(board[i][j].getShape());
                state += "@(";
                state += std::to_string(i);
                state += ",";
                state += std::to_string(j);
                state += ") ";
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

    // Print Column Numbers
    int i = 0;

    boardString.append(" "); // Print starting spacer
    while (i < getWidth())
    {
        // Keeps figures centred over columns regardless of one or two digit
        // length
        i++;
        std::stringstream colNumber;
        if (i < 10)
        {

            colNumber << " " << i << " ";
        }
        else
        {
            colNumber << " " << i;
        }
        boardString.append(colNumber.str());
    }
    boardString.append("\n");

    // Print divider
    i = 0;

    boardString.append(" "); // Print starting spacer
    while (i < getWidth())
    {
        i++;
        boardString.append("---");
    }
    boardString.append("\n");

    // Print board
    i = 0;
    for (vector<Tile> row : board)
    {
        boardString.push_back(alphabet[i]);
        i++;

        for (Tile col : row)
        {
            boardString.push_back('|');

            // Converts type to char or white space if empty tile
            char c = (col.getColour() != NO_COL) ? col.getColour() : ' ';
            std::string s = (col.getShape() == NO_SHAPE) ? " " : std::to_string(col.getShape());

            // Add characters to board
            boardString.push_back(c);
            boardString.append(s);
        }
        boardString.append("|\n");
    }
    return boardString;
}

void GameBoard::setHeight(int height)
{
    board.resize(height, vector<Tile>(board[0].size()));
}

void GameBoard::setWidth(int width)
{
    for (int i = 0; i < board.size(); i++)
    {
        board[i].resize(width);
    }
}

void GameBoard::setState(std::string &state)
{
    int width = 0, height = 0;
    int x, y;
    char color;
    int shape;
    std::stringstream ss(state);
    std::string tileString;

    while (std::getline(ss, tileString, ' '))
    {
        // Extract color, shape, x and y from the tile string
        color = tileString[0];
        shape = tileString[2] - '0';
        x = stoi(tileString.substr(4, tileString.find(",") - 4));
        y = stoi(tileString.substr(tileString.find(",") + 1, tileString.find(")") - tileString.find(",") - 1));

        // Update the height and width of the board if necessary
        height = std::max(height, x + 1);
        width = std::max(width, y + 1);
    }

    // Resize the board to the dimensions read from the input string
    board.resize(height, vector<Tile>(width));

    // Reset the stringstream and getline to the beginning of the input string
    ss.clear();
    ss.str(state);

    // Fill the board with Tile objects based on the information in the input string
    while (std::getline(ss, tileString, ' '))
    {
        color = tileString[0];
        shape = tileString[2] - '0';
        x = stoi(tileString.substr(4, tileString.find(",") - 4));
        y = stoi(tileString.substr(tileString.find(",") + 1, tileString.find(")") - tileString.find(",") - 1));
        board[x][y] = Tile(color, shape);
    }
}