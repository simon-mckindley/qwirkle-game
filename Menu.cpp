#include "Menu.h"
#include "UserPrompt.h"

std::string Menu::userSelection()
{
    UserPrompt userPrompt;

    printMainMenu();

    std::string userSelection = userPrompt.getInput();

    return userSelection;
}