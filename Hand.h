#ifndef ASSIGN2_Hand_H
#define ASSIGN2_Hand_H

#include "Node.h"
#include "LinkedList.h"
#include "TileBag.h"

class Hand : public LinkedList
{
public:
    Hand(TileBag *tileBag);
    ~Hand();

private:
    const int HAND_SIZE = 3;
};

#endif // ASSIGN2_Hand_H