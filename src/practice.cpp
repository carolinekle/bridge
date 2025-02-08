#include <iostream>
using namespace std;


int main(){
    int num;
    char space = ' ';
    char hash = '#';
    char dollar = '$';

    cout << "enter a number "<<endl;

    cin>> num;
    int times= num/2;

//rows
    for(int i=0; i<num; i++){

        for(int j=0; j<num; j++){
       
        if(j==1 || j==num-1 || i==0 || i==num-1){
            cout<<hash; 
        }
        else if(i==j || i+j == num-1){
            cout << dollar;
        }

        else{
            cout<<space;
        }


    }

        cout<<endl;
    }
}