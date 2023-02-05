
#include <gtest/gtest.h>
#include "../Player.h"
#include "../Players.h"
#include "../TileBag.h"
#include "../Hand.h"

TEST(PlayersTest, Constructor)
{
    TileBag *tileBag = new TileBag();
    // Creates new players and allocate hands of tiles
    Player *player1 = new Player("player1", tileBag);
    Player *player2 = new Player("player2", tileBag);
    Players *players = new Players(player1, player2);
    players->setCurrentPlayer(player1);
    EXPECT_EQ(players->getCurrentPlayer()->getName(), "player1");

    if (players->getCurrentPlayer()->getName() == player1->getName())
    {
        players->setCurrentPlayer(player2);
        EXPECT_EQ(players->getCurrentPlayer()->getName(), "player2");
    }
    else
    {
        players->setCurrentPlayer(player1);
        EXPECT_EQ(players->getCurrentPlayer()->getName(), "player1");
    }
}