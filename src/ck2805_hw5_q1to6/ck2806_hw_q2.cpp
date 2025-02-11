#include <iostream>
using namespace std;

//NOT DONE
//come back to a
void printShiftedTriangle(int n, int m, char symbol){
char space =' ';

for(int i=0; i<=n; i++){
    for(int k = 0;k<n-i;k++){
        cout<<space;
    }

    for(int j=0; j<i; j++){
        
        cout<<symbol;
    }
    cout<<endl;
}

}

void printPineTree(int n, char symbol){

/*  
char space =' ';

    for(int l=1;l<=n;l++){

        for(int i =1; i<=n;i++){


            for(int k=m;k<=n+m;k++ ){
                cout<<space;
            }
            for(int j=1; j<=i;j++){
                cout<<symbol;
            }
            cout<<endl;
        }

    }
 */

}

int main(){
    char symbol;
    int lines;
    int spaces;
    
    cout<<"Section a"<<endl;
    cout << "Enter the amount of lines, spaces and selected symbol in that order for your shifted triangle: "<<endl;
    cin>> lines;
    cin>> spaces;
    cin>>symbol;

    printShiftedTriangle(lines, spaces, symbol);

    cout<<"section b"<<endl;

    int pineNum;
    char pineSymbol;

    cout<<"Enter number of triabgles and symbol you want for your pine tree: "<< endl;
    cin>> pineNum;
    cin>>pineSymbol;
 

    printPineTree(pineNum, pineSymbol);



    return 0; 
}

