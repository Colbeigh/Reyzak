/**
 * Gamet.cpp created by Colby Hanna (Colby.Hanna@uleth.ca) on 2024-09-29
 */

#include "Game.hpp"

#include "Player.hpp"
#include "Spinner.hpp"

#include <iostream>
#include <cctype>

Game::Game() {}
Game::~Game() {
    delete spinner;
}

  void Game::Start() {
    while (player.getScore() > 0 && playing == true) {
        player.placeBet();
        Stakes(player.pbet); // change to player.bet
        SelectSpinner();
            while (player.Bust() == false || gambling == true) {
                hit();
            }
            player.Payout();
    }
    Exit();
  }

  void Game::Stakes(int bet) {
    if (bet < 25) { // Change to Player.bet once implemented
        stakes = "Low";
    } else if (bet >= 25 && bet < 50) { // Change to Player.bet once implemented
        stakes = "Medium";
    } else {
        stakes = "High";
    }
  }


  void Game::SelectSpinner() {
    char input;

    while (true) {
        std::cout << "Please Select a Spinner" << std::endl << "A - 2 to 5 Spinner" << std::endl << "B - 0 to 7 Spinner" << std::endl;
        std::cin >> input;

        input = std::toupper(input);

        if (spinner != nullptr) {
            delete spinner;
            spinner = nullptr;
        }

        if (input == 'A') {
            spinner = new FiveSpinner();
            std::cout << "You have selected the 2 to 5 spinner!" << std::endl;
            break;
        } else if (input == 'B') {
            spinner = new SevenSpinner();
            std::cout << "You have selected the 0 to 7 spinner!" << std::endl;
            break;
        } else {
            std::cout<< "That is an invalid input. Please try Again" << std::endl;
        }
    }
  }

  void Game::hit() {
    char input2;

    std::cout<< "Your current score is: " << player.score << std::endl;

    while (true) {
        std::cout << "Would you like to spin?  Y/N" << std::endl;
        std::cin >> input2;

        input2 = std::toupper(input2);
        if (input2 == 'Y') {
            int rndmnum = spinner.spin(stakes);
            std::cout << "You spun " << rndmnum << "!" << std::endl;

            player.currentScore += rndmnum;
            std::cout << "Your new score is " << player.score << std::endl;
            break;
        } else if (input2 == 'N') {
            gambling = false; 
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


    Player player;
    Spinner* spinner = nullptr;
    std::string stakes;
    bool playing = true; // used for loop in Start()
    bool gambling = true;// used for loop in Start()
    