#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    int sp, num_range, real_num, guess_num, guess_count = 0;
    int last_game_attempts = 0; // Variable to store the number of attempts in the last game

    while (true) {
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "-------------------- WELCOME TO NUMBER GUESSING GAME --------------------" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "Choose one option ---> " << "\n" << endl;
        cout << "1.>>> Play the Game >>>" << endl;
        cout << "2.>>> See the Last Game Score >>>" << endl;
        cout << "3.>>> Exit from the Game >>>" << endl;
        cout << "\n" << "Enter Your Option : ";
        cin >> sp;

        switch (sp) {
            case 1: {
                cout << "\nLet's Start the Game...\n" << endl;
                guess_count = 1;  // Reset guess count for the new game

                cout << "-------------------------- NUMBER GUESSING GAME -------------------------" << endl;
                cout << "\nEnter the range of the numbers: ";
                cin >> num_range;

                // Random number generation within the range of [1, num_range]
                srand(time(0));  // Initialize random seed
                real_num = rand() % num_range + 1;  // Random number between 1 and num_range
                
                // Debugging: You can uncomment the next line to check the real number
                // cout << "Debug: Real number is " << real_num << endl;

                // Play the guessing game
                while (true) {
                    cout << "\nEnter your guess number: ";
                    cin >> guess_num;

                    if (guess_num > real_num) {
                        guess_count += 1;
                        cout << "The number is lower than your guess..." << endl;
                    } else if (guess_num < real_num) {
                        guess_count += 1;
                        cout << "The number is higher than your guess..." << endl;
                    } else {
                        // User guessed correctly
                        cout << "\nGreat! You guessed the correct number...!!!" << endl;

                        if (guess_count == 1) {
                            cout << "You guessed the number in " << guess_count << "st Try.!!!" << "\n" << endl;
                        } else {
                            cout << "You guessed the number in " << guess_count << " Tries...!" << "\n" << endl;
                        }

                        last_game_attempts = guess_count;  // Store attempts for the last game
                        break;  // Exit the loop after the correct guess
                    }
                }
                break;
            }
            case 2: {
                // Display the score from the last game
                if (last_game_attempts == 0) {
                    cout << "\nYou haven't played the game once yet...\n" << endl;
                } else if (last_game_attempts == 1) {
                    cout << "\nIn the Last Game, you won the game in " << last_game_attempts << "st Try...!\n" << endl;
                } else {
                    cout << "\nIn the Last Game, you won the game in " << last_game_attempts << " Tries...\n" << endl;
                }
                break;
            }
            case 3: {
                // Exit the game
                cout << "\nThanks for Playing the Game...!" << "\n" << endl;
                return 0;
            }
            default:
                // Invalid option input
                cout << "\nInvalid Option Choice... Please Try Again..." << "\n" << endl;
                break;
        }
    }

    return 0;
}
