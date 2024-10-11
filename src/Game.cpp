/**
 * Game.cpp created by Colby Hanna (Colby.Hanna@uleth.ca) on 2024-09-29
 */

#include "Game.hpp"

Game::Game() {
    current_spinner = nullptr;
    isplaying = true;
    isgambling = true;
    stakes = "";
}
Game::~Game() {
    delete current_spinner;
}

void Game::Start() {
    Rules();
    while (player.getBalance() > 0 && isplaying == true) {
        player.currentbet = 0;
        player.currentscore = 0;
        player.placeBet();
        Stakes(player.currentbet);
        selectSpinner();
            while (player.Bust() == false && isgambling == true) {
                Hit();
            }
            player.getPayout();
            Playing();
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


void Game::selectSpinner() {
    int input;

    while (true) {
        std::cout << "Please Select a Spinner\n1 - 2 to 5 Spinner\n";
        std::cout <<  "2 - 0 to 7 Spinner\n3 - Display Rules\n";
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, Try again\n";
            continue;
        }

        if (current_spinner != nullptr) {
            delete current_spinner;
            current_spinner = nullptr;
        }

        if (input == 1) {
            current_spinner = new Spinner_2to5();
            std::cout << "You have selected the 2 to 5 spinner!\n";
            break;
        } else if (input == 2) {
            current_spinner = new Spinner_0to7();
            std::cout << "You have selected the 0 to 7 spinner!\n";
            break;
        } else if (input == 3) {
            Rules();
        } else {
            std::cout<< "Invalid input, Try again\n";
        }
    }
  }

void Game::Hit() {
    int input;

    std::cout<< "\nYour current score is: " << player.currentscore << "\n";

    while (true) {
        std::cout << "Would you like to spin?\n";
        std::cout << "1 - Yes\n2 - No\n3 - Display Rules\n";
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, Try again\n";
            continue;
        }

        if (input == 1) {
            int rndmnum = current_spinner->spin(stakes);
            std::cout << "You spun " << rndmnum << "!\n";
            player.currentscore += rndmnum;
            std::cout << "Your new score is " << player.currentscore << "\n";
            break;
        } else if (input == 2) {
            std::cout << "You decided not to spin\n";
            isgambling = false;
            break;
        } else if (input == 3) {
            Rules();
        }
    }
  }

void Game::Exit() {
    std::cout << "Thank's for playing!\n";
    std::cout << "You left the table with $" << player.getBalance();
    std::cout << " Zephy\n";

    if (player.getBalance() <= 0.0) {
        std::cout << "Better luck next time\n";
    } else if (player.getBalance() > 50.0) {
        std::cout << "You made a $" << player.getBalance() - 50.0;
        std::cout << " profit!\n";
    }
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

void Game::Playing() {
    int input;
    if (player.getBalance() == 0) {
        std::cout << "Exiting\n";
        return;
    }
    while (true) {
        std::cout << "Would you like to play again?\n";
        std::cout << "1 - Yes\n2 - No\n";
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, Try again\n";
            continue;
        }

        if (input == 1) {
            isgambling = true;
            player.currentbet = 0;
            player.currentscore = 0;
            break;
        } else if (input == 2) {
            std::cout << "Exiting\n";
            isplaying = false;
            break;
        }
    }
}

    Player player;
    Spinner* current_spinner;
    std::string stakes;
    bool isplaying;
    bool isgambling;
