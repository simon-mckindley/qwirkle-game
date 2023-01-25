#include "GameState.h"

// Takes a filepath and stores a saved game state at the designated path.
// Returns true if succesful or false if fails
//
// TODO: It's a bit of work overhead, but it might be better to make a custom
// "saveGameFailure" exception and throw that?
bool GameState::saveGame(std::string filepath)
{
    // TODO
    return true;
}

// Takes a filepath to an existing file, reads file to construct GameState and
// returns GameState
GameState GameState::loadGame(std::string filepath) {
    GameState* newGameState = new GameState();
    return *newGameState;
}