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

void printOppositeTriangles(int n){

    if (n == 0) {
        return;
    }else {

        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout<<endl;

        printOppositeTriangles(n - 1);

        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout<<endl;

    }

}


void printRuler(int n){
    if(n==0){
        return;
    }else{
        printRuler(n-1);
  
        for (int i = 0; i < n; i++) {
            cout << "- ";
        }
        cout<<endl;

        printRuler(n-1);
    }

}


int main(){
    int num;

    cout<<"enter a positive integer"<<endl;
    cin>> num;
    cout<<"section a"<<endl;
    printTriangle(num); 

    cout<<"section b"<<endl;
    printOppositeTriangles(num);

    cout<<"section c"<<endl;
    printRuler(num);


    return 0;
}