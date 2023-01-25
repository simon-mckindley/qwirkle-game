
#ifndef ASSIGN2_MENU_H
#define ASSIGN2_MENU_H

#include "Tile.h"

#include <iostream>
#include <fstream>
#include <string>

class Menu
{
public:
    int userSelection();

private:
    void printMainMenu()
    {
        std::cout << "---Main Menu---" << std::endl;
        std::cout << "1. New Game" << std::endl;
        std::cout << "2. Load Game" << std::endl;
        std::cout << "3. Credits (Show student information)" << std::endl;
        std::cout << "4. Quit" << std::endl;
    }

    bool isValidChoice(int userSelection)
    {
        // Is one of the 4 menu options
        if (userSelection >= 1 && userSelection <= 4)
        {
            return true;
        }

        return false;
    }
};

#endif // ASSIGN2_MENU_H
