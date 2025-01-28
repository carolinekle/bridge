#include <iostream>
using namespace std;

int main (){
    int number;
    cout <<"Please enter a postive integer: "<<endl;

    cin>> number;
    int max;


        for(int i =1; i<=number; i++){

                for(int k =1; k<=number; k++){
                    max =i *k;
                    cout << max << "\t";
                }

        cout<<"\n";
            
        }


        


    return 0; 
}