#include <iostream>
using namespace std;

void printTriangle(int n){
    if (n == 0) {
        return;
    }

    printTriangle(n - 1);

    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}
void printRuler(int n){

}

void printOppositeTriangles(int n){

}
int main(){
    int num;

    cout<<"enter a positive integer"<<endl;
    cin>> num;

    printTriangle(num);

    return 0;
}