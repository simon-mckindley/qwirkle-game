#include "GameBoard.h"

GameBoard::GameBoard()
{
    // TODO: tmp values, need to decide if we add X add 0 as "NULL" palceholders
    // or define a tile constructor that takes and handles NULL's
    Tile *tmpTile = new Tile(RED, CIRCLE);
    vector<Tile> vect(26, Tile(*tmpTile));
}

GameBoard::GameBoard(vector<vector<Tile>> board)
{
    // TODO
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