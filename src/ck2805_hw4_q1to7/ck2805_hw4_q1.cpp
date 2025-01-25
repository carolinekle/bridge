#include <iostream>
using namespace std;

int main () {
    int num;

    cout << "Please enter an integer on the next line: "<< endl;

    cin >> num;

    cout << "section a: " <<endl;

     for (int i = 1; i <= num; i++) {
        int result = i*2;
        cout << result <<endl;

    } 

    cout << "section b: " <<endl;
    int j=1;
    while(j <=num){
        int result = j*2;
        j++;
        cout << result <<endl;
    }

}
