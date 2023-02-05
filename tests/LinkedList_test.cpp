
#include <gtest/gtest.h>
#include "../Player.h"
#include "../TileBag.h"
#include "../Hand.h"
#include "../Node.h"
#include "../LinkedList.h"

TEST(LinkedListTest, Constructor)
{
    TileBag *tileBag = new TileBag();
    tileBag->fillTileBag();

    Hand *hand = new Hand(tileBag);
    const int maxBagSize = TileBag::MAX_BAG_SIZE;
    const int maxHandSize = Hand::HAND_SIZE;
    EXPECT_TRUE(maxBagSize == 25);

    // // Remove head
    hand->removeItemFromList(hand->getHead());
    EXPECT_TRUE(maxHandSize - 1);

    // // Remove tail
    hand->removeItemFromList(hand->getTail());
    EXPECT_TRUE(maxHandSize - 2);

    // // Remove middle
    hand->removeItemFromList(hand->getHead()->next);
    EXPECT_TRUE(maxHandSize - 3);
}