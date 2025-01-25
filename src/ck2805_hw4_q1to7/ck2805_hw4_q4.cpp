#include <iostream>
#include <cmath>
using namespace std;


int main(){
    // section a
cout << "section a: "<<endl;
    int num, a;
    int product= 1;

    cout << "Enter the length of your sequence: " <<endl;

    cin >>num;
    cout << "please enter your sequence: " << endl;
    
    for(int i=1; i <=num; i++){
     
        cin >> a;
        product = product*a;

    }
    
    double power = 1/(double)num;

    double result = pow(product, power);

    cout  <<"The geometric mean is: " << result << endl;


// section b 

    cout << "section b: " <<endl;

    int integer;
    int j=0;
    int seqProd =1;
    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:" << endl;
    while (integer!=-1){
        cin >> integer;
        seqProd = seqProd*integer;
        ++j;
    }

    double powerB = 1/((double)j-1);
cout << "product: " << seqProd <<endl;
    double resultB = pow(seqProd, powerB);

    cout  <<"The geometric mean is: " << resultB << endl;


    return 0;
}