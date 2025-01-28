#include <iostream>
using namespace std;

int main(){

    int num;
    int counting;
    cout << "input a random integer \n";
    cin >> num;

    if (num%2==0){
        counting =num/2;

        for (int i = 1; i <counting; i++) {
            int even = i*2;
            cout << even <<endl;
        }
    }else{
      counting =((num+1)/2);

        for (int j = 0; j <counting; j++) {
            int odd = (j*2)+1;
            cout << odd <<endl;
        }
      
    }
  

    return 0;
}