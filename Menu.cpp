#include "Menu.h"

int Menu::userSelection()
{
    printMainMenu();

    int userSelection = 0;

    do
    {
        std::cout << "Select:" << std::endl;
        std::cin >> userSelection;
    } while (!isValidChoice(userSelection));

    return userSelection;
}