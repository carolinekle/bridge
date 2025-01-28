#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;
    string roman = "";

    cout << "Enter decimal number: " << endl;
    cin >> num;

    while (num >= 1000) {
        roman += "M";
        num -= 1000;
    }

    if (num >= 500) {
        roman += "D";
        num -= 500;
    }

    while (num >= 100) {
        roman += "C";
        num -= 100;
    }


    if (num >= 50) {
        roman += "L";
        num -= 50;
    }

    while (num >= 10) {
        roman += "X";
        num -= 10;
    }

    if (num >= 5) {
        roman += "V";
        num -= 5;
    }
    
    while (num >= 1) {
        roman += "I";
        num -= 1;
    }

    cout << roman << endl;
    return 0;
}