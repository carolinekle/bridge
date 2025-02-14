#include <iostream>
using namespace std;

double eApprox(int n){
    double e=1;
    double factorial =1;

    for (int i = 1; i <= n; i++) {
        factorial *= i;
        e += 1.0 / factorial; 
    }

    return e;
}

int main(){

    double n;
    cout.precision(30);

    cout<<"enter amount for e: "<<endl;
    cin>> n;

    for (int n = 1; n <= 15; n++) {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
        }
    return 0;

}