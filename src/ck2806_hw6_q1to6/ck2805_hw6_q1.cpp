#include <iostream>
using namespace std;

void getIndex(int small, int arr[], int arrSize){
    

     for (int j=0; j<arrSize;j++){
        if (arr[j]==small){
            cout<<j<<" ";
        }
    }
    cout<<endl;
}

int minInArray(int arr[], int arrSize){

    int small = arr[0];

    for (int i = 1; i < arrSize; i++) { 
        if (arr[i] < small) {
            small = arr[i];
        }
    
        
    }
    

    return small;
    
}

void minValueWithIndex(int array[], int size){
    int small = minInArray(array, size);
    cout<<"the smallest number in the array: "<<small;
    cout<<" and it is located in the following indeces: ";
    getIndex(small, array, size);
    
    
}

int main()
{
    int x, value;
    int index;
    cout<<"section a"<<endl;

    cout<<"enter the size of your array"<<endl;
    cin>> x;
    int arr[x];
    
    cout<<"enter the values you want for your array"<<endl;
    
    for(index =0; index<x;index++){
        cin>>value;
        arr[index]=value;
    }
    
    int small=minInArray(arr, x);

    cout<<"smallest number in array: "<<small<<endl;
    
    cout<<"section b"<<endl;
    
    int array[20];
    int num;
    
    cout<<"please enter 20 integers seperated by a space: "<<endl;

    for(int i=0;i<20; i++){

        cin>>array[i];
    }

    minValueWithIndex(array, 20);
    
    
    
    return 0;
}