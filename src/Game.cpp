// Minimal source file for a placebo class that does nothing but allows the
// pipeline to pass.

#include "Game.hpp"

#include <iostream>
#include <cctype>

Game::Game() {}

Game::~Game() {}

  void Start(){
    
  }

  void Stakes(){
    if (bet < 25){ // Change to Player.bet once implemented
        stakes = "LowStakes";
    }
    else if (bet >= 25 && bet < 50){ // Change to Player.bet once implemented
        stakes = "MediumStakes";
    }
    else{
        stakes = "HighStakes";

    }
    
  }

  void SelectSpinner(){
    char input;

    while(true) {
        std::cout << "Please Select a Spinner" << std::endl << "A - 2 to 5 Spinner" << std::endl << "B - 0 to 7 Spinner" << std::endl;
        std::cin >> input;

        input = std::toupper(input);

        if (input == 'A') {
            spinner = "2 to 5"; // update to spinner class once implemented
            std::cout << "You have selected the 2 to 5 spinner!" << std::endl;
            break;
        }
        else if (input == 'B') {
            spinner ="0 to 7"; // update to spinner class once implemented
            std::cout << "You have selected the 0 to 7 spinner!" << std::endl;
            break;
        }
        else {
            std::cout<< "That is an invalid input. Please try Again" << std::endl;
        }   
    }
  }



  void hit(){
    char input2;
    
    std::cout<< "Your current score is: " << score << std::endl; // Update to player.score once implemented
    
    while(true){
        std::cout << "Would you like to spin?  Y/N" << std::endl;
        std::cin >> input2;

        input2 = std::toupper(input2);
        if (input2 == 'Y'){
            int rndmnumber = spin(stakes, spinner);  // change to how we call spin
            std::cout << "You spun " << rndmnumber << "!" << std::endl;
            score += rndmnumber; // Update to player.score once implemented
            std::cout << "Your new score is " << score << std::endl; // Update to player.score once implemented
            break;
        }
        else if (input2 == 'N'){
            break;
        }
        else{
            std::cout<< "Invalid input" << std::endl;
        }
    }
  }

  void Exit(){


  }

  void Payout(){


  }


    std::string spinner; // update to spinner class once implemented
    std::string stakes;
    int bet; // will be deleted
    int score = 0; // will be deleted
    int current_score = 0; // will be deleted

