#include <iostream>
using namespace std;

int jumpIt(int arr[], int index, int size){
    if(index==size-1){
        return arr[index];
    }else{
        if (index + 2 < size){
            if(arr[index+1]<arr[index+2]){
                return arr[index]+jumpIt(arr, index+1, size);
    
            }else{
                return arr[index]+ jumpIt(arr, index+2, size);
            }
        }
       
    }

}

int main(){

    int index=0;
    int size=6;
    int arr[6] = {0, 3, 80, 6, 57, 10};

    int cost = jumpIt(arr, index, size);

    cout<<cost<<endl;

    return 0;
}