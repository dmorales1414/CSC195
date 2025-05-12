#include <iostream>

#include <cstdlib>
#include <ctime>
using namespace std;

// Declared Methods
int difficulty(int difficulty);
int guessingGame(int difficulty);

int main()
{
    // Fixed variables
    const int rounds = 5; // Only 5 rounds are allowed
    bool win = false;

    // Console Input/Output
    try {
        int difficultyInput = 0;

        // Checks if the user chose between 1-3
        while (true) {
            std::cout << "Select Difficulty: \n1. Easy \n2. Medium \n3. Hard \n";
            std::cin >> difficultyInput;

            // this is to prevent a non-stop loop when user selects anything other than a number
            if (std::cin.fail()) {
                std::cin.clear(); // will manually clear the error state
                std::cin.ignore(1000, '\n'); // discards invalid input, such as a letter than a number
                std::cout << "Invalid Input. Please choose 1, 2, or 3. \n";
                continue;
            }

            if (difficultyInput >= 1 && difficultyInput <= 3) {
                break;
            }
            else {
                std::cout << "Number out of range. Please enter 1, 2, or 3\n";
            }
        }

        int selectDifficulty = difficulty(difficultyInput);

        if (difficultyInput == 1) {
            std::cout << "You've chosen Easy difficulty";
        }
        else if (difficultyInput == 2) {
            std::cout << "You've chosen Medium difficulty";
        }
        else if (difficultyInput == 3){
            std::cout << "You've chosen Hard difficutly";
        }

        // Making the random winning number
        srand(time(0)); // Seed random number generator
        int winningNumber = rand() % selectDifficulty + 1; // Random number from 1 to (based on the difficulty chosen)

        // The Game Now Starts
        std::cout << "\nLet The Guessing Game Begin  \n";

        // A for loop in which the game is stored in.
        for (int i = 1; i <= rounds; i++) {
            std::cout << "Round " << i << " of " << rounds;
            std::cout << ": \nGuess a number between 1 and " << selectDifficulty << " : ";
            int guessedNumber = guessingGame(selectDifficulty);

            if (guessedNumber == -1) {
                i--; // Repeats the current round is input is invalid
                continue;
            }

            if (guessedNumber > winningNumber) {
                std::cout << "Too High. Try Again. \n";
            }
            else if (guessedNumber < winningNumber) {
                std::cout << "Too Low. Try Again. \n";
            }
            else {
                std::cout << "You Win!";
                win = true;
                break;
            }
        }

        if (win == false) {
            std::cout << "You lose. The answer was " << winningNumber;
        }
    }
    catch (exception e) {
        std::cout << "Something went wrong.Try again\n";
    }
    
    return 0;
}

// A method to get the range of numbers depending on the selected difficulty
int difficulty(int difficulty)
{
    switch (difficulty)
    {
    case 1:
        return 10;
        break;
    case 2:
        return 50;
        break;
    case 3:
        return 100;
        break;
    default:
        return 10; // In case it doesn't work, the fallout plan is choosing Easy
        break;
    };
}

// A method in which validates the user's answer
int guessingGame(int difficulty)
{
    try {
        int guessInput;
        std :: cin >> guessInput; // Receives the user input
        if (guessInput >= 1 && guessInput <= difficulty) {
            return guessInput;
        }
        else {
            std::cout << "Out of bounds! Please select a number within 1 and " << difficulty;
            std::cout << "\n";
        }
    }
    catch (exception e) {
        std :: cout << "Invalid Input. Please Try Valid Number";
    }
    return -1; // Returns a -1 to make the user reselect their answer and repeat the round
}