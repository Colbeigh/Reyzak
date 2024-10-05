/**
 * Gamet.cpp created by Colby Hanna (Colby.Hanna@uleth.ca) on 2024-09-29
 */

#include "Game.hpp"

#include "Player.hpp"
#include "Spinner.hpp"
#include "2to5_Spinner.hpp"
#include "0to7_Spinner.hpp"

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>

Game::Game() {}
Game::~Game() {
    delete spinner;
}

void Game::Start() {
    Rules();
    while (player.getScore() > 0 && playing == true) {
        player.placeBet();
        Stakes(player.pbet); // change to player.bet
        SelectSpinner();
            while (player.Bust() == false || gambling == true) {
                Hit();
            }
            player.Payout();
    }
    Exit();
  }

void Game::Stakes(int bet) {
    if (bet < 25) {
        stakes = "Low";
    } else if (bet >= 25 && bet < 50) {
        stakes = "Medium";
    } else {
        stakes = "High";
    }
  }


void Game::SelectSpinner() {
    int input;

    while (true) {
        std::cout << "Please Select a Spinner" << std::endl << "1 - 2 to 5 Spinner" << std::endl;
        std::cout <<  "2 - 0 to 7 Spinner" << std::endl << "3 - Display Rules" << std::endl;
        std::cin >> input;

        if (spinner != nullptr) {
            delete spinner;
            spinner = nullptr;
        }

        if (input == '1') {
            spinner = new FiveSpinner();
            std::cout << "You have selected the 2 to 5 spinner!" << std::endl;
            break;
        } else if (input == '2') {
            spinner = new SevenSpinner();
            std::cout << "You have selected the 0 to 7 spinner!" << std::endl;
            break;
        } else if (input == '3') {
            Rules();
        }else {
            std::cout<< "That is an invalid input. Please try Again" << std::endl;
        }
    }
  }

void Game::Hit() {
    char input2;

    std::cout<< "Your current score is: " << player.pscore << std::endl;

    while (true) {
        std::cout << "Would you like to spin?" << std::endl << "1 - Yes" << std::endl << "2 - No" << std::endl << "3 - Display Rules" << std::endl;
    
        std::cin >> input2;

        input2 = std::toupper(input2);
        if (input2 == '1') {
            int rndmnum = spinner->spin(stakes);
            std::cout << "You spun " << rndmnum << "!" << std::endl;
            player.pscore += rndmnum;
            std::cout << "Your new score is " << player.pscore << std::endl;
            break;
        } else if (input2 == '2') {
            std::cout << "You decided not to spin" << std::endl;
            gambling = false;
            break;
        } else if (input2 == '3') {
            Rules();
        }
    }
  }

void Exit() {
    std::cout << "Thank's for playing!" << std::endl;
    std::cout << "You left the table with " << player.GetBalance() << " Zephy" << std::endl;

    if (player.GetBalance() <= 0) {
        std::cout << "Better luck next time" << std::endl;
    } else if (player.GetBalance() > 50) {
        std::cout << "You made a " << player.GetBalance() - 50 << " profit!" << std::endl;
    }
    playing = false;
  }

 void Rules() {
    std::ifstream inputFile("Rules.txt"); // Make sure this file exists

    if (!inputFile) {
        std::cerr << "Invalid File" << std::endl;
        return;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    inputFile.close();
}
    
    Player player;
    Spinner* spinner = nullptr;
    std::string stakes;
    bool playing = true; // used for loop in Start()
    bool gambling = true;// used for loop in Start()
    