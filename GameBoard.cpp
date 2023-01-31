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