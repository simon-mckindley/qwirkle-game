
#include "GameBoard.h"

GameBoard::GameBoard()
{
    // TODO
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
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j].getColour() != ' ')
            {
                state.push_back(board[i][j].getColour() + std::to_string(board[i][j].getShape()) + "@(" + std::to_string(i) + "," + std::to_string(j) + ")");
            }
        }
    }
    return state;
}