#include <iostream>
using namespace std;

void divisors(int num);

int main(){

    int num;
    int num2;

    cout << "enter a postive integer:" << endl;
    cin>>num;

    divisors(num);

    cout<<"section b: "<<endl;

    cout<< "enter a postive integer >= 2:" << endl;
    cin>>num2;

    if (num>=2){
        divisors(num2);
    }else{
        cout<<"I think you entered a number less than 2!"<< endl;
    }
    


    return 0;

}


void divisors(int num){
    int div;
    for (int i=1;i<num;i++){
        if(num%i==0){
            div=i;
            cout<< div << " ";
        };

    }
    cout<<endl;

}