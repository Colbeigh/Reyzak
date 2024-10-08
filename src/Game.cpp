/**
 * Game.cpp created by Colby Hanna (Colby.Hanna@uleth.ca) on 2024-09-29
 */

#include "Game.hpp"

Game::Game() {
    spinner = nullptr;
    isplaying = true; // used for loop in Start()
    isgambling = true;// used for loop in Start()
    stakes = "";
}
Game::~Game() {
    delete spinner;
}

void Game::Start() {
    Rules();
    while (player.currentscore > 0 && isplaying == true) {
        player.currentbet = 0;
        player.currentscore = 0;
        player.placeBet();
        Stakes(player.currentbet);
        SelectSpinner();
            while (player.Bust() == false || isgambling == true) {
                Hit();
            }
            isgambling = true;
            player.Payout();
    }
    Exit();
  }

void Game::Stakes(int bet) {
    if (bet < 25) {
        stakes = "Low";
    } else if (bet < 50) {
        stakes = "Medium";
    } else {
        stakes = "High";
    }
  }


void Game::SelectSpinner() {
    int input;

    while (true) {
        std::cout << "Please Select a Spinner\n1 - 2 to 5 Spinner\n";
        std::cout <<  "2 - 0 to 7 Spinner\n3 - Display Rules\n";
        std::cin >> input;

        if (spinner != nullptr) {
            delete spinner;
            spinner = nullptr;
        }

        if (input == '1') {
            spinner = new FiveSpinner();
            std::cout << "You have selected the 2 to 5 spinner!\n";
        } else if (input == '2') {
            spinner = new SevenSpinner();
            std::cout << "You have selected the 0 to 7 spinnern\n";
        } else if (input == '3') {
            Rules();
        } else {
            std::cout<< "Invalid input, Try again\n";
        }
    }
  }

void Game::Hit() {
    char input2;

    std::cout<< "Your current score is: " << player.currentscore << "\n";

    while (true) {
        std::cout << "Would you like to spin?\n";
        std::cout << "1 - Yes\n2 - No\n3 - Display Rules\n";

        std::cin >> input2;

        input2 = std::toupper(input2);
        if (input2 == '1') {
            int rndmnum = spinner->spin(stakes);
            std::cout << "You spun " << rndmnum << "!\n";
            player.currentscore += rndmnum;
            std::cout << "Your new score is " << player.currentscore << "\n";
            break;
        } else if (input2 == '2') {
            std::cout << "You decided not to spin\n";
            isgambling = false;
            break;
        } else if (input2 == '3') {
            Rules();
        }
    }
  }

void Game::Exit() {
    std::cout << "Thank's for playing!\n";
    std::cout << "You left the table with $"<< player.getBalance();
    std::cout << " Zephy\n";

    if (player.getBalance() <= 0) {
        std::cout << "Better luck next time\n";
    } else if (player.getBalance() > 50) {
        std::cout << "You made a $" << player.getBalance() - 50 << " profit!\n";
    }
    isplaying = false;
  }

void Game::Rules() {
    std::ifstream inputFile("Rules.txt");

    if (!inputFile) {
        std::cerr << "Invalid File\n";
        return;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    inputFile.close();
}

    Player player;
    Spinner* spinner;
    std::string stakes;
    bool isplaying;
    bool isgambling;
