#include <iostream>
using namespace std;

int main () {

    int num;
    char letter =97;

    cout << "enter a random integer!" <<endl;
    cin >> num;
    int times = (num*2)-1;

    for(int i=0; i<num; i++){
        for(int j=num;j>0; j--){
            cout<<" ";
    
        }
        cout<<letter;
        letter++;
        cout<<endl;

    }  
    letter = 97+(num-2);

    for(int k=1;k<num;k++){
        for(int l=num; l>=0; l--){
            cout<<" ";
    
        }
        cout<<letter;
        letter--;
        cout<<endl;
    }

    return 0;
}