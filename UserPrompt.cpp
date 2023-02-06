#include "UserPrompt.h"

#include <string>

// General purpose user input function
std::string UserPrompt::getInput()
{
    std::string userInput;
    std::cout << "> ";
    std::getline(std::cin, userInput);

    if (std::cin.eof())
    {
        // Exit for testing purposes
        std::cout << "\nGoodbye" << std::endl;
        exit(EXIT_SUCCESS);
    }

    return userInput;
}