// #include "LinkedList.h"

#include <iostream>
#include <fstream>
#include <string>

void printMainMenu();
void mainMenuOption(std::string userSelection);
void createNewGame();
void loadGame();
void printCredits();
std::string getPlayerName();
std::string getInput();
void gamePlay();
bool gamePlayOption();
void printGameStatus();

#define EXIT_SUCCESS 0

// Menu options
#define NEW_GAME "1"
#define LOAD_GAME "2"
#define CREDITS "3"
#define QUIT "4"

int main(void)
{
    std::string userSelection;

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
    std::cout << "\nStarting a new game." << std::endl;

    std::string player1;
    std::string player2;
    std::cout << "\nEnter a name for Player 1 (Uppercase characters only)" << std::endl;
    player1 = getPlayerName();
    std::cout << "\nEnter a name for Player 2 (Uppercase characters only)" << std::endl;
    player2 = getPlayerName();
    std::cout << "\nWelcome, " << player1 << " and " << player2
              << "\n\tLets Play!";

    // TODO Initialise new game 2.3.10

    gamePlay();
}

void loadGame()
{
    std::cout << "\nLoad a saved game" << std::endl;

    std::string filename;
    std::cout << "\nEnter the filename from which to load a save game" << std::endl;
    filename = getInput();
    std::cout << "\nLoading game from > " << filename << std::endl;

    // TODO Load game from file 2.2.2

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

// Accepts and validates player names
std::string getPlayerName()
{
    std::string name = "";
    bool valid;
    do
    {
        valid = true;
        name = getInput();
        for (char c : name)
        {
            if (!isupper(c))
            {
                valid = false;
                std::cout << "Invalid input" << std::endl;
                break;
            }
        }

    } while (!valid);

    return name;
}

// General purpose user input function
std::string getInput()
{
    std::string userSelection;
    std::cout << "> ";
    std::getline(std::cin, userSelection);

    if (std::cin.eof())
    {
        // Exit for testing purposes
        std::cout << "\nGoodbye" << std::endl;
        exit(EXIT_SUCCESS);
    }

    return userSelection;
}

// Main gameplay function
void gamePlay()
{
    bool endGame = false;

    do
    {
        std::cout << "\n\n<Player>"
                  << ", it's your turn";
        printGameStatus();
        endGame = gamePlayOption();

    } while (!endGame);
}

// Gets and validates user gameplay input
bool gamePlayOption()
{
    bool invalid;
    bool endGame = false;
    std::string userInput;
    do
    {
        invalid = false;
        userInput = getInput();
        int pos = userInput.find_first_of(" ");
        if (pos != std::string::npos)
        {
            // Valid input: place, replace, save
            std::string cmd = userInput.substr(0, pos);
            if (cmd == "place")
            {
                std::string tile = userInput.substr(pos + 1, 2);
                std::string location = userInput.substr(pos + 7);
                std::cout << "Place:" << tile << ":" << location << std::endl;
                // TODO validate tile and location
            }
            else if (cmd == "replace")
            {
                std::string tile = userInput.substr(pos + 1, 2);
                std::cout << "Replace:" << tile << std::endl;
                // TODO validate tile
            }
            else if (cmd == "save")
            {
                std::string fileName = userInput.substr(pos + 1);
                std::cout << "File:" << fileName << std::endl;
            }
            else
            {
                std::cout << "Invalid input" << std::endl;
                invalid = true;
            }
        }
        else if (userInput == "quit")
        {
            endGame = true;
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
            invalid = true;
        }

    } while (invalid);

    return endGame;
}

// Prints the game status a the start of each players turn
void printGameStatus()
{
    std::cout << "\nScore for "
              << "<Player1>"
              << ": "
              << "<9>";
    std::cout << "\nScore for "
              << "<Player2>"
              << ": "
              << "<9>";
    std::cout << "\nPRINT BOARD HERE" << std::endl;
    std::cout << "\nYour hand is:\n"
              << "<hand>\n"
              << std::endl;
}
