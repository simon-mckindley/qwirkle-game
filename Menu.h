
#ifndef ASSIGN2_MENU_H
#define ASSIGN2_MENU_H

#include <iostream>
#include <fstream>
#include <string>

// Menu options
#define NEW_GAME "1"
#define LOAD_GAME "2"
#define CREDITS "3"
#define QUIT "4"

class Menu
{
public:
    std::string userSelection();

private:
    void printMainMenu()
    {
        std::cout << "\n--- Main Menu ---\n"
                  << "1. New Game\n"
                  << "2. Load Game\n"
                  << "3. Credits\n"
                  << "4. Quit\n"
                  << std::endl;
    }
};

#endif // ASSIGN2_MENU_H
