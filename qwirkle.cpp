#include "LinkedList.h"

#include <iostream>
#include <fstream>
#include <string>

void printMainMenu();
void mainMenuOption(int userSelection);
void createNewGame();
void loadGame();
void printCredits();
bool isValidChoice(int userSelection);

#define EXIT_SUCCESS 0

int main(void)
{
    // No selection has been made yet
    int userSelection = 0;

    printMainMenu();
    // Repeat until valid selection is made
    do
    {
        std::cout << "Select:" << std::endl;
        std::cin >> userSelection;
    } while (!isValidChoice(userSelection));

    mainMenuOption(userSelection);

    LinkedList *list = new LinkedList();
    delete list;

    return EXIT_SUCCESS;
}

void printMainMenu()
{

    std::cout << "---Main Menu---" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Credits (Show student information)" << std::endl;
    std::cout << "4. Quit" << std::endl;
}

void mainMenuOption(int userSelection)
{
    switch (userSelection)
    {

    case 1:
        createNewGame();
        break;

    case 2:
        loadGame();
        break;

    case 3:
        printCredits();
        break;

    case 4:
        std::cout << "Exiting game" << std::endl;
        exit(0);
        break;

    default:
        std::cout << "Valid choice not selected" << std::endl;
    }
}

void createNewGame()
{
    // TODO
    std::cout << "Starting a new game." << std::endl;

    std::string username;
    std::cout << "Select your username" << std::endl;
    std::cin >> username;
    std::cout << "Welcome, " << username << std::endl;
}

void loadGame()
{
    // TODO
    std::cout << "Starting a new game." << std::endl;

    std::string filename;
    std::cout << "Enter the filename of the game you wish to load:" << std::endl;
    std::cin >> filename;
}

void printCredits()
{
    std::cout << "--- Developers --- " << std::endl;

    // Create a text string, which is used to output the text file
    std::string myText;

    // Read from the text file
    std::ifstream MyReadFile("credits.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText))
    {
        // Output the text from the file
        std::cout << myText << std::endl;
    }

    // Close the file
    MyReadFile.close();
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