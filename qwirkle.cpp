// #include "LinkedList.h"

#include <iostream>
#include <fstream>
#include <string>

void printMainMenu();
void mainMenuOption(std::string userSelection);
void createNewGame();
void loadGame();
void printCredits();
std::string getInput();

#define EXIT_SUCCESS 0

// Menu options
#define NEW_GAME "1"
#define LOAD_GAME "2"
#define CREDITS "3"
#define QUIT "4"

int main(void)
{
    std::string userSelection = "";

    std::cout << "\nWelcome to Qwirkle!"
              << "\n-------------------"
              << std::endl;

    do
    {
        // Repeat until Quit is selected
        printMainMenu();

        userSelection = getInput();

        mainMenuOption(userSelection);

    } while (userSelection != QUIT);

    // LinkedList *list = new LinkedList();
    // delete list;

    return EXIT_SUCCESS;
}

void printMainMenu()
{
    std::cout << "\n--- Main Menu ---\n"
              << "1. New Game\n"
              << "2. Load Game\n"
              << "3. Credits\n"
              << "4. Quit\n"
              << std::endl;
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

void createNewGame()
{
    // TODO
    std::cout << "\nStarting a new game." << std::endl;

    std::string player1;
    std::string player2;
    std::cout << "\nEnter a name for Player 1 (Uppercase characters only)" << std::endl;
    player1 = getInput();
    std::cout << "\nEnter a name for Player 2 (Uppercase characters only)" << std::endl;
    player2 = getInput();
    std::cout << "\nWelcome, " << player1 << " and " << player2
              << "\n\tLets Play!";

    std::cout << "\n.... game play starts" << std::endl;
}

void loadGame()
{
    // TODO
    std::cout << "\nLoad a saved game" << std::endl;

    std::string filename;
    std::cout << "\nEnter the filename from which to load a save game" << std::endl;
    filename = getInput();
    std::cout << "\nLoading game from > " << filename << std::endl;

    std::cout << "\n.... game play starts" << std::endl;
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

std::string getInput()
{
    std::string userSelection;
    std::cout << "> ";
    std::cin >> userSelection;
    return userSelection;
}
