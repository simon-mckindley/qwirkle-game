#include "Player.h"

Player::Player()
{
    name = "";
    score = 0;
    playerHand = new LinkedList();
}

// Cosntructor to assign name and hand at creation.
Player::Player(std::string name, LinkedList *playerHand)
{
    this->name = name;
    score = 0;
    this->playerHand = playerHand;
}

void Player::increaseScore(int score)
{
    this->score += score;
}

std::string Player::getName()
{
    return name;
}

int Player::getScore()
{
    return score;
}

std::string Player::getHand()
{
    std::string hand = "";
    for (int i = 0; i < playerHand->getSize(); i++)
    {
        Tile *tile = playerHand->getTileAtIndex(i);
        hand += tile->getColour() + std::to_string(tile->getShape()) + ",";
    }
    // remove the last comma from the string
    hand = hand.substr(0, hand.size() - 1);
    return hand;
}

void Player::setName(std::string name)
{
}

void Player::setScore(int score)
{
}

void Player::setHand(std::string hand)
{
    playerHand = new LinkedList();
    std::stringstream ss(hand);
    std::string tileString;
    while (std::getline(ss, tileString, ','))
    {
        char color = tileString[0];
        int shape = tileString[1] - '0';
        Tile *tile = new Tile(color, shape);
        playerHand->addTileToBack(tile);
    }
}
