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

int fibonacci(int n){
    int fib;
    int a=1;
    int b=1;
    int temp;

    if(n==1||n==2){
        fib=1;
        return fib;
    }

    for(int i=3; i<=n; i++){
        temp = a + b;
        a = b;
        b = temp;
        
    } 
    fib=b;

    return fib;
}