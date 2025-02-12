#include <iostream>
using namespace std;

double eApprox(int n){
    double e=1;
    for (int i=1; i<=n; i++){
        cout<<i<<endl;
        e=1/(e*i);
    }
    e=1+e;
    
    return e;
    
}

int main(){

    double num;

    cout<<"enter amount for e: "<<endl;
    cin>> num;

    double newNum = eApprox(num);
    cout<<newNum<<endl;

    return 0;

}