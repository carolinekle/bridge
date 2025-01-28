#include <iostream>
#include <string>
using namespace std;

int main() {
    int number;
    cout << "Enter whole number below: ";
    cin >> number;

    string star = "*";

    int times = (number * 2) - 1;


    for (int i = 0; i < number; i++) {
        for (int s = 0; s < i; s++) {
            cout << " ";
        }

        for (int k = 0; k < times; k++) {
            cout << star;
        }
        cout << "\n";
        times -= 2;
    }

    times = 1;  
   
    for (int j = number - 1; j >= 0; j--) {
        for (int s = 0; s < j; s++) {
            cout << " ";
        }

        for (int k = 0; k < times; k++) {
            cout << star;
        }
        cout << "\n";

        times += 2;
    }

    return 0;
}
    