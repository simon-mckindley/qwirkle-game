#include "LinkedList.h"
#include "GamePlay.h"
#include "UserPrompt.h"

#include <iostream>
#include <fstream>
#include <string>

void printMainMenu();
void mainMenuOption(std::string userSelection);
void printCredits();

#define EXIT_SUCCESS 0

// Menu options
#define NEW_GAME "1"
#define LOAD_GAME "2"
#define CREDITS "3"
#define QUIT "4"

int main(void)
{
    std::cout << "\nWelcome to Qwirkle!\n"
              << "-------------------" << std::endl;

    std::string choice;
    UserPrompt userPrompt;

    do
    {
        printMainMenu();
        choice = userPrompt.getInput();
        mainMenuOption(choice);

    } while (choice != QUIT);

    LinkedList *list = new LinkedList();
    delete list;

    // TODO: Delete the below code, used as a demo of the GameBoard, setTile
    // and toString() features.

    // GameBoard gameBoard;

    // Tile *tile = new Tile(RED, CIRCLE);
    // Tile *tile2 = new Tile(BLUE, CIRCLE);
    // Tile *tile3 = new Tile(GREEN, CIRCLE);

    // Tile *tile4 = new Tile(BLUE, SQUARE);
    // Tile *tile5 = new Tile(BLUE, DIAMOND);
    // Tile *tile6 = new Tile(BLUE, STAR_4);

    // gameBoard.setTile(2, 2, *tile);
    // gameBoard.setTile(2, 3, *tile2);
    // gameBoard.setTile(2, 4, *tile3);

    // gameBoard.setTile(3, 3, *tile4);
    // gameBoard.setTile(4, 3, *tile5);
    // gameBoard.setTile(5, 3, *tile6);

    // std::string boardString = gameBoard.toString();
    // std::cout << boardString << std::endl;

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
