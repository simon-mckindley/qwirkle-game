
#include <gtest/gtest.h>
#include "../Player.h"
#include "../TileBag.h"
#include "../Hand.h"

TEST(PlayerTest, Constructor)
{
    TileBag *tileBag = new TileBag();
    tileBag->fillTileBag();

    Hand *hand = new Hand(tileBag);
    const int MAX_HAND_SIZE = hand->getSize();

    Player *playerOne = new Player("P1", tileBag);

    ASSERT_TRUE(playerOne->getHandPtr()->getSize() == MAX_HAND_SIZE);
}