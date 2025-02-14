#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol){

    for (int i = 1; i <= n; i++) {
        int spaces = m + (n - i);   
        for (int k = 0; k < spaces; k++) {
            cout << ' ';  
        }
        for (int j = 0; j < (2 * i - 1); j++) {  
            cout << symbol; 
        }
        cout << endl;
    }
}

void printPineTree(int n, char symbol){

    for (int l = 1; l <= n; l++) {  
        int width = 2 * l - 1;      
        
        for (int i = 1; i <= width; i += 2) {  
            int spaces = (n * 2 - 1 - i) / 2;
            
            for (int k = 0; k < spaces; k++) {  
                cout << " "; 
            }
            for (int j = 0; j < i; j++) {
                cout << symbol;
            }
            cout << endl;
        }
    }
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

    cout<<"Enter number of triangles and symbol you want for your pine tree: "<< endl;
    cin>> pineNum;
    cin>>pineSymbol;
 

    printPineTree(pineNum, pineSymbol);


    return 0; 
}

