#include <iostream>
using namespace std;

int main(){
    
    int num;
char space = ' ';
char star = '*';

    cout << "insert a positive integer: " << endl;
    cin>> num;

for (int i=0; i<= num; i++){

    for (int j=0; j<i; j++){
	        cout<<space;

    }


	for (int k=0; k<num-i;k++){

        cout << star;

    }
    cout << endl;
}



return 0;
}

/* 
    cin>>num;
    for(int i=0; i<=num; i++){
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        for(int k = 0;k<num-i;k++){
            cout<<star;
        }

        cout<<endl;
    }
 */
    //bottom right trianlge
/*     for(int i=0; i<=num; i++){
        for(int k = 0;k<num-i;k++){
            cout<<" ";
        }

        for(int j=0; j<i; j++){
            cout<<star;
        }
        cout<<endl;
    } */

//top left tringle
/*
    for(int i=num; i>0; i--){
        cout << " ";
        for(int j=0; j<i; j++){
            cout<<star;
        }
        star++;
        cout<<endl;
    }
*/

/* 

/bottome left triangle
    for(int i =1; i<=num;i++){
        for(int j=1; j<=i;j++){
            cout<<star;
        }
        star++;
        cout<<endl;
    }

 */
