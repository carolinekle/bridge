#include <iostream>
using namespace std;

int sumArr(int arr[], int size){
int i=0;

    if(size==1){
        return arr[0];
    }
    else{
        int m = sumArr(arr,size-1);
        return (arr[size]-1)+m;
    }


        
}
int main() {
    int arr[5]={1,5,3,8,9};
    int size =5;
   int result = sumArr(arr, size);
   cout<<result;

    return 0;
}