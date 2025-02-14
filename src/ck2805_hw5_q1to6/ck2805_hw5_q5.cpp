#include <iostream>
using namespace std;


void analyseDividors(int num, int& outCountDivs, int& outSumDivs){
    outCountDivs = 0;
    outSumDivs = 0;

    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            outSumDivs += i;
            outCountDivs++;
            if (i != 1 && i * i != num) { 
                outSumDivs += num / i;
                outCountDivs++;
            }
        }
    }
}

bool isPerfect(int num){
    int outCountDivs=0;
    int outSumDivs =0;

    analyseDividors(num, outCountDivs,outSumDivs);


     if (outSumDivs == num){ 
        return true;
        }
    else{
        return false;
    }
}

bool isGreater(int num){
    return num>=2;
}


int main(){

    int numA, numB, numC;
    int outCountDivs=0;
    int outSumDivs=0;

    cout<<"Section a: "<<endl;

    cout << "enter a postive integer:" << endl;
    cin>>numA;
    if(isGreater(numA)){
        analyseDividors(numA, outCountDivs, outSumDivs);
        cout<<"Sum:"<<outSumDivs<<endl;
        cout<<"Count:"<<outCountDivs<<endl;
    }else{
        cout<<"enter an integer great than 2"<<endl;
        return 1;
    }

    cout<<"section b: "<<endl;
    cout << "enter a postive integer:" << endl;
    cin>>numB;

    if(isGreater(numA)){
        if(isPerfect(numB)){
            cout<<numB<<" is a perfect number."<<endl;
        }else{
            cout<<numB<<" is not a perfect number."<<endl;
        }
    }else{
        cout<<"enter an integer great than 2"<<endl;
        return 1;
    }  

    cout<<"section C: "<<endl;
    
    cout << "enter a postive integer:" << endl;
    cin>>numC;
    if (!isGreater(numC)) {
        cout << "enter an integer greater than or equal to 2." << endl;
        return 1;
    }

    cout << "perfect numbers between 2 and " << numC << ": ";
    for (int i = 2; i <= numC; i++) {
        if (isPerfect(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "amicable pairs between 2 and " << numC << ": " << endl;
    for (int i = 2; i <= numC; i++) {
        int sumA, countA;
        analyseDividors(i, countA, sumA);
        if (sumA > i && sumA <= numC) {  
            int sumB, countB;
            analyseDividors(sumA, countB, sumB);
            if (sumB == i) {
                cout << i << " and " << sumA << endl;
            }
        }
    }





    return 0;

}