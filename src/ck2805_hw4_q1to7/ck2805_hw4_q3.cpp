#include <iostream>
#include <string>
using namespace std;

int main() {
    int number;
    string bin = "";

    cout << "Enter a whole number: ";
    cin >> number;

    while (number > 0) {
        int remainder = number % 2; 
        bin = to_string(remainder) + bin;  
        number = number / 2; 
    }

    cout << "Binary: " << bin << endl;

    return 0;
}