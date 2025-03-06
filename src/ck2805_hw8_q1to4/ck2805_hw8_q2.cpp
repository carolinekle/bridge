#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize){

    if(arrSize==0){
        return 0;
    }else{
        return arr[arrSize-1]*arr[arrSize-1] + sumOfSquares(arr, arrSize-1);;
       

    }


}

bool isSorted(int arr[], int arrSize){
    if(arrSize==0||arrSize==1){
        return true;
    } else {
        if (arr[arrSize - 1] < arr[arrSize - 2]) {
            return false; 
        } else {
            return isSorted(arr, arrSize - 1);
        }
    }
}

int main(){
    int num;
    int temp;
    
    cout<< "section a"<<endl;
    cout<<"enter a positive integer for array size"<<endl;
    cin>> num;
    int arr[num];
    cout<<"enter a positive integer for array size"<<endl;
    
    for (int i=0; i<num; i++){

        cin>>temp;
        arr[i]=temp;
    }

    int sum = sumOfSquares(arr, num);

    cout<< "sum:"<<sum<< endl;

    cout<<"section b"<<endl;
    int num2;
    int temp2;
    

    cout<<"enter a positive integer for array size"<<endl;
    cin>> num2;
    int arr2[num2];
    cout<<"enter a positive integer for array size"<<endl;
    
    for (int i=0; i<num2; i++){

        cin>>temp2;
        arr2[i]=temp2;
    }

     if(isSorted(arr2, num2))
        cout<<"True!"<<endl;
    else    
        cout<<"False"<<endl;


    return 0;
}