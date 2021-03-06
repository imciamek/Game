#include "Menu.h"

// Change setters for 'champion' when DB is created to set stats from DB

Menu::Menu()
   : main_menu_open{true}, exit_game{false} {
}

void Menu::mainMenu() {
    main_menu_open = !closeMainMenu();

    while (!exit_game && main_menu_open) {
        std::cout << "---------------------\n"
            << "1. New game (NOT READY YET)\n"
            << "2. Start\n" //Change to 'Continue' when DB is created
            << "0. Exit\n"
            << "---------------------\n";

        std::cout << "Select: ";
        int select {};
        std::cin >> select;

        /*if(select == 1) {
            system("CLS");
            newGame();
        }
        else */if(select == 2) {
            system("CLS");
            continueGame();
        }
        else if(select == 0) {
            system("CLS");
            exit_game = exitGame();
        }
        else {
            system("CLS");
            std::cout << "There is no choice like that.\n";
        }
    }
}
/*
void Menu::newGame() {
    main_menu_open = closeMainMenu();

    while (!exit_game && !main_menu_open) {
        std::cout << "---------------------\n"
                //<< "1. Register\n"
                << "9. Back\n"
                << "---------------------\n";

        std::cout << "Select: ";
        int select {};
        std::cin >> select;

        if(select == 1){
            Register newUser;
            newUser.registerForm();
        }
        else if(select == 9) {
            system("CLS");
            mainMenu();
        }
        else {
            system("CLS");
            std::cout << "There is no choice like that.\n";
        }
    }
}
*/
void Menu::continueGame() {
    main_menu_open = closeMainMenu();
    system("CLS");

    while (!exit_game && !main_menu_open) {
        std::cout << "---------------------\n"
            << "1. Login\n"
            << "9. Back\n"
            << "---------------------\n";

        std::cout << "Select: ";
        int select {};
        std::cin >> select;

        if(select == 1) {
            system("CLS");
            Game game;
            game.checkLogin();
            mainMenu();
        }
        else if(select == 9) {
            system("CLS");
            mainMenu();
        }
        else {
            system("CLS");
            std::cout << "There is no choice like that.\n";
        }
    }
}

bool Menu::closeMainMenu() {
    return false;
}

bool Menu::exitGame() {
    return true;
}
