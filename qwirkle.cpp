#include "LinkedList.h"
#include "Menu.h"
#include "GameState.h"

#include <iostream>
#include <fstream>
#include <string>

// TODO: Consider creating a gameState object with default values for
// createGame, or load values into gameState with loadGame();
// GameState createNewGame();
void createNewGame();
// GameState loadGameState();
void loadGame();

void mainMenuOption(int userSelection);
void printCredits();

#define EXIT_SUCCESS 0

int main(void)
{
    // Initialize menu.
    //
    // TODO: Given C++ has no static classes, is there a better
    // way to implement a stateless class than making it concrete and having
    // to instantiating it?
    int choice = 0;
    Menu menu;
    do
    {
        choice = menu.userSelection();
        mainMenuOption(choice);
    } while (true);

    // Never actually reaches this
    // TODO: Either bring the code back into qwirkle.cpp
    // Or move the rest into Menu and have it return only a call to only a
    // valid response?
    LinkedList *list = new LinkedList();
    delete list;

    return EXIT_SUCCESS;
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

// GameState createNewGame()
void createNewGame()
{
    // TODO

    //
    std::cout << "Starting a new game." << std::endl;

    std::string username;
    std::cout << "Select your username" << std::endl;
    std::cin >> username;
    std::cout << "Welcome, " << username << std::endl;
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

// TODO: Consider replacing with a gameState method instead
void loadGame()
{
    // TODO
    std::cout << "Starting a new game." << std::endl;

    std::string filename;
    std::cout << "Enter the filename of the game you wish to load:" << std::endl;
    std::cin >> filename;
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