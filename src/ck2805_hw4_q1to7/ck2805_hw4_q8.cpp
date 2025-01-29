
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); 


    int secretNumber = (rand() % 100) +1;

        int bottomRange = 1;
        int topRange = 100;

    int numGuesses =5;

    int guess;


    while (numGuesses >0 ) {

        if(secretNumber == guess){
            cout << "Congrats!! You guessed right!!" << endl;
            break;
        }
        
        if(secretNumber!=guess && numGuesses ==0){
            cout << "You have run out of guess. The number I picked is: " << secretNumber << endl;
            break;
        }

        if (numGuesses == 5){

            cout << "I thought of a number betweem 1 and 100! Try to guess it."<< endl;
            cout<<"Range: [" <<bottomRange<<", " << topRange<<"], number of guess left " <<numGuesses << endl;
            cout <<"Your guess: ";
            cin >> guess;

        }else{ 

            cout<<"Range: [" <<bottomRange<<", " << topRange<<"], number of guess left " <<numGuesses << endl;
            cout <<"Your guess: ";
            cin >> guess;

        }
    

        if (guess > secretNumber) {
            cout << "Wrong! My number is smaller!" << endl;
            topRange =guess-1;
            numGuesses--;
        } else {
            cout << "Wrong! My number is bigger." << endl;
            bottomRange =guess+1;
            numGuesses--;
        }


    }


    return 0;
}
