#include "Player.h"
#include "TileBag.h"

Player::Player()
{
}
// Cosntructor to assign name and hand at creation.
Player::Player(std::string name, TileBag *tileBag)
{
    this->name = name;
    score = 0;
    this->tileBag = tileBag;
    this->playerHand = new Hand(tileBag);
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

void Player::addScore(int score)
{
    this->score += score;
}

std::string Player::getHand()
{
    std::string hand = "";
    for (int i = 0; i < playerHand->getSize(); i++)
    {
        if (playerHand->getTileAtIndex(i) == nullptr)
        {
            continue;
        }
        Tile *tile = playerHand->getTileAtIndex(i);
        hand += tile->getColour() + std::to_string(tile->getShape()) + ",";
    }
    // remove the last comma from the string
    hand = hand.substr(0, hand.size() - 1);
    return hand;
}
void Player::setHand(std::string hand)
{
    // playerHand = new LinkedList();
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

Hand *Player::getHandPtr()
{
    return this->playerHand;
}

void Player::setName(std::string name)
{
}

void Player::setScore(int score)
{
}
