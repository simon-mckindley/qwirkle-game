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

// Sets the x and y coordinates of the board to the assigned Tile.
void GameBoard::setTile(int x, int y, Tile tile)
{
    bool success = false;

    try
    {
        board[x][y] = tile;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
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
