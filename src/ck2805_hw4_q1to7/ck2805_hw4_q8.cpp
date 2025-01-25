/*
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int secretNumber;
    srand(time(NULL)); // Seed the random number generator
    secretNumber = rand() % 20 + 1; // Random number between 1 and 20
    int guess;

    cout << "Enter a whole number: ";
    cin >> guess;

    while (secretNumber != guess) {
        if (guess > secretNumber) {
            cout << "Your guess is higher than the number!" << endl;
        } else {
            cout << "Your guess is lower than the number!" << endl;
        }
        cout << "Enter another guess: ";
        cin >> guess;
    }

    // This executes when the user guesses correctly
    cout << "Congrats!! You guessed right!!" << endl;

    return 0;
}
*/