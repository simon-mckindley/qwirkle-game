#include "LinkedList.h"
#include "Menu.h"
#include "GameState.h"
#include "UserPrompt.h"

#include <iostream>
#include <fstream>
#include <string>

// TODO: Consider creating a gameState object with default values for
// createGame, or load values into gameState with loadGame();
// GameState createNewGame();
void createNewGame();
// GameState loadGameState();
void loadGame();
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
        createNewGame();
    }
    else if (userSelection == LOAD_GAME)
    {
        loadGame();
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

// GameState createNewGame()
void createNewGame()
{
    // TODO
    UserPrompt userPrompt;

    std::cout << "Starting a new game." << std::endl;
    std::string username;
    std::cout << "Select your username" << std::endl;
    username = userPrompt.getInput();
    std::cout << "Welcome, " << username << std::endl;
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

// TODO: Consider replacing with a gameState method instead
void loadGame()
{
    // TODO
    UserPrompt userPrompt;
    std::cout << "Starting a new game." << std::endl;

    std::string filename;
    std::cout << "Enter the filename of the game you wish to load:" << std::endl;
    filename = userPrompt.getInput();
}
<<<<<<< HEAD

bool isValidChoice(int userSelection)
{
    // Is one of the 4 menu options
    if (userSelection >= 1 && userSelection <= 4)
    {
        return true;
    }

    return false;
}
=======
>>>>>>> origin/Menu
