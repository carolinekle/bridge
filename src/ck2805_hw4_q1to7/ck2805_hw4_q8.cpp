
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int a,b,c;
    srand(time(0)); 


    int secretNumber = (rand() % 100) +1;

    int numGuesses =5;

    int guess;


    while (secretNumber != guess || numGuesses == 0) {
        
        cout << "I thought of a number betweem 1 and 100! Try to guess it. \n "
        << "Range: [1, 100], number of guess left " <<numGuesses << endl;
        cout <<"Your guess: ";
        cin >> guess;
        cout << "secret: " <<secretNumber<<endl;

        if (guess > secretNumber) {
            cout << "Wrong! My number is bigger!" << endl;
            numGuesses--;
        } else {
            cout << "Wrong! My number is smaller." << endl;
            numGuesses--;
        }

    }

    cout << "Congrats!! You guessed right!!" << endl;

    return 0;
}
