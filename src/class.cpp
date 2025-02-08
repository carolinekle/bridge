#include <iostream>
using namespace std;

int main () {

    int num;
    char letter =97;
    char space = ' ';
    int outerspace = 0;
    int innerspace = 0;


    cout << "enter a random integer!" <<endl;
    cin >> num;
    int times = (num*2);
    outerspace=num-1;

    for(int i=1; i<times; i++){
        for(int j=0;j<outerspace; j++){
            cout<<space;
    
        }
        cout << letter;

        for(int j=1;j<innerspace; j++){
            cout<<space;
    
        }

        if(i!=1 && i!=((num *2)-1)){
            cout<<letter;
        }

         if(i<num){
        innerspace+=2;
        outerspace--;
            letter++;
        }else{
                      letter--;
            innerspace-=2;
            outerspace++;
        }
    cout <<endl;


    }  
   

    return 0;
}