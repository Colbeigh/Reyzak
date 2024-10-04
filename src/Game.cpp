/**
 * Gamet.cpp created by Colby Hanna (Colby.Hanna@uleth.ca) on 2024-09-29
 */

#include "Game.hpp"

#include "Player.hpp"
#include "Spinner.hpp"

#include <iostream>
#include <cctype>

Game::Game() {} // I believe unneccesary in //this class to further implement just going to use default
Game::~Game() {} // I believe unneccesary in //this class to further implement just going to use default

  void Start() {
    while (zephy > 0 || playing == true) { // change to player.wallet.zephy
        Player.PlaceBet();
        Stakes(bet); // change to player.bet
        SelectSpinner();
            while (player.bust() == false || gambling == true) {
                hit();
            }
            Player.Payout();
    }
    Exit();
  }

  void Stakes(int bet) {
    if (bet < 25) { // Change to Player.bet once implemented
        stakes = "Low";
    } else if (bet >= 25 && bet < 50) { // Change to Player.bet once implemented
        stakes = "Medium";
    } else {
        stakes = "High";
    }
  }


  void SelectSpinner() {
    char input;

    while (true) {
        std::cout << "Please Select a Spinner" << std::endl << "A - 2 to 5 Spinner" << std::endl << "B - 0 to 7 Spinner" << std::endl;
        std::cin >> input;

        input = std::toupper(input);

        if (input == 'A') {
            spinner = new FiveSpinner(); // update to spinner class once implemented
            std::cout << "You have selected the 2 to 5 spinner!" << std::endl;
            break;
        } else if (input == 'B') {
            spinner = new SevenSpinner(); // update to spinner class once implemented
            std::cout << "You have selected the 0 to 7 spinner!" << std::endl;
            break;
        } else {
            std::cout<< "That is an invalid input. Please try Again" << std::endl;
        }
    }
  }

  void hit() {
    char input2;

    std::cout<< "Your current score is: " << score << std::endl; // Update to player.score once implemented

    while (true) {
        std::cout << "Would you like to spin?  Y/N" << std::endl;
        std::cin >> input2;

        input2 = std::toupper(input2);
        if (input2 == 'Y') {
            int rndmnum = Spinner.spin(stakes);  // change to how we call spin
            std::cout << "You spun " << rndmnum << "!" << std::endl;

            player.score += rndmnum; // Update to player.score once implemented
            std::cout << "Your new score is " << score << std::endl; // Update to player.score once implemented
            break;
        } else if (input2 == 'N') {
            gambling = false; 
    }
    }
  }

  void Exit() {
    std::cout << "Thank's for playing!" << std::endl;
    std::cout << "You left the table with " << Player.GetBalance() << " Zephy" << std::endl; // replace with Player.zephy

    if (Player.GetBalance() <= 0) {
        std::cout << "Better luck next time" << std::endl;
    } else if (Player.GetBalance() > 50) { // replace with Player.zephy
        std::cout << "You made a " << Player.GetBalance() - 50 << " profit!" << std::endl; // replace with Player.zephy
    }
    playing = false;
  }



    Spinner* spinner; // update to spinner class once implemented
    std::string stakes;


    int bet; // will be deleted
    int score = 0; // will be deleted
    int current_score = 0; // will be deleted
    int zephy = 50; // will be deleted
    bool playing = true; // used for loop in Start()
    bool gambling = true;// used for loop in Start()
    

 