#include <iostream>
#include <vector>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int counter=0;
    int index=0;

    for(int i=0; i<=arrSize;i++){
        if(arr[i]>0){
            counter++;
        }
    }
    outPosArrSize= counter;
    int *NewArr;
    NewArr = new int[counter];

    for(int i=0; i<=arrSize;i++){
        if(arr[i]>0){
            NewArr[index]=arr[i];
            index++;
            
        }
    }


    cout<<"new"<<endl;
    for(int i=0; i<=counter;i++){
        cout<<NewArr[i]<<" ";
    }
     cout<<endl;
    
    return NewArr;
}


int main(){
    int arrSize;
    int outPosArrSize;
    cout<<"enter array Size:"<<endl;

    cin>>arrSize;
    int arr[arrSize];

    cout<<"enter digits in array"<<endl;

    for(int i=0; i<arrSize;i++){
        cin>>arr[i];
    }
    int* posArr=(getPosNums1(arr, arrSize, outPosArrSize));
    cout<<"pointer address "<<(getPosNums1(arr, arrSize, outPosArrSize));

    for(int i=0; i<=*posArr-1;i++){
        cout<<posArr[i];
    } 

    return 0; 
}