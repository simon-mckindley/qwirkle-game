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
    const static int HAND_SIZE = 6;

private:
};

#endif // ASSIGN2_Hand_H