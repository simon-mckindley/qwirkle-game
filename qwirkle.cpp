#include "LinkedList.h"
#include "Menu.h"
#include "GameState.h"
#include "GamePlay.h"
#include "UserPrompt.h"

#include <iostream>
#include <fstream>
#include <string>

void mainMenuOption(std::string userSelection);
void printCredits();

#define EXIT_SUCCESS 0

int main(void)
{
    std::cout << "\nWelcome to Qwirkle!\n"
              << "-------------------" << std::endl;

    std::string choice;
    Menu menu;

    do
    {
        choice = menu.userSelection();
        mainMenuOption(choice);

    } while (choice != QUIT);

    LinkedList *list = new LinkedList();
    delete list;

    return EXIT_SUCCESS;
}

// Calls the correct method depending on the user option entered
void mainMenuOption(std::string userSelection)
{
    if (userSelection == NEW_GAME)
    {
        GamePlay gamePlay;
        gamePlay.createNewGame();
    }
    else if (userSelection == LOAD_GAME)
    {
        GamePlay gamePlay;
        gamePlay.loadGame();
    }
    else if (userSelection == CREDITS)
    {
        printCredits();
    }
    else if (userSelection == QUIT)
    {
        std::cout << "Exiting game...\nGoodbye" << std::endl;
    }
    else
    {
        std::cout << "Valid option not selected" << std::endl;
    }
}

void printCredits()
{
    std::cout << "\n--------- Developers ---------\n"
              << std::endl;

    // Create a text string, which is used to output the text file
    std::string myText;
    int i = 1;

    // Read from the text file
    std::ifstream MyReadFile("credits.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText))
    {
        // Output the text from the file
        if (i == 1)
        {
            std::cout << "Name: " << myText << std::endl;
            i++;
        }
        else if (i == 2)
        {
            std::cout << "Student ID: " << myText << std::endl;
            i++;
        }
        else if (i == 3)
        {
            std::cout << "Email: " << myText << "\n"
                      << std::endl;
            i = 1;
        }
    }

    // Close the file
    MyReadFile.close();
    std::cout << "------------------------------" << std::endl;
}

