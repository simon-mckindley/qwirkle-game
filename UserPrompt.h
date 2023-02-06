#ifndef ASSIGN2_USERPROMPT_H
#define ASSIGN2_USERPROMPT_H

#include "Tile.h"

#include <iostream>
#include <fstream>
#include <string>

#define EXIT_SUCCESS 0

class UserPrompt
{
public:
    std::string getInput();
};

#endif // ASSIGN2_USERPROMPT_H