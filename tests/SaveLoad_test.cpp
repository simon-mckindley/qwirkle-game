#include "gtest/gtest.h"
#include "GameState.h"
#include "GamePlay.h"

TEST(GameStateTest, SaveAndLoad)
{
    // Create a GameState object
    TileBag tileBag;
    tileBag.fillTileBag();
    // Creates new players and allocate hands of tiles
    std::string player1name = "Player1";
    std::string player2name = "Player2";
    Player *player1 = new Player(player1name, &tileBag);
    Player *player2 = new Player(player2name, &tileBag);

    // Creates new Gamestate object for the pointer
    Players *players = new Players(player1, player2);
    GameBoard gameBoard;
    GameState *gameState = new GameState(players, &gameBoard, &tileBag);

    // Call the save method with a file name
    std::string filename = "game_state_test.txt";
    gameState->save(filename);

    // Load the saved game state
    GameState loadedGameState;
    loadedGameState.load(filename);

    // Verify that the loaded game state has the same information as the original game state
    EXPECT_EQ(gameState->getPlayer1()->getName(), loadedGameState.getPlayer1()->getName());
    EXPECT_EQ(gameState->getPlayer1()->getScore(), loadedGameState.getPlayer1()->getScore());
    EXPECT_EQ(gameState->getPlayer1()->getHand(), loadedGameState.getPlayer1()->getHand());
    EXPECT_EQ(gameState->getPlayer2()->getName(), loadedGameState.getPlayer2()->getName());
    EXPECT_EQ(gameState->getPlayer2()->getScore(), loadedGameState.getPlayer2()->getScore());
    EXPECT_EQ(gameState->getPlayer2()->getHand(), loadedGameState.getPlayer2()->getHand());
    EXPECT_EQ(gameState->getGameBoard()->getHeight(), loadedGameState.getGameBoard()->getHeight());
    EXPECT_EQ(gameState->getGameBoard()->getWidth(), loadedGameState.getGameBoard()->getWidth());
    EXPECT_EQ(gameState->getGameBoard()->getState(), loadedGameState.getGameBoard()->getState());
    EXPECT_EQ(gameState->getCurrentPlayer()->getName(), loadedGameState.getCurrentPlayer()->getName());

    // Clean up
    delete gameState;
    delete player1;
    delete player2;
    delete players;
}
