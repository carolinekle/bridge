#include <iostream>
using namespace std;


int main(){
    int num;

    cout << "enter a number "<<endl;

    cin>> num;


    for(int i=0; i<=num; i++){
        
        if(i==1 || i==num){
            for(int j=0; j<=num; j++){
                cout <<"#";
            }
        }

        for(int k=0;k<=num;k++){
            cout<<"#";
            
        }
    }
}