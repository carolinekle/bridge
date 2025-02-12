#include <iostream>
using namespace std;

//NOT DONE

void analyseDividiors(int num, int& outCountDivs, int& outSumDivs){
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

    analyseDividiors(num, outCountDivs,outSumDivs);


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
        analyseDividiors(numA, outCountDivs, outSumDivs);
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
    if(isGreater(numC)){
        int outSumDivs, outCountDivs;
        analyseDividiors(numC, outCountDivs, outSumDivs);
        

 /*        for (int i = 2; i <= numC; i++) {
            if (isPerfect(i)) {
                cout << i << " ";
            }
        }
        for (int i=2;i<=numC;i++){
            if (isPerfect(i)){
                int sumA=i;
            }
        } */
        cout << endl;

    }else{
        cout<<"enter an integer great than 2"<<endl;
        return 1;
    }  
    




    return 0;

}