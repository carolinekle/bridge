#include <iostream>
#include <string>
using namespace std;

int main() {
    int number;
    string bin=" ";
    char one = '1';
    char zero = '0';


    cout << "Enter a whole number: ";
    cin >> number;
    int math = number;

    while (math > 0) {
        int remainder = math % 2; 
        if (remainder == 1){
            bin=one+bin;
        }else{
            bin=zero+bin;
        }

        math = math / 2; 
    }

    cout << "Binary representation of " << number <<" is " << bin << endl;

    return 0;
}