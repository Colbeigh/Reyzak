/**
 * Gamet.cpp created by Colby Hanna (Colby.Hanna@uleth.ca) on 2024-09-29
 */

#include "Game.hpp"

#include "Player.hpp"
#include "Spinner.hpp"
#include "Payout.hpp"

#include <iostream>
#include <cctype>

Game::Game() {} // I believe unneccesary in //this class to further implement just going to use default
Game::~Game() {} // I believe unneccesary in //this class to further implement just going to use default

  void Start() {
    while (zephy > 0 || playing == true) { // change to player.wallet.zephy
        player.PlaceBet();
        Stakes(bet); // change to player.bet
        SelectSpinner();
            while (player.bust() == false || gambling == true) {
                hit();
            }
            payout.Payout(player.pscore, player.bet, player.wallet.zephy); // calls payout function can change to whatever we decide to call it or we can implement into however we want
            current_score = 0; // Change to player.score or Player.CurrentScore or whatever we call it
    }
    Exit();
  }

  void Stakes(int bet) {
    if (bet < 25) { // Change to Player.bet once implemented
        stakes = 0;
    } else if (bet >= 25 && bet < 50) { // Change to Player.bet once implemented
        stakes = 1;
    } else {
        stakes = 2;
    }
  }


  void SelectSpinner() {
    char input;

    while (true) {
        std::cout << "Please Select a Spinner" << std::endl << "A - 2 to 5 Spinner" << std::endl << "B - 0 to 7 Spinner" << std::endl;
        std::cin >> input;

        input = std::toupper(input);

        if (input == 'A') {
            spinner = "2 to 5"; // update to spinner class once implemented
            std::cout << "You have selected the 2 to 5 spinner!" << std::endl;
            break;
        } else if (input == 'B') {
            spinner ="0 to 7"; // update to spinner class once implemented
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
    std::cout << "You left the table with " << zephy << " Zephy" << std::endl; // replace with Player.zephy

    if (zephy <= 0) {
        std::cout << "Better luck next time" << std::endl;
    } else if Low(zephy > 50) { // replace with Player.zephy
        std::cout << "You made a " << zephy - 50 << " profit!" << std::endl; // replace with Player.zephy
    }
    playing = false;
  }

  void Payout() {// We might not use so have not implemented
  }


    std::string spinner; // update to spinner class once implemented
    enum stakes{low, medium, high};
    int bet; // will be deleted
    int score = 0; // will be deleted
    int current_score = 0; // will be deleted
    int zephy = 50; // will be deleted
    bool playing = true; // used for loop in Start()
    bool gambling = true;// used for loop in Start()
    

 