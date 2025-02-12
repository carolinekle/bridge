#include <iostream>
using namespace std;

int fibonacci(int num);

int main (){
    int num;

    cout<<"enter a postive integer: "<<endl;
    cin>>num;
    int fib =fibonacci(num);

    cout<<fib<<endl;

    return 0;
}

int fibonacci(int num){
    int fib=1;
    int fib2=0;

    for(int i=1; i<=num; i++){
        fib = fib2+fib;
        fib2=fib-fib2;

    } 

    return fib;
}