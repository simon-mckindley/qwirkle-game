#include "TileBag.h"
#include <iostream>

TileBag::TileBag()
{
    setHead(nullptr);
    setTail(nullptr);
}

TileBag *TileBag::fillTileBag()
{
    std::cout << "Filling Tile Bag..." << std::endl;
    const Shape shapes[6] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER};
    const Colour colours[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};

    // for (int i = 0; i < 2; i++)
    // {
    //     for (Shape shape : shapes)
    //     {
    //         for (Colour colour : colours)
    //         {
    //             Tile *newTile = new Tile(colour, shape);
    //             this->addTileAtIndex(getRandomDigit(this->getSize()), newTile);
    //         }
    //     }
    // }

    this->addTileToBack(new Tile(RED, CIRCLE));
    this->addTileToBack(new Tile(ORANGE, CIRCLE));
    this->addTileToBack(new Tile(YELLOW, CIRCLE));
    this->addTileToBack(new Tile(GREEN, CIRCLE));
    this->addTileToBack(new Tile(BLUE, CIRCLE));
    this->addTileToBack(new Tile(PURPLE, CIRCLE));

    this->addTileToBack(new Tile(RED, CIRCLE));
    this->addTileToBack(new Tile(ORANGE, CIRCLE));
    this->addTileToBack(new Tile(YELLOW, CIRCLE));
    this->addTileToBack(new Tile(GREEN, CIRCLE));
    this->addTileToBack(new Tile(BLUE, CIRCLE));
    this->addTileToBack(new Tile(PURPLE, CIRCLE));

    // std::cout << "\tSize: " << this->getSize() << std::endl;
    // printBag();

    return this;
}

// Remove and return the tile chosen by the player.
Tile *TileBag::replaceTile(Tile *tileToReplace)
{
    // Put the old tile back in the tile bag (add to back)
    this->addTileToBack(tileToReplace);
    // Draw a new tile from the tile bag (remove from front)
    return this->drawTile();
}

// Print bag - for testing purposes
void TileBag::printBag()
{
    for (int i = 0; i < this->getSize(); i++)
    {
        std::cout << this->getTileAtIndex(i)->getColour() << this->getTileAtIndex(i)->getShape() << ", ";
    }
}

int TileBag::getRandomDigit(int max)
{
    if (max <= 0)
    {
        max = 1;
    }

    return rand() % max;
}