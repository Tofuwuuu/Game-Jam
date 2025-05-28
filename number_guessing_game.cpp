#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main() {
    // Seed for random number generation
    srand(static_cast<unsigned int>(time(nullptr)));
    
    int secretNumber, userGuess, attempts;
    char playAgain;
    
    std::cout << "=== NUMBER GUESSING GAME ===" << std::endl;
    
    do {
        // Generate random number between 1 and 100
        secretNumber = rand() % 100 + 1;
        attempts = 0;
        
        std::cout << "\nI've chosen a number between 1 and 100." << std::endl;
        std::cout << "Try to guess it!" << std::endl;
        
        do {
            std::cout << "\nEnter your guess: ";
            
            // Input validation
            while (!(std::cin >> userGuess)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number: ";
            }
            
            attempts++;
            
            if (userGuess < secretNumber) {
                std::cout << "Too low! Try again." << std::endl;
            } else if (userGuess > secretNumber) {
                std::cout << "Too high! Try again." << std::endl;
            } else {
                std::cout << "\nCongratulations! You guessed the number in " << attempts << " attempts!" << std::endl;
            }
            
        } while (userGuess != secretNumber);
        
        std::cout << "\nDo you want to play again? (y/n): ";
        std::cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    std::cout << "\nThanks for playing! Goodbye!" << std::endl;
    
    return 0;
} 